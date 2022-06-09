#include"main.h"
#include<ctype.h>
#include<dirent.h>
#define FEED 9
#define NAME_SIZE 80
#define SIZE 10
pthread_mutex_t lock;
char Tf[30];
int Li;
int check_opt(int);
void *data_enter();
//void *data_enter2();
//void *data_enter3();
void write_data(FILE *fp2);
char Email_check[]="@thundersoft.com";
typedef struct Employee
{
	char Emp_id[SIZE];
	char Name[NAME_SIZE];
	char Email_id[NAME_SIZE];
	char Reporting_manager[NAME_SIZE];
	char Feedback[FEED];
	//int Li;	
}Emp_d;
Emp_d det;
