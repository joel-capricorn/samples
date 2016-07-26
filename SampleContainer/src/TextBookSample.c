#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int ReadLine(char *line, size_t len)
{
	char *p;
	size_t i;

	if(fgets(line, len, stdin) == NULL) {
		// printf("Unable to ReadLine(): %s\n", strerror(errno));
		return 0;
	}

	p = line;
	while(*p) {
		if(*p == '\r' || *p == '\n') {
			*p = 0;
			break;
		}
		p++;
	}

	return line[0] != 0;
}

int main(int argc, char **argv, char **envp)
{
	char ShellCode[384];
	int (*fp)(void);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	if(ReadLine(ShellCode, sizeof(ShellCode)-1) == 0) exit(EXIT_FAILURE);
	fp = (intptr_t *)ShellCode;
	fp();
}
