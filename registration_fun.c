#include"main.h"
#include"registration.h"
pthread_mutex_t lock;
void registration_fun()//registration function
{
	int n;
	int cnt_r=4;
        void (*fptr[3])();
        fptr[0] = create;
        fptr[1] = delete;
        fptr[2] = send;
	printf("Do you want 1.create (or) 2.delete (or) 3.send\nchoose(1/2/3)\n");
	scanf(" %d",&n);// choosing a function
	switch(n)
	{
 	 	case 1:fptr[0]();break;
		case 2:fptr[1]();break;
		case 3:fptr[2]();break;
		default: --cnt_r;
			 if(cnt_r<1)
			 {
				 printf("you choose the wrong option more than three times that's why application is closed\n");
				 exit(0);
			 }
			 else
			 {
				 printf("your enter invalid option you have only %d chance\n",cnt_r);
				 break;// if cnt is less than 3 then go to main again
			 }
	}
}
void create()
{
        char a[MAX];
        char b[MAX]="_training.xls";
	char c[MAX];
	char field;
        int i=0;
scan:
	do
	{
		printf("enter the excel file name\nEg string format is:-python or python123\n");
		scanf(" %[^\n]",a);
	}while(a[0]=='_'||a[0]>='0'&&a[0]<='9');//this will scan untill it does not start with _ and numbers
	for(i=0;a[i];i++)
	{
		if(a[i]>='0'&&a[i]<='9'&&a[i+1]>='a'&&a[i+1]<='z')
		{
			printf("wrong format\n");
			goto scan;
		}
		if(a[i]>='0'&&a[i]<='9'&&a[i+1]>='A'&&a[i+1]<='Z')
		{
			printf("wrong format\n");
			goto scan;
		}
		if(a[i]>='!'&&a[i]<='/'||a[i]>=':'&&a[i]<='@'||a[i]>='['&&a[i]<='`'||a[i]>='{'&&a[i]<='~')
		{
			printf("wrong format\n");
			goto scan;
		}
	}//This for loop will check the criteria for creating filename
	strcpy(c,a);
	for(i=0;a[i];i++)
	{
		if(a[i]==' ')
			a[i]='_';
	}//this is for adding '_' in the place of space
        strcat(a,b);
        printf("%s\n",a);
        FILE*fp;
        fp=fopen(a,"w");
        int n;
	printf("enter the fields for %s training form\n",c);
        do//this will scan the fields for the .xls file 
        {
                char read[MAX];
                scanf(" %[^\n]",read);
                fprintf(fp,"%s\t",read);
                i++;
		printf("Do you want add another field(y/n)\n");
                scanf(" %c",&field);
        }while(field=='y'||field=='Y');
	fclose(fp);
	

}
void delete()
{
	char delete[BEAST];//delete string will present in this variable eg:-rm filename.xls
	char d[MAX];
	char b[MAX]="_training.xls";
	char sure;
	if(system("ls *.xls"))//this will list the file with .xls extension
	{
		printf("Training forms are not created\n");
		return;
	}
	printf("Enter the file name to delete\n");
	scanf(" %s",d);//scanning file name
	char *p=strstr(d,b);//cheaking string "_training.xls" is present or not.If it present it'll do nothing otherwise strcat will add  
	if(p==NULL)
		strcat(d,b);//"_training.xls"
	
	snprintf(delete,sizeof(delete),"rm %s",d);//In delete it will add with "rm filename.xls"
	printf("Are you sure (y/n)\n");
	scanf(" %c",&sure);
	if(sure=='Y'||sure=='y')
	{
		system(delete);//delete that particular file
		printf("%s is deleted\n",d);//it will print that deleted file
	}
	else
	{
		printf("%s is not deleted\n",d);// if we give no at sure choice the else will print
	}
}
void send()
{
	pthread_t tid[3];
	char a[BEAST];
	char b[MAX]="_training.xls";
	printf("Enter the file name to send\nList of files are presented below:-\n");
	if(system("ls *.xls"))//this will list the file with .xls extension
        {
                printf("Training forms are not created\n");
                return;
        }
	scanf(" %s",a);
	char *p=strstr(a,b);//cheaking string "_training.xls" is present or not.If it present it'll do nothing otherwise strcat will add
        if(p==NULL)
                strcat(a,b);//"_training.xls"
	//printf("%s\n",a);
	if(!access(a,F_OK))//access is for checking the file is present or not
	{
		printf("%s\nfile is present\n",a);
		pthread_create(&tid[0],NULL,user_thread1,a);
		pthread_create(&tid[1],NULL,user_thread2,a);
		pthread_create(&tid[2],NULL,user_thread3,a);
		pthread_join(tid[0],NULL);
		pthread_join(tid[1],NULL);
		pthread_join(tid[2],NULL);
	}//and i created three user pthread
	else 
	{
		printf("%s\nfile does not created\n",a);
	}//if send file doesnot present else part will display
}
//three user containing the same coding these threads are used to collect the details from user
void*user_thread1(char*p)
{
	pthread_mutex_lock(&lock);
	int i;
	char ch;
	char firstline[BEAST];
	char scan[MAX];
	FILE*fp=fopen(p,"r");//opening file in a read mode
	if(!(fp==NULL))
		printf("details you have to fill\n");

	fscanf(fp,"%[^\n]",firstline);
	printf("%s\n",firstline);//it will print the all fields required
	fclose(fp);
	fp=fopen(p,"a");//again the same file opening in append mode
	fprintf(fp,"\n");//\n is used to get the file pointer to next line
#if 1	
	for(i=0;firstline[i];i++)
	{
		if(firstline[i]=='\t'||firstline[i]=='\n')
		{
		printf(":-");
			scanf("%s",scan);
			fprintf(fp,"%s\t",scan);
		}
		else
		{
			printf("%c",firstline[i]);
		}
	}//this whole for loop for scaning the details for each fields and it will fill that excel sheet
#endif
	

	fclose(fp);//closing file which is opened in append mode
	pthread_mutex_unlock(&lock);//mutex lock is used to avoid the thread can execute the same region
}
void*user_thread2(char*p)
{
	pthread_mutex_lock(&lock);
        int i;
        char ch;
        char firstline[BEAST];
        char scan[MAX];
        FILE*fp=fopen(p,"r");//opening file in a read mode
        if(!(fp==NULL))
                printf("details you have to fill\n");

        fscanf(fp,"%[^\n]",firstline);
        printf("%s\n",firstline);//it will print the all fields required
        fclose(fp);
        fp=fopen(p,"a");//again the same file opening in append mode
        fprintf(fp,"\n");//\n is used to get the file pointer to next line
#if 1
        for(i=0;firstline[i];i++)
        {
                if(firstline[i]=='\t'||firstline[i]=='\n')
                {
                        printf(":-");
                        scanf("%s",scan);
                        fprintf(fp,"%s\t",scan);
                }
                else
                {
                        printf("%c",firstline[i]);
                }
        }//this whole for loop for scaning the details for each fields and it will fill that excel sheet
#endif


        fclose(fp);//closing file which is opened in append mode
        pthread_mutex_unlock(&lock);//mutex lock is used to avoid the thread can execute the same region

}
void*user_thread3(char*p)
{
	pthread_mutex_lock(&lock);
        int i;
        char ch;
        char firstline[BEAST];
        char scan[MAX];
        FILE*fp=fopen(p,"r");//opening file in a read mode
        if(!(fp==NULL))
                printf("details you have to fill\n");

        fscanf(fp,"%[^\n]",firstline);
        printf("%s\n",firstline);//it will print the all fields required
        fclose(fp);
        fp=fopen(p,"a");//again the same file opening in append mode
        fprintf(fp,"\n");//\n is used to get the file pointer to next line
#if 1
        for(i=0;firstline[i];i++)
        {
                if(firstline[i]=='\t'||firstline[i]=='\n')
                {
                        printf(":-");
                        scanf("%s",scan);
                        fprintf(fp,"%s\t",scan);
                }
                else
                {
                        printf("%c",firstline[i]);
                }
        }//this whole for loop for scaning the details for each fields and it will fill that excel sheet
#endif


        fclose(fp);//closing file which is opened in append mode
        pthread_mutex_unlock(&lock);//mutex lock is used to avoid the thread can execute the same region

}
