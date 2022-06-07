#include "main.h"
#include "Voting_Request.h"
#include "registration.h"
void Voting_Request()
{
	int n;
	int invalid_option = 0;
	void (*fptr[2])();
	fptr[0] = CreateVotingRequest;
	fptr[1] = DeleteVotingRequest;
	while(1)
	{
		if(invalid_option < 3)
		{
			printf("Enter your choice :\n 1.Create Voting Request\n 2.Delete Voting Request\n 3.Main menu\n");
	        scanf(" %d",&n);
	        switch(n)
	        {
		    case 1 : fptr[0]();
		               break;
		    case 2 : fptr[1]();
		               break;
		    case 3 : main();
		               break;
		    default : invalid_option++;
			           printf("Invalid choice.\n");
		               break;
	        }	
		}
	    else
	    {
	    	printf("\nError: User entered Invalid Option for three times\n\n");
			main();
	    }
    }
}
void CreateVotingRequest()
{
	char a[MAX]; //scaning file name
	char b[MAX] = "_request.xls";//adding this with file for perfect format
	char c[MAX];//copy of scanned file name
	char field;//getting fields from user
	int i = 0;
	scan:
		do
		{
			printf("Enter the excel file name : \n");
			scanf(" %[^\n]",a);
		}while(a[0] == '_' || a[0] >= '0' && a[0] <= '9');
	        for(i=0; a[i]; i++) // This for loop is to check the criteria for creating filename
	        {
			if(a[i] >= '0' && a[i] <= '9' && a[i+1] >= 'a' && a[i+1] <= 'z')
			{
				printf("Wrong format\n");
				goto scan;
			}
			if(a[i] >= '0' && a[i] <= '9' && a[i+1] >= 'A' && a[i+1] <= 'Z')
			{
				printf("Wrong format\n");
				goto scan;
			}
			if(a[i] >= '!' && a[i] <= '/' || a[i] >= ':' && a[i] <= '@' || a[i] >= '[' && a[i] <= '`' || a[i] >= '{' && a[i] <= '~')
			{
			printf("Wrong format\n");
			goto scan;
			}
		}
		strcpy(c,a);
		for(i=0; a[i]; i++)
		{
		if(a[i] == ' ')
			a[i] = '_';
		}//This is for adding '_' in the place of space
        	strcat(a,b);
        	printf("%s\n",a);
        	FILE*fp;
        	fp=fopen(a,"w");
        	char n;
		char p[30]="Name";
		printf("Enter the fields for %s training form\n",c);
		printf("Do you want to add Name in fields(y/n)\n");
		scanf(" %c",&n);
		if(n=='y'||n=='Y')
		{
			fprintf(fp,"%s\t",p);
		}
		printf("Do you want to add Emp_id in fields(y/n)\n");
		scanf(" %c",&n);
		if(n=='y'||n=='Y')
		{
		fprintf(fp,"%s\t","Emp_ID");
		}
		printf("Do you want to add Email_ID in fields(y/n)\n");
        	scanf(" %c",&n);
        	if(n=='y')
        	{
                	fprintf(fp,"%s\t","Email_ID");
        	}
		printf("Do you want to add Mobile_No in fields(y/n)\n");
        	scanf(" %c",&n);
        	if(n=='y')
        	{
                	fprintf(fp,"%s\t","Mobile_No");
        	}
		printf("Do you want add another field(y/n)\n");
		scanf(" %c",&n);
		if(n=='y')
		{	
        		do//this will scan the fields for the .xls file 
        		{
                		char read[MAX];
                		scanf(" %[^\n]",read);
                		fprintf(fp,"%s\t",read);
                		i++;
				printf("Do you want add another field(y/n)\n");
                		scanf(" %c",&field);
        		}while(field=='y'||field=='Y');
		}
		fclose(fp);
		printf("%s file is created\n\n",a);
}
void DeleteVotingRequest()
{
        delete();
    /*	char delete[SIZE];
	char d[MAX]; // scaning the file name for deletion
	char b[MAX] = "_request.xls";
	char sure;
	int i;
	printf("List of xls files present :\n");
	if(system("ls *request.xls")) // Listing the files with .xls extension
	{
		printf("Request form is not created\n");
		return;
	}
	printf("Enter the file name to delete : \n");
	scanf(" %[^\n]",d); // To scan file name
	for(i=0; d[i]; i++) // To add '_' in place of space
	{
		if(d[i] == ' ')
			d[i] = '_';
	}
	
	char *p = strstr(d,b); // To check "_Request.xls" file is present or not. Otherwise it will add to strcat
	if(p == NULL)
	   strcat(d,b); // "_request.xls"
	snprintf(delete,sizeof(delete), "rm %s", d); // In delete it will add with  "rm filename.xls"
	if(!access(d,F_OK)) //access is for checking the file is present or not
	{
	printf("Are you sure (y/n)\n");
	scanf(" %c",&sure);
	if(sure == 'Y' || sure == 'y')
	{
		system(delete); // Deleting particular file
		printf("%s file is deleted\n\n",d); // Printing deleted file
	}
	else
	{
		printf("%s is not deleted\n\n", d); 
	}
	}
	else
	{
		printf("%s  File does not created\n\n", d);
	}*/
}

