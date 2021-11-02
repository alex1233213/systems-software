CC = gcc
objects = daemon.o collect_reports.o
headers = daemon_tasks.h


daemon: $(objects) 
	$(CC) -o daemon $(objects)

daemon.o: daemon.c $(headers)
	$(CC) -c daemon.c

collect_reports.o: collect_reports.c
	$(CC) -c collect_reports.c

clean:
	rm $(objects) daemon
