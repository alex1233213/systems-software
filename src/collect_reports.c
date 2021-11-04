#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syslog.h>

void collect_reports(void) {

	 pid_t  pid;

    	 pid = fork();
    	 if (pid == 0) // child
    	 {
	 	 char *args[] = {"/bin/sh", "/home/alex/Desktop/assignment/src/scripts/collect_reports.sh", NULL};
		execvp(args[0], args);	

  	  }
	     else // parent
	     {
		       int status=0;
		       wait(&status);
		       printf ("Child process is returned with: %d.\n",status);
	     }
}

