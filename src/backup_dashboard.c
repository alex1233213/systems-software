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
		int day, month, year;

		time_t now;
		time(&now);

		struct tm *local = localtime(&now);
		day = local->tm_mday;            // get day of month (1 to 31)
		month = local->tm_mon + 1;      // get month of year (0 to 11)
		year = local->tm_year + 1900;   // get year since 1900

		char archive_path[300];
		char *backups_dir = "/home/alex/Desktop/assignment/backups/";

		char *assignment_dir = "/home/alex/Desktop/assignment/";
		char *target_compress_dir = "dashboard/";
		char transform_arg[300];
		snprintf(transform_arg, 300, "%s%d%c%d%c%d%s", "s|dashboard_system|dashboard-system-backup-", day, '-', month, '-', year, "|");

		snprintf(archive_path, 300, "%s%s%d%c%d%c%d%s", backups_dir, "dashboard-backup-", day, '-',  month, '-',  year, ".tar.gz");


		char *args[] = {
			"/bin/tar",
			"-czvf",
			archive_path,
			"-C",
			assignment_dir,
			"dashboard_system",
			"--transform",
			transform_arg,
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
