#include"main.h"
#include<dirent.h>
#define FEED 256
#define NAME_SIZE 80
#define SIZE 8
pthread_mutex_t lock;
void feedback_func();
void *data_enter1();
void *data_enter2();
void *data_enter3();
void write_data(FILE *fp2);
char Email_check[]="@thundersoft.com";
typedef struct Employee
{
	char Emp_id[SIZE];
	char Name[NAME_SIZE];
	char Email_id[NAME_SIZE];
	char Reporting_manager[NAME_SIZE];
	char Feedback[FEED];	
}Emp_d;
Emp_d det;
