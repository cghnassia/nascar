#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <pthread.h>

#include "config.h"
#include "circuit.h"
#include "voiture.h"
//#include "fileMessages.h"






int removeIPC() {
	//msgctl(msgId, IPC_RMID, NULL);	
	return 0;
}

int main() {
	initCircuit();
	initVoitures();
	//initQueue();
	//initSem();

	//removeIPC();

}
