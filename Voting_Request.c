#include "Voting_Request.h"
void Voting_Request()
{
	char n;
	int invalid_option = 0;
	void (*fptr[2])();
	fptr[0] = CreateVotingRequest;
	fptr[1] = DeleteVotingRequest;
	while(1)
	{
		if(invalid_option < 3)
		{
			printf("Enter your choice :\n 1.Create Voting Request\n 2.Delete Voting Request\n *. Main menu\n");
	        scanf(" %c",&n);
	        switch(n)
	        {
		    case '1' : fptr[0]();
		               break;
		    case '2' : fptr[1]();
		               break;
		   // case '*' : main();
		     //          break;
		    default  : invalid_option++;
			       if(invalid_option==3)
			       {
				       printf("you chose 3 times wrong option that's why is go to main mainu\n");
				       main();
			       }
			           printf("Invalid choice.\n");
		               break;
	        }	
		}
	    else
	    {
	    	printf("\nError: User entered Invalid Option for three times\n\n");
	//		main();
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
			if(a[i] >= '0' && a[i] <= '9' && a[i+1]>='a' && a[i+1] <= 'z')
			{
				printf("Wrong format\n");
				goto scan;
			}
			if(a[i] >= '0' && a[i] <= '9' && a[i+1]>='A' && a[i+1] <= 'Z')
			{
				printf("Wrong format\n");
				goto scan;
			}
			if(a[i] >= '!' && a[i] <= '/' || a[i] <= '@' || a[i] >= '[' && a[i] <= '`' || a[i] >= '{' && a[i] <= '~')
			{
				printf("Wrong format\n");
				goto scan;
			}
		}
		strcpy(c,a);
		for(i=0;a[i];i++) // loop for adding '_' in place of space
		{
			if(a[i] == ' ')
			   a[i] = '_';
		}
		strcat(a,b);
		//printf("%s\n",a);
		FILE*fp;
		fp = fopen(a,"w");
		int n;
		printf("Enter the fields for %s Request form\n", c);
		do
		{
			char read[MAX];
			scanf(" %[^\n]", read);
            fprintf(fp,"%s\t", read);
            i++;
            printf("Do you want to add another field (y/n)\n");
            scanf(" %c",&field);
		}while(field == 'y' || field == 'Y');
	fclose(fp);
}
void DeleteVotingRequest()
{
	char delete[SIZE];
	char d[MAX];
	char b[MAX] = "_request.xls";
	char sure;
	printf("List of xls files present :\n");
	if(system("ls *.xls")) // Listing the files with .xls extension
	{
		printf("Request form is not created\n");
		return;
	}
	printf("Enter the file name to delete : \n");
	scanf(" %s",d); // To scan file name
	char *p = strstr(d,b); // To check "_Request.xls" file is present or not
	if(p == NULL)
		strcat(d,b); // "_request.xls"
	snprintf(delete,sizeof(delete), "rm %s", d); // In delete it will add with  "rm filename.xls"
	printf("Are you sure (y/n)\n");
	scanf(" %c",&sure);
	if(sure == 'Y' || sure == 'y')
	{
		system(delete); // Deleting particular file
		printf("%s file is deleted\n",d); // Printing deleted file
	}
	else
	{
		printf("%s is not deleted\n", d); 
	}
}

