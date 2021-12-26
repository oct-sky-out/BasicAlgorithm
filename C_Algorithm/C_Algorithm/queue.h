//
//  queue.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/26.
//

#ifndef queue_h
#define queue_h

typedef struct {
  int max;
  int assignedSize;
  int* queue;
} IntQueue;

int initializeQueue(IntQueue *queueStructure, int maxQueueLength);

int enqueue(IntQueue *queueStructure, int enqueueData);

int dequeue(IntQueue *queueStructure, int* shiftData);

int peekQueue(IntQueue *queueStructure, int *peekData);

void clearQueue(IntQueue *queueStructure);

int capacityQueue(IntQueue *queueStructure);

int assignedQueueSize(IntQueue *queueStructure);

int isEmptyQueue(IntQueue *queueStructure);

int isFullQueue(IntQueue *queueStructure);

int searchQueue(IntQueue *queueStructure, int searchData);

void printQueue(IntQueue *queueStructure);

void disorganizationQueue(IntQueue *queueStructure);

int initializeQueue(IntQueue *queueStructure, int maxQueueLength){
  queueStructure -> assignedSize = 0;
  queueStructure -> queue = calloc(maxQueueLength, sizeof(int));
  if(queueStructure -> queue == NULL){
    queueStructure -> max = 0;
    return -1;
  }
  queueStructure -> max = maxQueueLength;
  return 0;
}

int enqueue(IntQueue *queueStructure, int enqueueData){
  if(queueStructure -> assignedSize == queueStructure -> max)
    return -1;
  
  *(queueStructure -> queue + queueStructure -> assignedSize++) = enqueueData;
  return 0;
}

int dequeue(IntQueue *queueStructure, int* shiftData){
  if(queueStructure -> assignedSize <= 0)
    return -1;
  *shiftData = *(queueStructure -> queue);
  for (int i = 0; i < queueStructure -> max; i++) {
    int next = i == queueStructure -> max ? 0 : i+1;
    *(queueStructure -> queue + i) = *(queueStructure -> queue + next);
  }
  queueStructure -> assignedSize--;
  return 0;
}

int peekQueue(IntQueue *queueStructure, int *peekData){
  if(queueStructure -> assignedSize == 0)
    return -1;
  *peekData = *(queueStructure -> queue);
  return 0;
}

void clearQueue(IntQueue *queueStructure){
  for (int i = 0; i < queueStructure -> assignedSize; i++)
    *(queueStructure -> queue + i) = 0;
  
  queueStructure -> assignedSize = 0;
}

int capacityQueue(IntQueue *queueStructure){
  return queueStructure -> max;
}

int assignedQueueSize(IntQueue *queueStructure){
  return queueStructure -> assignedSize;
}

int isEmptyQueue(IntQueue *queueStructure){
  return queueStructure -> assignedSize == 0  ? 0 : -1;
}

int isFullQueue(IntQueue *queueStructure){
  return queueStructure -> assignedSize != 0  ? 0 : -1;
}

int searchQueue(IntQueue *queueStructure, int searchData){
  for (int i = 0; i < queueStructure -> assignedSize; i++) {
    if(*(queueStructure -> queue + i) == searchData)
      return 0;
  }
  return -1;
}

void printQueue(IntQueue *queueStructure){
  for (int i = 0; i < queueStructure -> assignedSize; i++) {
    printf("%d\n", *(queueStructure -> queue + i));
  }
}

void disorganizationQueue(IntQueue *queueStructure){
  if(queueStructure -> queue != NULL){
    free(queueStructure -> queue);
    queueStructure -> assignedSize = 0;
    queueStructure -> max = 0;
  }
}

#endif /* queue_h */
