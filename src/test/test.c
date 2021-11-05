#include <unistd.h>
#include <stdio.h>

int main() {
        char *manufacturing_xml = "/home/alex/Desktop/assignment/managers_xml_upload/manufacturing_report.xml";

        char *warehouse_xml = "/home/alex/Desktop/assignment/managers_xml_upload/warehouse_report.xml";

        char *sales_xml = "/home/alex/Desktop/assignment/managers_xml_upload/sales_report.xml";

         char *distribution_xml = "/home/alex/Desktop/assignment/managers_xml_upload/distribution_report.xml";


        char *files[] = { manufacturing_xml, warehouse_xml, sales_xml, distribution_xml};


        for(int i = 0; i < 4; ++i) {
		printf("Checking for file %s" , files[i]);
                int result = access (files[i], F_OK);

                if(result == -1) {
               		printf("%s isnt a file ", files[i]); 
			      printf("\n\n"); 
		} else { 
			printf("\t result %d\n\n", result);
		}

        }
}

