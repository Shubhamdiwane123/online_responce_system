CC=gcc
CFLAGS = -c
OBJS = main.o registration_fun.o -lpthread Voting_Request.o Voting_Responce.o -lpthread feedback_func.o -lpthread
HDR = main.h Voting_Request.h Voting_Responce.h feedback.h
exe : $(OBJS) $(HDR)
	$(CC) $(OBJS) -o exe
main.o : main.c
	$(CC) $(CFLAGS) main.c
registration_fun.o : registration_fun.c
	$(CC) $(CFLAGS) registration_fun.c
feedback_func.o : feedback_func.c
	$(CC) $(CFLAGS) feedback_func.c
Voting_Request.o : Voting_Request.c
	$(CC) $(CFLAGS) Voting_Request.c
Voting_Responce.o : Voting_Responce.c
	$(CC) $(CFLAGS) Voting_Responce.c
clean :
	rm *.o
	rm exe
