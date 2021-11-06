// Orphan Example
// The child process is adopted by init process, when parent process dies.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>
#include "daemon_tasks.h"



 
int main()
{
    time_t now;
    struct tm backup_time;
    double seconds;
    time(&now);  /* get current time; same as: now = time(NULL)  */
    backup_time = *localtime(&now);
    backup_time.tm_hour = 21; 
    backup_time.tm_min = 23; 
    backup_time.tm_sec = 0;

    // Implementation for Singleton Pattern if desired (Only one instance running)

    // Create a child process      
    int pid = fork();
 
    if (pid > 0) {
        // if PID > 0 :: this is the parent
        // this process performs printf and finishes
        sleep(10);  // uncomment to wait 10 seconds before process ends
        exit(EXIT_SUCCESS);
    } else if (pid == 0) {
       // Step 1: Create the orphan process
       
       // Step 2: Elevate the orphan process to session leader, to loose controlling TTY
       // This command runs the process in a new session
       if (setsid() < 0) { exit(EXIT_FAILURE); }

       // We could fork here again , just to guarantee that the process is not a session leader
       int pid = fork();
       if (pid > 0) {
          exit(EXIT_SUCCESS);
       } else {
       
          // Step 3: call umask() to set the file mode creation mask to 0
          umask(0);

          // Step 4: Change the current working dir to root.
          // This will eliminate any issues of running on a mounted drive, 
          // that potentially could be removed etc..
          if (chdir("/") < 0 ) { exit(EXIT_FAILURE); }

          // Step 5: Close all open file descriptors
          /* Close all open file descriptors */
          int x;
          for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
          {
             close (x);
          } 

          // Signal Handler goes here

          // Log file goes here
	  openlog("MAN-DAEMON-LOGGER", LOG_PID | LOG_CONS, LOG_DAEMON);
          // Orphan Logic goes here!! 
          // Keep process running with infinite loop
          // When the parent finishes after 10 seconds, 
          // the getppid() will return 1 as the parent (init process)
          
	  struct tm check_uploads_time;
	  time(&now);  /* get current time; same as: now = time(NULL)  */
	  check_uploads_time = *localtime(&now);
	  check_uploads_time.tm_hour = 11; 
	  check_uploads_time.tm_min = 7; 
	  check_uploads_time.tm_sec = 0;
	
  	  //while(1) {
	 // 	sleep(1);
	 // 	time(&now);
	 // 	seconds = difftime(now,mktime(&check_uploads_time));
	//	if(seconds == 0) {
//			syslog(LOG_INFO, "CHECKING FOR XML FILES UPLOADS");
//			check_file_uploads();
//		}		
//	  }

	  

	  //lock_directories();

	 //collect_reports();	  
	 //backup_dashboard();
	 generate_reports();
	 syslog(LOG_ERR, "TEST");
	  //sleep(15);
	 // unlock_directories();
 
				   
	}
	closelog();
       return 0;
    }
}
