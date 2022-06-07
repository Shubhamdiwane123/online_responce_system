#include "registration.h"

void create();
void delete();
void send();
//thread
void*user_thread1();
void*user_thread2();
void*user_thread3();
//
//static int k=0;
//static char*string[k][256];
//mutex
pthread_mutex_t lock;
void registration_fun()// void registration function
{
	int n;//choosing option in switch
	int cnt_r=4;
        void (*fptr[3])();
        fptr[0] = create;
        fptr[1] = delete;
        fptr[2] = send;
	while(1)
	{
	printf("Do you want 1.create (or) 2.delete (or) 3.send (or) 4.Main menu\nchoose(1/2/3/4)\n");
	scanf(" %d",&n);// choosing a function
	switch(n)
	{
 	 	case 1:fptr[0]();break;
		case 2:fptr[1]();break;
		case 3:fptr[2]();break;
		case 4:main(); break;
		default:--cnt_r;
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
}
void create()
{
        char a[MAX];//scaning file name
        char b[MAX]="_training.xls";//adding this with file for perfect format
	char c[MAX];//copy of scanned file name
	char field;//getting fields from user
        int i=0;//this is used in for loop
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
        FILE*fp;//file pointer
        fp=fopen(a,"w");
        char n;
	char p[30]="name";
	printf("enter the fields for %s training form\n",c);
	printf("do you want to add name in fields(y/n)\n");
	scanf(" %c",&n);
	if(n=='y'||n=='Y')
	{
		fprintf(fp,"%s\t",p);
	}
	printf("do you want to add Emp_id in fields(y/n)\n");
	scanf(" %c",&n);
	if(n=='y'||n=='Y')
	{
		fprintf(fp,"%s\t","Emp_id");
	}
	printf("do you want to add email in fields(y/n)\n");
        scanf(" %c",&n);
        if(n=='y')
        {
                fprintf(fp,"%s\t","email");
        }
	printf("do you want to add mobno in fields(y/n)\n");
        scanf(" %c",&n);
        if(n=='y')
        {
                fprintf(fp,"%s\t","mobno");
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
	printf("%s file is created\n",a);
//	static int k=0;
//	char*files[k][256];
//	k++;
//	string[k][256]=a;
//	printf("%s\n",string[k][256]);
}
void delete()
{
	char delete[BEAST];//delete string will present in this variable eg:-rm filename.xls
	char d[MAX];//scanning file name for deletion
	char b[MAX]="_training.xls";
	char t[MAX]="_request.xls";
	int i;
	char sure;// asking for sure to delete
	printf("1)Training file 2)Request file\n");
	scanf(" %d",&i);
	if(i==1)
	{
	if(system("ls *training.xls"))//this will list the file with .xls extension
	{
		printf("Training forms are not created\n");
		return;
	}
	printf("Enter the file name to delete\n");
	scanf(" %[^\n]",d);//scanning file name
	for(i=0;d[i];i++)
        {
                if(d[i]==' ')
                        d[i]='_';
        }//this is for adding '_' in the place of space

	char *p=strstr(d,b);//cheaking string "_training.xls" is present or not.If it present it'll do nothing otherwise strcat will add  
	if(p==NULL)
		strcat(d,b);//"_training.xls"
	}
	if(i==2)
        {
        if(system("ls *request.xls"))//this will list the file with .xls extension
        {
                printf("Request forms are not created\n");
                return;
        }
        printf("Enter the file name to delete\n");
        scanf(" %[^\n]",d);//scanning file name
        for(i=0;d[i];i++)
        {
                if(d[i]==' ')
                        d[i]='_';
        }//this is for adding '_' in the place of space

        char *p=strstr(d,t);//cheaking string "_request.xls" is present or not.If it present it'll do nothing otherwise strcat will add
        if(p==NULL)
                strcat(d,t);//"_request.xls"
        }

	snprintf(delete,sizeof(delete),"rm %s",d);//In delete it will add with "rm filename.xls"
	if(!access(d,F_OK))//access is for checking the file is present or not
        {
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
	else
        {
                printf("%s\nfile does not created\n",d);
        }//if send file doesnot present else part will display
}
	
void send()
{
	pthread_t tid[3];
	int i;
	char a[BEAST];//scanning for filename
	char b[MAX]="_training.xls";
	printf("Enter the file name to send\nList of files are presented below:-\n");
	if(system("ls *training.xls"))//this will list the file with .xls extension
        {
                printf("Training forms are not created\n");
                return;
        }
	scanf(" %[^\n]",a);
	for(i=0;a[i];i++)
        {
                if(a[i]==' ')
                        a[i]='_';
        }//this is for adding '_' in the place of space

	char *p=strstr(a,b);//cheaking string "_training.xls" is present or not.If it present it'll do nothing otherwise strcat will add
        if(p==NULL)
                strcat(a,b);//"_training.xls"
	//printf("%s\n",a);
	char m;
	if(!access(a,F_OK))//access is for checking the file is present or not
	{
		printf("%s\nfile is present\n",a);
		do{
		pthread_create(&tid[0],NULL,user_thread1,a);
		pthread_join(tid[0],NULL);
		printf("do you want to add one more details(y/n)\n");
		scanf(" %c",&m);
		}while(m=='y'||m=='Y');
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
	int j=0,k=0;
	char ab[100];
	for(i=0;firstline[i];i++)
	{
		if(firstline[i]=='\t'||firstline[i]=='\n')
		{
			printf(":-");
thread:			scanf(" %[^\n]",scan);
			if(strstr(ab,"name")||strstr(ab,"NAME")||strstr(ab,"Name"))
			{
			for(int k=0;scan[k];k++)
			{
				if((scan[k]>='a'&&scan[k]<='z')||(scan[k]>='A'&&scan[k]<='Z')||(scan[k]==' '))
				{
					continue;
				}
				else
				{
					printf("only character should allowed\nname:-");
					goto thread;
				}
			}
			fprintf(fp,"%s\t",scan);
			j=0;
			}
			else if(strstr(ab,"number")||strstr(ab,"NUMBER")||strstr(ab,"Number")||strstr(ab,"NUM")||strstr(ab,"Num")||strstr(ab,"num")||strstr(ab,"mobno")||strstr(ab,"mob_no")||strstr(ab,"mobile")||strstr(ab,"Mobile")||(strstr(ab,"MOBILE"))||(strstr(ab,"Mobile_number"))||strstr(ab,"Mobile_Number")||strstr(ab,"MOBILE_NUMBER")||strstr(ab,"mobile_number")||strstr(ab,"mobilenumber")||strstr(ab,"MOBILENUMBER"))
                        {
                        for(k=0;scan[k];k++)
                        {
                                if(scan[k]>='0'&&scan[k]<='9')
                                {
                                        continue;
                                }
				else
                                {
                                        printf("only numeric should allowed\nnumber:-");
                                        goto thread;
                                }
                        }
			if(k==10)
                        fprintf(fp,"%s\t",scan);
			else
			{
				printf("invalid number\nnumber:-");
				goto thread;
			}
                        j=0;
                        }
			else if(strstr(ab,"email_id")||strstr(ab,"email")||strstr(ab,"Email")||strstr(ab,"EMAIL_ID")||strstr(ab,"EMAIL")||strstr(ab,"emailid")||strstr(ab,"EMAILID"))
                        {
                        for(k=0;scan[k];k++)
                        {
                                if(strstr(scan,"@gmail.com"))
                                {
                                        continue;
                                }
                                else
                                {
                                        printf("wrong email\nEnter your Email:-");
                                        goto thread;
                                }
                        }
                        fprintf(fp,"%s\t",scan);
                        j=0;
                        }
			else if(strstr(ab,"EMP_ID")||strstr(ab,"emp_id")||strstr(ab,"Emp_id")||strstr(ab,"Emp_ID")||strstr(ab,"ID")||strstr(ab,"id"))
                        {
                        for(k=0;scan[k];k++)
                        {
                                if(scan[0]=='0')
                                {
                                        continue;
                                }
                                else
                                {
                                        printf("wrong emp_ID it should start with zero\nEnter your Emp_id:-");
                                        goto thread;
                                }
                        }
			if(k==7){
                        fprintf(fp,"%s\t",scan);
			}
			else
			{
				printf("invalid emp_id\n");
				goto thread;
			}
                        j=0;
                        }
			else
			{
				fprintf(fp,"%s\t",scan);
			}

		}
		else
		{
			printf("%c",firstline[i]);
			ab[j++]=firstline[i];
		}
	}//this whole for loop for scaning the details for each fields and it will fill that excel sheet
	

	fclose(fp);//closing file which is opened in append mode
	pthread_mutex_unlock(&lock);//mutex lock is used to avoid the thread can execute the same region
}
//three user containing the same coding these threads are used to collect the details from user
