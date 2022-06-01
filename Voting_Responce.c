#include"Voting_Responce.h"
char Fname[10]; // for scanning filename from user 
pthread_mutex_t lock;
FILE *F; //To access file operations
void *person1(void *p)
{
pthread_mutex_lock(&lock);
	char data[20],ch;//(data=for taking data from user),(ch=taking data from file)
	char buf[80],*r;//(buf=to storing file data into buffer),(r=taking data upto null using strtok and printing)
	int i=0;//to store the data into buffer using this variable
	F=fopen(Fname,"r");
	if(F==NULL)
	{
		printf("file is not present\n");
	return 0;
	}
	else
	{
//	F=fopen(Fname,"r");
	while(((ch=fgetc(F))!=EOF))//taking loop and copying each data into buffer 
		buf[i++]=ch;
	buf[i]='\0';
	fclose(F);
	ch='\t'; 
	F=fopen(Fname,"a");//opening file to append data in next line
	r=strtok(buf,",");
	while(r!=NULL)
	{

		printf("%s\n",r);
		//r=strtok(NULL,",");
		scanf("%s",data);//taking data from user
		fputs(data,F);//putting the data into file
		fputc(ch,F);//for going to next coloumn
		r=strtok(NULL,",");
	}
	fclose(F);
	pthread_mutex_unlock(&lock);
	}
}

void *person2(void *p)
{
	pthread_mutex_lock(&lock);
	char data[20],ch,buf[80],*r;
	int i=0;
	F=fopen(Fname,"r");
	while(((ch=fgetc(F))!=EOF))
		buf[i++]=ch;
	buf[i]='\0';
	fclose(F);
	puts(buf);
	ch='\t';
	char c='\n';
	F=fopen(Fname,"a");
	fputc(c,F);
	r=strtok(buf,",");
	while(r!=NULL)
	{
		printf("%s\n",r);
		r=strtok(NULL,",");
		scanf("%s",data);
		fputs(data,F);
		fputc(ch,F);
	}
	fclose(F);
	pthread_mutex_unlock(&lock);
}
void *person3(void *p)
{

	pthread_mutex_lock(&lock);
	char data[20],ch,buf[80],*r;
	int i=0;
	F=fopen(Fname,"r");
	while(((ch=fgetc(F))!=EOF))
		buf[i++]=ch;
	buf[i]='\0';
	fclose(F);
	puts(buf);
	ch='\t';
	char c='\n';
	F=fopen(Fname,"a");
        fputc(c,F);
	r=strtok(buf,",");
	i=0;
	while(r!=NULL)
	{
		printf("%s\n",r);
		r=strtok(NULL,",");
		scanf("%s",data);
		fputs(data,F);
		fputc(ch,F);
	}
	fclose(F);
	pthread_mutex_unlock(&lock);
}
void Voting_Responce()
{
	system("ls");
	printf("enter file name\n");
	scanf("%s",Fname);
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,person1,0);
	pthread_create(&t2,NULL,person2,0);
	pthread_create(&t3,NULL,person3,0);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}
