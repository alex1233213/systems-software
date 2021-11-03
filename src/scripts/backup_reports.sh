date=$(date +'%d-%m-%Y')


tar -czf /home/alex/Desktop/assignment/backups/dashboard-backup-${date}.tar.gz -C /home/alex/Desktop/assignment/ dashboard_system  --transform "s|dashboard_system|dashboard-system-backup-${date}|" 
