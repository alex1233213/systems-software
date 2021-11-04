#!/bin/bash

audit_file="audit-report-$(date +'%d-%m-%Y').txt"

#generate audit log 
sudo ausearch  -ts today -f /home/alex/Desktop/assignment/managers_xml_upload | sudo aureport -f -i  > /home/alex/Desktop/assignment/manufacturing_company_reports/$audit_file

