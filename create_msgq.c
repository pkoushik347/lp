#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(){
	key_t key;
	int msgid;
	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	if(msgid == -1)
		printf("\nQueue not created\n");
	else
		printf("\nQueue created succesfully\n");
	return 0;
}
