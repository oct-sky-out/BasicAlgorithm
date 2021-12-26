//
//  lingQueue.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/26.
//

#ifndef lingQueue_h
#define lingQueue_h

typedef struct {
  int max;
  int front;
  int rear;
  int assignedSize;
  int* queue;
} IntLingQueue;

int initializeLingQueue(IntLingQueue *queueStructure, int maxQueueLength);

int lingEnqueue(IntLingQueue *queueStructure, int enqueueData);

int lingDequeue(IntLingQueue *queueStructure, int* shiftData);

int peekLingQueue(IntLingQueue *queueStructure, int *peekData);

void clearLingQueue(IntLingQueue *queueStructure);

int capacityLingQueue(IntLingQueue *queueStructure);

int assignedLingQueueSize(IntLingQueue *queueStructure);

int isEmptyLingQueue(IntLingQueue *queueStructure);

int isFullLingQueue(IntLingQueue *queueStructure);

int searchLingQueue(IntLingQueue *queueStructure, int searchData);

void printLingQueue(IntLingQueue *queueStructure);

void disorganizationLingQueue(IntLingQueue *queueStructure);

int initializeLingQueue(IntLingQueue *queueStructure, int maxQueueLength){
  queueStructure -> assignedSize = queueStructure -> front = queueStructure -> rear = 0;
  queueStructure -> queue = calloc(maxQueueLength, sizeof(int));
  if(queueStructure ->queue == NULL){
    queueStructure -> max = 0;
    return -1;
  }
  queueStructure -> max = maxQueueLength;
  return 0;
}

int lingEnqueue(IntLingQueue *queueStructure, int enqueueData){
  if(queueStructure -> assignedSize == queueStructure -> max)
    return -1;
  
  *(queueStructure -> queue + queueStructure -> rear++) = enqueueData;
  queueStructure -> assignedSize++;
  
  if(queueStructure -> rear == queueStructure -> max)
    queueStructure -> rear = 0;
  
  return 0;
}

int lingDequeue(IntLingQueue *queueStructure, int* shiftData){
  if(queueStructure -> assignedSize <= 0)
    return -1;
  *shiftData = *(queueStructure -> queue + queueStructure -> front);
  queueStructure -> front++;
  queueStructure -> assignedSize--;
  return 0;
}

int peekLingQueue(IntLingQueue *queueStructure, int *peekData){
  if(queueStructure -> assignedSize == 0)
    return -1;
  *peekData = *(queueStructure -> queue + queueStructure -> front);
  return 0;
}

void clearLingQueue(IntLingQueue *queueStructure){
  for (int i = 0; i < queueStructure -> assignedSize; i++) {
    *(queueStructure -> queue + i) = 0;
  }
  queueStructure -> rear = 0;
  queueStructure -> front = 0;
  queueStructure -> assignedSize = 0;
}

int capacityLingQueue(IntLingQueue *queueStructure){
  return queueStructure -> max;
}

int assignedLingQueueSize(IntLingQueue *queueStructure){
  return queueStructure -> assignedSize;
}

int isEmptyLingQueue(IntLingQueue *queueStructure){
  return queueStructure -> front != queueStructure -> rear ? 0 : -1;
}

int isFullLingQueue(IntLingQueue *queueStructure){
  return queueStructure -> front == queueStructure -> rear ? 0 : -1;
}

int searchLingQueue(IntLingQueue *queueStructure, int searchData){
  int front = queueStructure -> front;
  for (int i = 0; i < queueStructure -> assignedSize; i++) {
    if(*(queueStructure -> queue + front++) == searchData){
      return 0;
    }
    if(front == queueStructure -> max)
      front = 0;
  }
  return -1;
}

void printLingQueue(IntLingQueue *queueStructure){
  int front = queueStructure -> front;
  for (int i = 0; i < queueStructure -> assignedSize; i++) {
    printf("%d\n", *(queueStructure -> queue + front++));
    if(front == queueStructure -> max)
      front = 0;
  }
}

void disorganizationLingQueue(IntLingQueue *queueStructure){
  if(queueStructure -> queue != NULL){
    free(queueStructure -> queue);
    queueStructure -> assignedSize = 0;
    queueStructure -> max = 0;
    queueStructure -> rear = 0;
    queueStructure -> front = 0;
  }
}

#endif /* lingQueue_h */
