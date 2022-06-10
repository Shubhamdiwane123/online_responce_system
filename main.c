#include"main.h"// it contain all header files and function declration
int main()
{
	int  choice_main;// for choice we take variable
	int cnt_main=4,count=4;// for counting how many times user chose wrong option
	void (*first[])()={Training,Voting};

	while(1)
	{
		__fpurge(stdin);
		printf("1.Training 2.Voting 3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice_main);
		if(choice_main>=0 && choice_main<=9)//for checking enter input is integer or not
		{
			switch(choice_main)
			{
				case 1: first[0]();// for go to training functon 
					break;
				case 2: first[1]();// for go to voating function
					break;
				case 3: exit(0);// for exit from the application
				default: --cnt_main;//if user choose wrong options cnt is  incrementing 
					 if(cnt_main<1)//if cnt is more than 3 times then exit from application
					 {
						 printf("you select more than three times wrong option that's why application is closed\n");
						 exit(0);
					 }
					 else
					 {
						 printf("you enter invalid option you have only %d chance\n",cnt_main);
						 break;// if cnt is less than 1 then application is closed
					 }
			}
		}
		else// if enter input is not integer then it go in these part
		{
			--count;
			if(count<1)//if user enter more than three time wrong input then it go in that 
			{
				printf("you enter more than three time wrong option that's why application is closed\n");
				exit(0);
			}
			else
				printf("invalid option you  have only %d chance\n",count);
		}
	}

}
void Training()// function for training registration and feedback
{
	int choice_t;//for choice we take these variable
	int cnt_t=4,count_t=4;//for counting how many times user chosing wrong option
	void (*training[])()={registration_fun,feedback_func};
	while(1)
	{
		__fpurge(stdin);
		printf("1.registration 2. feedback 3.main_menu\n");
		printf("enter your choice\n");
		scanf("%d",&choice_t);
		if(choice_t>=0 && choice_t<=9) //for checking enter input is integer or not

		{
			switch(choice_t)
			{
				case 1: training[0]();//for go to training_registration function
					break;
				case 2: training[1]();// for go to training_feedback function
					break;
				case 3: main();
				default:cnt_t--;//if user choose wrong options then cnt incremented
					if(cnt_t<1)// if cnt is more than 3 then exit
					{
						printf("you select more than three times wrong option that's why it go to main menu\n");
						main();
					}
					else
					{
						printf("you enter invalid option you have only %d chance\n",cnt_t);
						break;// if cnt is less than 1 then go to main again
					}
			}
		}
		else // if enter input is not integer then it go in these part

		{
			--count_t;
			if(count_t<1)
			{
				printf("you enter more than three time wrong option that's why it go to main menu\n");
				main();
			}
			else
				printf("invalid option you  have only %d chance\n",count_t);
		}

	}
}	
void Voting()// function for voating request and responce
{
	int choice_v;// for choose option
	int cnt_v=4,count_v=4;// for counting how many times user chosing wrong options
	void (*voting[])()={Voting_Request,Voting_Responce};
	while(1)
	{
		__fpurge(stdin);
		printf("1.request 2.responce 3.main_menu\n");
		printf("enter your choice\n");
		scanf("%d",&choice_v);
		if(choice_v>=0 && choice_v<=9) //for checking enter input is integer or not

		{
			switch(choice_v)
			{
				case 1: voting[0]();//for go to voting request function
					break;
				case 2: voting[1]();// for go to voting responce function
					break;
				case 3: main();
				default:cnt_v--;// if user choose wrong option then cnt is increamented
					if(cnt_v<1)// if cnt is more than 3 then exit
					{
						printf("you select more than three times wrong option that's why it going to main menu\n");
						main();
					}
					else
					{
						printf("you enter invalid option you have only %d chance\n",cnt_v);
						break;// if cnt is less than 3 then go to main again
					}
			}
		}
		else // if enter input is not integer then it go in these part

		{
			--count_v;
			if(count_v<1)
			{
				printf("you enter more than three time wrong option that's why it go main menu\n");
				main();
			}
			else
				printf("invalid option you  have only %d chance\n",count_v);
		}
	}

}
