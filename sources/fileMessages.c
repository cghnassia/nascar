#include "fileMessages.h"

static int msgId; 

struct message_t { 	//communication entre voitures et stands
	long type;
	int content;
};

int initFileMessages() {
	if((msgId = msgget(ftok(KEY, 1), IPC_CREAT | IPC_EXCL | 0666)) == -1) {
		return 1;
	}

	return 0;
}

int deleteFileMessage() {
	msgctl(msgId, IPC_RMID, NULL);	
	return 0;
}