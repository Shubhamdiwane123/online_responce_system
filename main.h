#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define MAX 30
#define BEAST 200
void Training();// for training registration and feedback
void Voting();// for voating request and responce
void registration_fun();// for training registration
void feedback_func();// for training feedback
void Voting_Request();// for voating request
void Voting_Responce();// for voating responce
