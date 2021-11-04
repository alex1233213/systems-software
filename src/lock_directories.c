
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>

void lock_directories() {
	pid_t pid;

	pid = fork();

	if(pid == -1) { 
		syslog(LOG_ERR, "ERROR OCCURRED DURING FORK");
	} else if(pid == 0) { 
		char *upload_dir = "/home/alex/Desktop/assignment/managers_xml_upload";
		char *dashboard_dir = "/home/alex/Desktop/assignment/dashboard_system";
		
		char *args[] = {"/bin/chmod", "000", upload_dir, dashboard_dir, NULL};

		execvp(args[0], args);
	} else {
		wait(NULL);
	}
}
