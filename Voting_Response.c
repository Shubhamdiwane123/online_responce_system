#include"Voting_Response.h"
#include<dirent.h>
enum day{yes,no};
char s[M],s1[M],buf[N],buf1[N];
pthread_mutex_t lock;
int print(char *p)
{
	char s1[K]="Name",s2[K]="Emp_ID",s3[K]="Email_ID",s4[K]="Mobile_No",s5[K]="0210";//hardcoded names for some fileds
	int i=0;//for iterating the loop through this variable
	if((strcmp(s1,buf1))==0)//comaparing harcoded name with user entered field name
	{
		static int c=3;
		if(c==0)
		{
			printf("you have entered wrong input for 3 times\n");
			main();
		}
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
				if(c>0)
					printf("please enter only alphabets space is also allowed\n");//popup message for invalid name
				c--;
				print(p);//going back to function and scanning the data
			}
		}
		return no;//if it satisfies condition it returns
	}
	if((strcmp(s2,buf1))==0)
	{

		int cnt=10;
		static int c=3,k=0;//taking variable for checking the condition of user data 
		char buf[30],*h;
		h=buf;
		if(c==0)
		{
			printf("you have entered wrong input for 3 times\n");
			main();
		}
		printf("%s",s2);//scanning data from user for respected filed
		scanf(" %[^\n]",s);//scanning the data from user
		/*if(h=strstr(h,s))
		  {
		  printf("Response has been taken from this id\n");
		  c--;
		  print(p);
		  }*/
		if((strlen(s))<=(cnt))//comparing user entered data length and cnt length
		{
			for(i=0;s[i];i++)
			{
				if((s[0])!='0')
				{
					printf("enter valid id\n");
					c--;
					print(p);
				}

				else if((s[i]>=48)&&(s[i]<=57))//checking condition for user entered data
					continue;
				else 
				{
					if(c>0)
						printf("enter valid id\n");//popup message for invalid data                    
					c--;
					print(p);
				}
			}
			/*if(s[i]=='\0')
			  {
			  for(i=0;s[i];i++)
			  b[k++]=s[i];
			  b[k++]=',';
			  puts(b);
			  }*/

		}
		else
		{
			if(c>0)
				printf("enter valid id\n");//popup for invalid data
			c--;
			print(p);
		}
		return no;
	}


	if((strcmp(s3,buf1))==0)
	{	
		char m[20]="@thundersoft.com";
		int i,f=0,k=0,l=0;
		static int c=3;
		char *u;

		if(c==0)
		{
			printf("you have entered wrong input for 3 times\n");
			main();
		}
		printf("%s",s3);
		scanf(" %[^\n]",s);
		u=s;
		if((u=strstr(u,m)))
		{
			for(i=0;s[i];i++)
			{
				if(s[i+1]=='\0')
					return no;
				if((s[i]=='@')||(s[i]=='.')||(s[i]>=65&&s[i]<=122))
					continue;
				else
				{
					if(c>0)
						printf("enter valid email\n");
					print(p);
				}

			}
		}
		else
		{
			if(c>0)
				printf("enter valid email\n");
			print(p);

		}
		return no;
	}

	if(strcmp(s4,buf1)==0)
	{
		int i,cnt=10,k;
		static int c=3;
		if(c==0)
		{
			printf("you have entered wrong input for 3 times\n");
			main();
		}
		printf("%s:",s4);//printing the field
		scanf("%s",s);//scanning the data for required field
		if((strlen(s))==(cnt))//checking the condition 
		{
			for(i=0;s[i];i++)
			{
				if((s[i]>=48)&&(s[i]<=57))//checking condition for each index
					continue;
				else
				{
					if(c>0)
						printf("please enter valid mobile number\n");
					c--;
					print(p);
				}
			}

		}
		else
		{
			if(c>0)
				printf("please enter valid mobno\n");
			c--;
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
	printf("Details are recorded succesfully\n");//printing data after each person details are recorded
	pthread_mutex_unlock(&lock);
}

void *p2(void *p)
{
	pthread_mutex_lock(&lock);

	int c;
	int cnt_p2=4;
	while(1)
	{
		printf("press 1:Do you want to take another response\n2:main menu\n");
		scanf("%d",&c);
		if(c==1)
		{
			details();
			printf("Details are recorded succesfully\n");
			break;
		}
		else if(c==2)
		{
			main();
			break;
		}
		else
		{
			--cnt_p2;
			if(cnt_p2<1)
			{
				printf("you enter more than three times invalid option that's why it go to main menu\n");
				main();
			}
			else
			{
				printf("your enter invalid option you have only %d chance\n",cnt_p2);

			}
			}
	}

	pthread_mutex_unlock(&lock);

}
void *p3(void *p)
{
	int c;
	int cnt_p3=4;
	pthread_mutex_lock(&lock);
	while(1)
	{

		printf("press 1:Do you want to take another response\n2:main menu\n");
		scanf("%d",&c);
		if(c==1)
		{
			details();
			printf("Details are recorded succesfully\n");
			break;
		}
		else if(c==2)
		{
			main();
			break;
		}
		else 
		{
			--cnt_p3;
			if(cnt_p3<1)
			{
				printf("you enter more than three times invalid option that's why it go to main menu\n");
				main();
			}
			else
			{
				printf("your enter invalid option you have only %d chance\n",cnt_p3);

			}
		}
	}

	pthread_mutex_unlock(&lock);
}
void Voting_Response()
{
	FILE *f;
	char c;
	int i=0,l=0;
	char o[20]="request.xls";
	char b[20]="_request.xls";
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{

		while((dir=readdir(d))!=NULL)
		{


			if(strstr(dir->d_name,o))
			{
				l=1;
				printf("%s\n",dir->d_name);
			}

		}
		closedir(d);
	}
	if(l==0)
	{
		printf("no requests are created\n");
		main();
	}
	printf("enter your request form\n");
	scanf("%s",s1);//taking filename from user
	strcat(s1,b);
	f=fopen(s1,"r");//taking file and checking file is created or not
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
		pthread_t t[3];//creating 3 threads to take data from 3 users
		pthread_create(&t[0],0,p1,0);//thread-1
		pthread_join(t[0],0);
		pthread_create(&t[1],0,p2,0);//thread-2
		pthread_join(t[1],0);
		pthread_create(&t[2],0,p3,0);//thread-3
		pthread_join(t[2],0);
	}
}


void details()
{
	FILE *f;
	char ch='\n',b[100];//after taking details of each user setting the cursor to next line
	int i=0,j=0;
	int k=0;
	static int h=0;
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
				for(k=0;s[k];k++)
				{
					b[h++]=s[k];
				}
				b[h++]='\t';
				/*f=fopen(s1,"a");
				  fprintf(f,"%s\t",s);//printing the data into file
				  fclose(f);*/
			}
		}
		else
		{
			buf1[j++]=buf[i];//storing each charector into 
		}

	}

	if(buf[i]=='\0')
	{
		b[h]='\0';
		f=fopen(s1,"a");
		fputs(b,f);
		fclose(f);
		h=0;
	}
}






