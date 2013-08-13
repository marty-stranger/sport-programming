#include <stdio.h>

int main() {
	printf("D=\'\"\';S=\"\'\";A=\"?\'D=\'+S+D+S+\';\';?\'S=\'+D+S+D+\';\';?\'A=\'+D+A+D+\';\';?A\";?\'D=\'+S+D+S+\';\';?\'S=\'+D+S+D+\';\';?\'A=\'+D+A+D+\';\';?A");
	return 0;
}

