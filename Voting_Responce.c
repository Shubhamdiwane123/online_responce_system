#include"Voting_Responce.h"
char Fname[20],buf[80]; // for scanning filename from user 
pthread_mutex_t lock;
FILE *F; //To access file operations
void *person1(void *p)
{
	pthread_mutex_lock(&lock);
	char str[20];
	int i;
	char ch='\n';
	F=fopen(Fname,"a");
	fputc(ch,F);
	for(i=0;buf[i];i++)
	{
		if(buf[i]==',')
			continue;
		else if((buf[i])!='\t')
			printf("%c",buf[i]);
		else
		{
			printf("\n");
			printf("use '_' in case of ' '\n");

			scanf("%s",str);
			fprintf(F,"%s\t",str);
		}

	}
	fclose(F);
	pthread_mutex_unlock(&lock);
}
void *person2(void *p)
{
	pthread_mutex_lock(&lock);
	char str[20];
	int i;
	char ch='\n';
	F=fopen(Fname,"a");
	fputc(ch,F);
	for(i=0;buf[i];i++)
	{
		if(buf[i]==',')
			continue;
		else if((buf[i])!='\t')
			printf("%c",buf[i]);
		else
		{
			printf("\n");
			printf("use '_' in case of ' '\n");

			scanf("%s",str);
			fprintf(F,"%s\t",str);
		}

	}
	fclose(F);
	pthread_mutex_unlock(&lock);
}

void *person3(void *p)
{
	pthread_mutex_lock(&lock);
	char str[20];
	int i;
	char ch='\n';
	F=fopen(Fname,"a");
	fputc(ch,F);
	for(i=0;buf[i];i++)
	{
		if(buf[i]==',')
			continue;
		else if((buf[i])!='\t')
			printf("%c",buf[i]);
		else
		{
			printf("\n");
			printf("use '_' in case of ' '\n");
			scanf("%s",str);
			fprintf(F,"%s\t",str);
		}

	}
	fclose(F);
	pthread_mutex_unlock(&lock);
}
void Voting_Responce()
{
	char ch;
	int i=0;

	system("ls *_request.xls");
	printf("enter file name\n");
	scanf("%s",Fname);
	F=fopen(Fname,"r");
	if(F==NULL)
	{
		printf("file not present\n");
		return ;
	}
	else
	{
		while(((ch=fgetc(F))!=EOF))
			buf[i++]=ch;
		buf[i++]=',';
		buf[i]='\0';
		fclose(F);
	}
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,person1,0);
pthread_create(&t2,NULL,person2,0);
pthread_create(&t3,NULL,person3,0);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
}
