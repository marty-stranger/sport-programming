#include "ruby.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

extern void f();

VALUE method_run(VALUE self, VALUE prog_v, VALUE time_limit_v, VALUE memory_limit_v) {
  char *prog;
  int time_limit, memory_limit;
  pid_t pid;
  long page_size, clock_tick;
  int code, time, yes, status, exit_value;
  char filename[100];
  struct timespec req;
  FILE *f;
  char state;
  unsigned long utime, stime, data, mem, max_mem;
  
  prog = StringValuePtr(prog_v);
  time_limit = FIX2INT(time_limit_v);
  memory_limit = FIX2INT(memory_limit_v);
  
  pid = vfork();
  if (pid == 0) {
    execl(prog, prog, NULL);
    perror("exec");
  } if (pid == -1)
    perror("vfork");
    
  page_size = sysconf(_SC_PAGESIZE);
  clock_tick = sysconf(_SC_CLK_TCK); // = 100
  
  putchar('\r');
  code = 0;
  max_mem = 0;
  yes = 1;
  
  while (yes) {
    req.tv_sec = 0;
    req.tv_nsec = 10000000; /* 0.01 sec */
    if (nanosleep(&req, NULL) == -1)
      perror("nanosleep");
      
    sprintf(filename, "/proc/%i/stat", pid);
    f = fopen(filename, "r");
    if (f == NULL)
      perror("fopen");
    fscanf(f, "%*d%*s%*c%c%*d%*d%*d%*d%*d%*lu%*lu%*lu%*lu%*lu%lu%lu", &state, &utime, &stime);
    fclose(f);
    
    if (state == 'Z')
      yes = 0;

    sprintf(filename, "/proc/%i/statm", pid);
    f = fopen(filename, "r");
    if (f == NULL)
      perror("fopen");
    fscanf(f, "%*ld%*ld%*ld%*ld%*ld%ld", &data);
    fclose(f);

    time = utime + stime; /* 100 jiffies = 1 second ? */
    mem = data * page_size;

    if (mem > max_mem)
      max_mem = mem;

    if (time > time_limit) {
      if (kill(pid, SIGKILL) == -1)
        perror("kill");
      code = 2;
      yes = 0;
    }

    if (mem > memory_limit) {
      if (kill(pid, SIGKILL) == -1)
        perror("kill");
      code = 3;
      yes = 0;
    }
    
    printf("%dcs %dkb\r", time, (int)(mem / 1024));
    if (fflush(stdout) == -1)
      perror("fflush");
  }
      
  waitpid(pid, &status, 0);
    
  if (code == 0)
    if (WIFEXITED(status)) {
      exit_value = WEXITSTATUS(status);
      if (exit_value != 0)
        code = 1;
    } else if (WIFSIGNALED(status)) {
      exit_value = WTERMSIG(status);
      code = 1;
    } else
      exit_value = 0;
  else
    exit_value = 0;
  
  VALUE ary = rb_ary_new();
  rb_ary_push(ary, INT2FIX(code));
  rb_ary_push(ary, INT2FIX(exit_value));
  rb_ary_push(ary, INT2FIX(time));
  rb_ary_push(ary, INT2FIX(max_mem));

  return ary;
}

void Init_run() {
  f();

  VALUE run_module = rb_define_module("Run");
  rb_define_method(run_module, "run", method_run, 3);
}
