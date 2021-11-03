#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/wait.h>

void backup_dashboard(void) {
	pid_t  pid;

	pid = fork();
	if (pid == 0) // child
	{
		char *args[] = {
			"/bin/sh",
			"/home/alex/Desktop/assignment/src/scripts/backup_reports.sh",		
			NULL
		};

		execvp(args[0], args);
		
	}
	else // parent
	{
		int status=0;
		wait(&status);
		printf ("Child process is returned with: %d.\n",status);
	}

}
