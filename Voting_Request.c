#include "main.h"
#include "Voting_Request.h"
void Voting_Request(int n)
{
	int invalid_option = 4;
	void (*fptr[2])();
	fptr[0] = CreateVotingRequest;
	fptr[1] = DeleteVotingRequest;
	while(1)
	{
		__fpurge(stdin);
		printf("Enter your choice :\n 1.Create Voting Request\n 2.Delete Voting Request\n 3.Main Menu\n");
	        scanf(" %d",&n);
	        if(n >=0 && n <= 9)
	        { 
	        	switch(n)
	        	{
		    		case 1 : fptr[0]();
		               	 break;
		    		case 2 : fptr[1]();
		               	 break;
		    		case 3 : main();
		                        break;
		    		default :--invalid_option;
			       	if( invalid_option < 1)
			       	{
			       		printf("\nError: User entered Invalid Option for three times\n\n");
			       		main();
			       	}
			       	else
			       	{
			       		printf("You have entered invalid option... You have only %d chance\n\n",invalid_option);
			       		break;
			       	}	 
	        	}	
		}
	        else
	        {
	        	--invalid_option;
	        	if( invalid_option < 1)
			{
				printf("\nError: User entered Invalid Option for three times\n\n");
			        main();
			}
			else
				printf("You have entered invalid option... You have only %d chance\n\n",invalid_option);
			        break;
				
	        }
}
}
/* Funtion to input the voting request name and based on the voting request name, voting request form will be created with the fields mentioned by the user */
void CreateVotingRequest()
{
	char a[MAX]; //scaning file name
	char b[MAX] = "_request.xls";//adding this with file for perfect format
	char c[MAX];//copy of scanned file name
	char field;//getting fields from user
	int i = 0;
	char ad;
	scan:
		printf("Enter the excel file name : \n");
		scanf(" %[^\n]",a);
		for(i=0; a[i]; i++) // This for loop is to check the criteria for creating filename
		{
			if(i > 0 && a[i] == '_')
			{
				continue;
			}
			if(a[0] == '_' || a[0] >= '0' && a[0] <= '9')
			{
				printf("Wrong format...\nPlease input valid excel file name :\n");
				goto scan;
			}
			if(a[i] >= '0' && a[i] <= '9' && a[i+1] >= 'a' && a[i+1] <= 'z')
			{
				printf("Wrong format...\nPlease input valid excel file name :\n");
				goto scan;
			}
			if(a[i] >= '0' && a[i] <= '9' && a[i+1] >= 'A' && a[i+1] <= 'Z')
			{
				printf("Wrong format...\nPlease input valid excel file name :\n");
				goto scan;
			}
			if(a[i] >= '!' && a[i] <= '/' || a[i] >= ':' && a[i] <= '@' || a[i] >= '[' && a[i] <= '`' || a[i] >= '{' && a[i] <= '~')
			{
				printf("Wrong format...\nPlease input valid excel file name :\n");
				goto scan;
			}
		}
		strcpy(c,a);
		for(i=0; a[i]; i++) //Loop for adding '_' in the place of space
		{
		if(a[i] == ' ')
			a[i] = '_';
		}
        	char *t=strstr(a,b);//cheaking string "_request.xls" is present or not.If it present it'll do nothing otherwise strcat will add
        	if(t == NULL)
                	strcat(a,b);//"_request.xls"

		if(!access(a,F_OK))//access is for checking the file is present or not
        	{
                	printf("%s file is already present\n",a);
			printf("Are you sure to create a new file with same name(y/n)\n");
			scanf(" %c",&ad);
			if(ad=='y'||ad=='Y')
			{
				printf("%s file is created\n",a);
			}
			else
			{
				goto scan;
			}
        	}
        	FILE*fp;
        	fp=fopen(a,"w");
        	char n;
		char p[30]="Name";
		printf("Enter the fields for %s request form\n",c);
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
        		do//This will scan the fields for the .xls file 
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

/* Funtion to display available voting request forms and user is prompted to choose the form to be deleted from the given list.*/
void DeleteVotingRequest()
{
    	char delete[SIZE];
	char d[MAX]; // Scaning the file name for deletion
	char f[MAX] = "_request.xls";
	char sure;
	int i;
	printf("List of xls files present :\n\n");
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
	
	char *p = strstr(d,f); // To check "_Request.xls" file is present or not. Otherwise it will add to strcat
	if(p == NULL)
	   strcat(d,f); // "_request.xls"
	snprintf(delete,sizeof(delete), "rm %s", d); // In delete it will add with  "rm filename.xls"
	if(!access(d,F_OK)) //access is for checking the file is present or not
	{
	printf("\nAre you sure, Do you want to delete the file (y/n) :\n");
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
		printf("%s  file is not created\n\n", d);
	}
}

