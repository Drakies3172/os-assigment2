#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size == MAX_QUEUE_SIZE)
		return;
	else
	{
		int i;
		for (i = 0; i < MAX_QUEUE_SIZE; i++) {
			if (q->proc[i] == NULL) {
				q->proc[i] = proc;
				q->size++;
			}
		}
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) {
		return NULL;
	}
	else
	{
		struct pcb_t* proc = NULL;
		int j = 0,i;
		for (i = 0; i < q->size -1; i++) {
			if (q->proc[i]->priority < q->proc[i + 1]->priority) {
				j = i;
			}
		}
		proc = q->proc[j];
		for (i = 0; i < q->size-1; i++) {
			if (i >= j) {
				q->proc[i] = q->proc[i + 1];
			}
		}
		q->size--;
		return proc;
	}
}

