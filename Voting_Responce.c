#include"Voting_Responce.h"
enum day{yes,no};
#define M 50
#define N 1000
#define K 20
char s[M],s1[M],buf1[M],buf[N];
FILE *f;
void details();
void check();
pthread_mutex_t lock;
int print(char *p)
{
	char s1[K]="Name",s2[K]="EMP_ID",s3[K]="Email_ID",s4[K]="Mobile_No",s5[K]="0210";//hardcoded names for some fileds
	int i=0;//for iterating the loop through this variable
	if((strcmp(s1,buf1))==0)//comaparing harcoded name with user entered field name
	{
		printf("%s:",s1);//printing the field name
		scanf(" %[^\n]",s);//scanning the data from user for the corresponding field
		for(i=0;s[i];i++)//iterating loop and checking the condition for given field
		{
			if((s[i])==' ')//allowing user to take spaces are taken in name 
				continue;
			else if((s[i]>=65)&&(s[i]<=122))//if alphabets are present continue
				continue;
			else//if user types any other than alphabets it checks this condition
			{
				printf("please enter only alphabets space is also allowed\n");//popup message for invalid name
				print(p);//going back to function and scanning the data
			}
		}
		return no;//if it satisfies condition it returns
	}
	if((strcmp(s2,buf1))==0)
	{
		int cnt=3;//taking variable for checking the condition of user data 
		printf("%s",s2);//scanning data from user for respected filed
	printf(":-please enter last 3 digits of id\n");//popup message 
		scanf(" %[^\n]",s);//scanning the data from user
		if((strlen(s))==(cnt))//comparing user entered data length and cnt length
		{
			for(i=0;s[i];i++)
			{
				if((s[i]>=48)&&(s[i]<=57))//checking condition for user entered data
					continue;
				else 
				{
					printf("please enter valid id  0210xxx format\n");//popup message for invalid data
				       print(p);
				}
			}
		strcat(s5,s);//appending data with user entered data
		strcpy(s,s5);//copying that data into destination string for printing
		}
		else
		{
			printf("enter valid id should contain only 3 digits\n");//popup for invalid data
		        print(p);
		}
		return no;
	}
	if((strcmp(s3,buf1))==0)
	{
		char  ch[2]="@";//vriable for email
		if((strcmp(s3,buf1))==0)//checking the condition
		{
			printf("%s\n",s3);//printing filed data
			printf("enter name:");
			scanf(" %[^\n]",s);//scanning data from user
			char q[20];//memory for company name from user
			strcat(s,ch);//appending that data
			printf("enter company mane\n");
			scanf(" %[^\n]",q);//scanning company name from user
			strcat(s,q);//concatinating  field taken by user
			char c[10]=".com";//variable for email
			strcat(s,c);//appending and storing entire data 
		}
		return no;

	}

	if(strcmp(s4,buf1)==0)
	{
		int i,cnt=10,k;
		printf("%s:",s4);//printing the field
		scanf("%s",s);//scanning the data for required field
		char ch[30]="+91 ";//for appending the data with user 
		if((strlen(s))==(cnt))//checking the condition 
		{
			for(i=0;s[i];i++)
			{
				if((s[i]>=48)&&(s[i]<=57))
					continue;
				else
				{
					printf("please enter valid mobile number\n");
					print(p);
				}
			}
			strcat(ch,s);
			strcpy(s,ch);

		}
		else
		{
			printf("please enter valid mobno\n");
			print(p);
		}
		return no;
	}
	else
	{
		printf("%s:",buf1);//printing the filed data 
		scanf(" %[^\n]",s);//scanning the field data from user
		return no;
	}

}
void *p1(void *p)
{
	pthread_mutex_lock(&lock);
        details();//function for print the fileds data
	printf("Details are recorded succesfully\n");
	pthread_mutex_unlock(&lock);
}

void *p2(void *p)
{
	pthread_mutex_lock(&lock);
        details();
	printf("Details are recorded succesfully\n");
	pthread_mutex_unlock(&lock);
}
void *p3(void *p)
{
	pthread_mutex_lock(&lock);
        details();
	printf("Details are recorded succesfully\n");
	pthread_mutex_unlock(&lock);
}
void Voting_Responce()
{
	char c;
	int i=0;
	char s2[K]="_request.xls";
	if(system("ls *_request.xls"))//this will list the file with .xls extension
	{
		printf("No Request forms are not created\n");
		return;
	}
	printf("enter which file you want to open\n");
	scanf("%s",s1);//taking filename from user
	strcat(s1,s2);
	puts(s1);//displaying the filename
	f=fopen(s1,"r");
	if(f==NULL)
		printf("no excel has been created  for this request\n");
	else
	{
		while((c=fgetc(f))!=EOF)//storing each charector into buffer
		{
			buf[i++]=c;

		}

		buf[i]='\0';
		fclose(f);
		pthread_t t1,t2,t3;//creating 3 threads to take data from 3 users
		pthread_create(&t1,0,p1,0);
	        pthread_create(&t2,0,p2,0);
	        pthread_create(&t3,0,p3,0);
		pthread_join(t1,0);
		pthread_join(t2,0);
		pthread_join(t3,0);
	}
}


void details()
{
	char ch='\n';
	int i=0,j=0;
	f=fopen(s1,"a");
	fputc(ch,f); 
	fclose(f);
	for(i=0;buf[i];i++)//loop for checking each charector and performing operation 
	{
		if(buf[i]=='"')
			continue;

		if((buf[i]==',')||(buf[i]=='\t')||(buf[i+1]=='\0'))//taking the charectors and storing into buffer 
		{
			buf1[j]='\0';//placing null after taking data upto tab
			j=0;
			if(print(buf1))//calling print function and checking condition for given strings
			{
				f=fopen(s1,"a");
				fprintf(f,"%s\t",s);//printing the data into file
				fclose(f);
			}
		}
		else
		{
			buf1[j++]=buf[i];//storing each charector into 
		}

	}
}






