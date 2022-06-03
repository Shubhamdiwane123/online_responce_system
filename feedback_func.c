
#include "feedback.h"
void feedback_func()
{
DIR * dir = opendir(".");		// to oprn directory
if(dir == NULL)
{
	return ;
}
	struct dirent* entity;
	entity = readdir(dir);
	int i=0;
	char *ctf[i][30];   			// declared ctf to store created training files			
	char check[]="_training.xls";
	while(entity != NULL)
	{
	if(strstr(entity->d_name,check) && !strstr(entity->d_name,"#"))
	{
		i++;
		ctf[i][30]=entity->d_name;		// created training files will store here

	}
	entity = readdir(dir);
}


//---------------------------

FILE *fp;
int k=0;
char *stf[k][30];			// declared stf to store send training files : done trainng files 
for (int j =1;j<=i;j++)
{
	
	fp = fopen(ctf[j][30],"r");
	if(fp == NULL)
	{
		
		printf("file didnt present");
		return ;
	}
	else{
		char ch;
		int count=1;
		while(1)
		{
			ch = fgetc(fp);
			if(ch =='\n')
				count++;
			if(feof(fp))
				break;
		}
		fclose(fp);
		printf("%d\n",count);
		if(count > 1)     // checking whether the responses are saved or not
				   // if resopnses saved then files will store to stf
		{
			k++;
			stf[k][30]=ctf[j][30];
				
		}
	}
	
}
if(k==0)
{
	printf("No trainings are conducted ");
	return ;
}
printf("Below trainings have been conducted.\n");
for(int j = 1; j<=k;j++)
{
	printf("%d. %s \n",j,stf[j][30]);    // displaying the completed training files
}
int opt;
printf("Enter no. of the file that you want to give feedback\n");
scanf("%d",&opt);
char fn[30];
strcpy(fn,stf[opt][30]);
printf("%s",fn);
//printf("selected option is %d",opt);
//---------------------------------------------
char* split = strtok(fn,".");
strcat(split,"_feedback.xls");

FILE *fp2 = fopen(split,"w");
fprintf(fp2,"EMP ID\t");
fprintf(fp2,"EMP NAME\t");
fprintf(fp2,"EMAIL ID\t");
fprintf(fp2,"REPORTING MANAGER\t");
fprintf(fp2,"FEEDBACK\n");

pthread_t tid[3];


pthread_create(&tid[0],NULL,data_enter1,fp2);   // creating threads to store employee details
pthread_create(&tid[1],NULL,data_enter2,fp2);
pthread_create(&tid[2],NULL,data_enter3,fp2);


pthread_join(tid[0],NULL);
pthread_join(tid[1],NULL);
pthread_join(tid[2],NULL);

fclose(fp2);
closedir(dir);
return ;
}

void check_id()
{
	printf("\nEnter the Employee ID :");
	//getchar();
	scanf("%s",det.Emp_id);
	if(det.Emp_id[0] != '0')
	{
		printf("\nWrong input give again\n");
		check_id();
	}
}
void check_name()
{
	printf("\nEnter the Employee Name : ");
	getchar();
	scanf("%[^\n]",det.Name);
	int k=0;
	while(det.Name[k] != '\0')
	{
		if(det.Name[k]==' ' || (det.Name[k] >= 65 && det.Name[k] <= 90) || (det.Name[k] >= 97 && det.Name[k]<=122))
		{
			k++;
		}
		else
		{
			
			printf("\nNo special chareacters are allowed, Given input again\n");
			check_name();
		}
	}

}

void check_email()
{
	printf("\nEnter the Employee email id :");
	scanf("%s",det.Email_id);
	if(!strstr(det.Email_id,Email_check))
	{
		printf("\nNot thundersoft mail extension\n");
		check_email();
	}
}


void check_reporting_manager()
{

	printf("\nEnter the name of the reporting manager : ");
	getchar();
	scanf("%[^\n]",det.Reporting_manager);
	int k=0;
	while(det.Reporting_manager[k] != '\0')
	{
		if(det.Reporting_manager[k]==' ' || (det.Reporting_manager[k] >= 65 && det.Reporting_manager[k] <= 90) || (det.Reporting_manager[k] >= 97 && det.Reporting_manager[k]<=122))
		{
			k++;
		}
		else
		{
			
			printf("\nNo special chareacters are allowed, Given input again\n");
			check_reporting_manager();
		}
	}
	
}

void check_feedback()
{
	printf("\nEnter the feedback : ");
	getchar();
	scanf("%[^\n]",det.Feedback);
	int k=0;
	while(det.Feedback[k] != '\0')
	{
		if(det.Feedback[k]==' ' || (det.Feedback[k] >= 65 && det.Feedback[k] <= 90) || (det.Feedback[k] >= 97 && det.Feedback[k]<=122))
		{
			k++;
			
		}
		else
		{
			
			printf("\nNo special chareacters are allowed, Given input again\n");
			check_feedback();
		}
	}
	if(k > FEED)
	{
		printf("size of the input is exceeded, feedback should contain 256 characters");
		check_feedback();
	}
}


void *data_enter1(FILE *fp2)
{
	pthread_mutex_lock(&lock);
	
	check_id();
	
	check_name();
	
	check_email();
  
    	check_reporting_manager();
	
	check_feedback();
	
	write_data(fp2);
	pthread_mutex_unlock(&lock);
}

void *data_enter2(FILE *fp2)
{
	pthread_mutex_lock(&lock);
	
	check_id();
	
	check_name();
	
	check_email();
  
    	check_reporting_manager();
	
	check_feedback();
	
	write_data(fp2);
	pthread_mutex_unlock(&lock);

}

void *data_enter3(FILE *fp2)
{
	pthread_mutex_lock(&lock);
	
	check_id();
	
	check_name();
	
	check_email();
  
    	check_reporting_manager();
	
	check_feedback();
	
	write_data(fp2);
	pthread_mutex_unlock(&lock);
}

void write_data(FILE *fp2)
{
	
	fprintf(fp2,"%s\t",det.Emp_id);
	fprintf(fp2,"%s\t",det.Name);
	fprintf(fp2,"%s\t",det.Email_id);
	fprintf(fp2,"%s\t",det.Reporting_manager);
	fprintf(fp2,"%s\n",det.Feedback);
	
}




