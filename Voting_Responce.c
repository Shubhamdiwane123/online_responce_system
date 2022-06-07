#include"Voting_Responce.h"
enum day{yes,no};
//#define M 50
//#define N 1000
//#define K 20
char s[M],s1[M],buf1[M],buf[N];
FILE *f;
//void details();
//void check();
pthread_mutex_t lock;
int dummy()
{
	return 0;
}
int print(char *p)
{
	char s1[K]="name",s2[K]="emp_id",s3[K]="email",s4[K]="mobno",s5[K]="0210";
	int i=0;
	if((strcmp(s1,buf1))==0)
	{
		printf("%s:",s1);
		scanf(" %[^\n]",s);
		for(i=0;s[i];i++)
		{
			if((s[i])==' ')
				continue;
			else if((s[i]>=65)&&(s[i]<=122))
				continue;
			else
			{
				printf("please enter only alphabets space is also allowed\n");
				print(p);
			}
		}
		return no;
	}


	if((strcmp(s2,buf1))==0)
	{
		int cnt=3;
		printf("%s",s2);
	printf(":-please enter last 3 digits of id\n");
		scanf(" %[^\n]",s);
		if((strlen(s))==(cnt))
		{
			for(i=0;s[i];i++)
			{
				if((s[i]>=48)&&(s[i]<=57))
					continue;
				else 
				{
					printf("please enter valid id  0210xxx format\n");
				       print(p);
				}
			}
		strcat(s5,s);
		strcpy(s,s5);
		puts(s);
		}
		else
		{
			printf("enter valid id should contain only 3 digits\n");
		        print(p);
		}
		//strcat(s5,s);
		//strcpy(s,s5);
		return no;
	}
	if((strcmp(s3,buf1))==0)
	{
		char  ch[2]="@";
		if((strcmp(s3,buf1))==0)
		{
			printf("%s\n",s3);
			printf("enter name:");
			scanf(" %[^\n]",s);
			char q[20];
			strcat(s,ch);
			printf("enter company mane\n");
			scanf(" %[^\n]",q);
			strcat(s,q);
			char c[10]=".com";
			strcat(s,c);
		}
		return no;

	}

	if(strcmp(s4,buf1)==0)
	{
		int i,cnt=10,k;
		printf("%s:",s4);
		scanf("%s",s);
		char ch[30]="+91 ";
		if((strlen(s))==(cnt))
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

		}
		else
		{
			printf("please enter valid mobno\n");
			print(p);
		}
		strcat(ch,s);
		strcpy(s,ch);
		return no;
	}
	else
	{
		printf("%s:",buf1);
		scanf(" %[^\n]",s);
		return no;
	}

}
void *p1(void *p)
{
	pthread_mutex_lock(&lock);
        details();
	printf("Details are recorded succesfully\n");
	pthread_mutex_unlock(&lock);
}

void *p2(void *p)
{
	pthread_mutex_lock(&lock);
        check();
	pthread_mutex_unlock(&lock);
}
void *p3(void *p)
{
	pthread_mutex_lock(&lock);
        check();
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
	scanf("%s",s1);
	strcat(s1,s2);
	puts(s1);
	f=fopen(s1,"r");
	if(f==NULL)
		printf("no excel has been created  for this request\n");
	else
	{
		while((c=fgetc(f))!=EOF)
		{
			buf[i++]=c;

		}

		buf[i]='\0';
		fclose(f);
		pthread_t t1,t2,t3;
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
	for(i=0;buf[i];i++)
	{
		if(buf[i]=='"')
			continue;

		if((buf[i]==',')||(buf[i]=='\t')||(buf[i+1]=='\0'))
		{
			buf1[j]='\0';
			j=0;
			if(print(buf1))
			{
				f=fopen(s1,"a");
				fprintf(f,"%s\t",s);
				fclose(f);
			}
		}
		else
		{
			buf1[j++]=buf[i];
		}

	}
	printf("Details are recorded successfully\n");
}

void check()
{
	int i;
t2:	printf("enter choice\n1:Do you want to enter another data\n2:exit from file\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:details();
		       break;
		case 2:dummy();
		       break;
		default:goto t2;
       }
}

