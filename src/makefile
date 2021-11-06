CC = gcc
objects = daemon.o collect_reports.o backup_dashboard.o lock_directories.o unlock_directories.o generate_reports.o check_file_uploads.o
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


lock_directories.o: lock_directories.c
	$(CC) -c lock_directories.c	 


unlock_directories.o: unlock_directories.c
	$(CC) -c unlock_directories.c

generate_reports.o: generate_reports.c
	$(CC) -c generate_reports.c


check_file_uploads.o: check_file_uploads.c
	$(CC) -c check_file_uploads.c


clean:
	rm $(objects) daemon
