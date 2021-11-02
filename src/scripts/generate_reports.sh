#!/bin/bash

REPORT_DATE=$(date +'%d-%m-%Y')

#generate audit log 
sudo ausearch -k xml_upload_watch | sudo  aureport -f -i > /home/alex/Desktop/assignment/manufacturing_company_reports/audit_report_${REPORT_DATE}.txt

echo 'SCRIPT has been run' > /home/alex/Desktop/assignment/test_output.txt
