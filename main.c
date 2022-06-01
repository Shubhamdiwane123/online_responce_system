#include"main.h"// it contain all header files and function declration
int main()
{
	int choice_main;// for choice we take variable
	int cnt_main=0;// for counting how many times user chose wrong option
	void (*first[])()={Training,Voting};

	while(1)
	{
		printf("1.Training 2.Voating 3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice_main);
		switch(choice_main)
		{
			case 1: first[0]();// for go to training functon 
				break;
			case 2: first[1]();// for go to voating function
				break;
			case 3: exit(0);// for exit from the application
			default: cnt_main++;//if user choose wrong options cnt is  incrementing 
				 if(cnt_main>3)//if cnt is more than 3 times then exit from application
				 {
					 printf("you select three times wrong option that's why application is closed\n");
					 exit(0);
				 }
				 else
					 break;// if cnt is less than 3 then go to main again
		}
	}
}
void Training()// function for training registration and feedback
{
	int choice_t;//for choice we take these variable
	int cnt_t=0;//for counting how many times user chosing wrong option
	void (*training[])()={registration_fun,feedback_func};
	while(1)
	{
		printf("1.registration_fun 2. feedback 3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice_t);
		switch(choice_t)
		{
			case 1: training[0]();//for go to training_registration function
				break;
			case 2: training[1]();// for go to training_feedback function
				break;
			case 3: exit(0);
			default:cnt_t++;//if user choose wrong options then cnt incremented
				 if(cnt_t>3)// if cnt is more than 3 then exit
				 {
					 printf("you select three times wrong option that's why application is closed\n");
                                         exit(0);
                                 }
                                 else
                                         break;// if cnt is less than 3 then go to main again
		}
	}
}	
void Voting()// function for voating request and responce
{
	int choice_v;// for choose option
        int cnt_v=0;// for counting how many times user chosing wrong options
        void (*voting[])()={Voting_Request,Voting_Responce};
        while(1)
        {
                printf("1.request 2.responce 3.exit\n");
                printf("enter your choice\n");
                scanf("%d",&choice_v);
                switch(choice_v)
                {
                        case 1: voting[0]();//for go to voting request function
                                break;
                        case 2: voting[1]();// for go to voting responce function
                                break;
                        case 3: exit(0);
                        default:cnt_v++;// if user choose wrong option then cnt is increamented
                                 if(cnt_v>3)// if cnt is more than 3 then exit
                                 {
                                         printf("you select three times wrong option that's why application is closed\n");
                                         exit(0);
                                 }
                                 else
                                         break;// if cnt is less than 3 then go to main again
                }
	}
	
}
