#include <unistd.h>
#include <syslog.h>
#include "daemon_tasks.h"
#include <signal.h>


void sig_handler(int sigNum)
{
	if (sigNum == SIGINT) {
		syslog(LOG_INFO, "RECEIVED SIGNAL INTERRUPT, INITIATING BACKUP AND TRANSFER");
		lock_directories();
		collect_reports();
		backup_dashboard();
		unlock_directories();
	}
}
