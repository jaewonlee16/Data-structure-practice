#include "CircularQueue.h"

int main(){
	int i;
	CircularQueue* Queue;
	
	CQ_CreateQueue(&Queue, 10);
	
	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);
	
	for (i = 0; i < 3; i++){
		printf("Dequeue: %d, ", CQ_Dequeue(Queue));
		printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
	}
	
	
	CQ_DestroyQueue(Queue);
	
	return 0;
}
