#include <syslog.h>
#include <stdio.h>
#include <time.h>


//this function takes a date struct and modifies its day to tommorrow's day.
//when time is due for transfer / backup / etc. the daemon will then start counting 
//to tommorows day
void update_timer(struct tm *due_date) {
	syslog(LOG_INFO, "CURRENT DAY IS %d; CHANGING TIMER TO TOMMOROW'S DAY", due_date -> tm_mday);
	due_date -> tm_mday += 1;
  	mktime(due_date);	
	syslog(LOG_INFO, "TIMER UPDATED, DUE NEXT DAY, %d", due_date -> tm_mday);
}
