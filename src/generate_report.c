
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>

void generate_report(void) {
	pid_t pid;
	
	pid = fork();

	if(pid == -1) {
		syslog(LOG_ERR, "ERROR OCCURRED DURING FORK");
	} else if(pid == 0) {
		
		char *args[] = {"/bin/sudo", "./home/alex/Desktop/assignment/src/scripts/generate_reports.sh", NULL};

		execvp(args[0], args);

	} else {
		wait(NULL);
	}

}
