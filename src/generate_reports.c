
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>

void generate_reports(void) {
	pid_t pid;
	
	pid = fork();

	if(pid == -1) {
		syslog(LOG_ERR, "ERROR OCCURRED DURING FORK");
	} else if(pid == 0) {
		syslog(LOG_INFO, "GENERATING REPORTS");	
		char *args[] = {"/bin/sudo", "./home/alex/Desktop/assignment/src/scripts/generate_reports.sh", NULL};

		execvp(args[0], args);
		
	} else {
		
		int status;

		if(wait(&status) == -1) {
			syslog(LOG_ERR, "generate_reports.c: wait() failed");
		}


		if( (WIFEXITED(status)) ) {

			if( WEXITSTATUS(status) != 0 ) {
				syslog(LOG_ERR, "ERROR GENERATING REPORTS, STATUS %d", WEXITSTATUS(status));
			} else {
				syslog(LOG_INFO, "SUCCESSFULLY GENERATED REPORTS");
			}

		}

	}

}
