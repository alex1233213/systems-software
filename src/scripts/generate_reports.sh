#!/bin/bash

audit_file="audit-report-$(date +'%d-%m-%Y').txt"

#generate audit log 
sudo ausearch  -ts today -k xml_upload_watch | sudo aureport -f -i  > /home/alex/Desktop/assignment/manufacturing_company_reports/$audit_file

