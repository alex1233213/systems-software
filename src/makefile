CC = gcc
objects = daemon.o collect_reports.o backup_dashboard.o 
headers = daemon_tasks.h
flags = -Wall -g

daemon: $(objects) 
	$(CC) -o daemon $(objects)

daemon.o: daemon.c $(headers)
	$(CC) -c daemon.c

collect_reports.o: collect_reports.c
	$(CC) -c collect_reports.c 

backup_dashboard.o: backup_dashboard.c
	$(CC) -c backup_dashboard.c 
 
clean:
	rm $(objects) daemon
