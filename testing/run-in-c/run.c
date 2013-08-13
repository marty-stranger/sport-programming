#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char *prog = argv[1];

	pid_t pid = vfork();
	if (pid == 0) {
		execl(prog, prog, NULL);
		perror("exec");
	} if (pid == -1)
		perror("vfork");
    
	long page_size = sysconf(_SC_PAGESIZE), clock_tick = sysconf(_SC_CLK_TCK);
  
	putc('\r', stderr);
	int code = 0, yes = 1;
	unsigned long max_mem = 0, time;
  
	while (yes) {
		struct timespec req;
		req.tv_sec = 0;
		req.tv_nsec = 1000000; /* 0.001 sec */
		if (nanosleep(&req, NULL) == -1)
			perror("nanosleep");
      
		char filename[100];
		sprintf(filename, "/proc/%i/stat", pid);
		FILE *f = fopen(filename, "r");
		if (f == NULL)
			perror("fopen");

		char state; 
		unsigned long utime, stime;
		fscanf(f, "%*d%*s%*c%c%*d%*d%*d%*d%*d%*lu%*lu%*lu%*lu%*lu%lu%lu", &state, &utime, &stime);
		fclose(f);

		if (state == 'Z')
			yes = 0;

		sprintf(filename, "/proc/%i/statm", pid);
		f = fopen(filename, "r");
		if (f == NULL)
			perror("fopen");

		unsigned long data;
		fscanf(f, "%*ld%*ld%*ld%*ld%*ld%ld", &data);
		fclose(f);

		unsigned long mem = data * page_size;

		if (mem > max_mem)
			max_mem = mem;

		time = utime + stime; /* 100 jiffies = 1 second ? */

		fprintf(stderr, "%dcs %dkb\r", time, (int)(mem / 1024));
		if (fflush(stdout) == -1)
			perror("fflush");
	}

	int status;
	waitpid(pid, &status, 0);

	if (WIFEXITED(status)) {
		int exit_status = WEXITSTATUS(status);
		if (exit_status != 0) {
			fprintf(stderr, "exit status = %d", exit_status);
			return 0;
		}
	} else if (WIFSIGNALED(status)) {
		int term_sig = WTERMSIG(status);
		fprintf(stderr, "term sig = %d", term_sig);
		return 0;
	} else {
		fprintf(stderr, "unhandle waitpid status\n");
		return 0;
	}

	fprintf(stderr, "%dcs %dkb\n", time, (int)(max_mem / 1024));
	return 0;
}
