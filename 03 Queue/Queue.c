#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
  ElementType *Data;
  Position Front, Rear;
  int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize) {
  Queue Q = (Queue)malloc(sizeof(struct QNode));
  Q->Data = (ElementType *)malloc(MaxSize * sizeof(struct QNode));
  Q->Front = Q->Rear = 0;
  Q->MaxSize = MaxSize;
  return Q;
}

bool IsFull(Queue Q) { return ((Q->Rear + 1) % Q->MaxSize == Q->Front); }

bool AddQ(Queue Q, ElementType X) {
  if (IsFull(Q)) {
    printf("QUEUE IS FULL\n");
    return false;
  } else {
    Q->Rear = (Q->Rear + 1) % Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return true;
  }
}

bool IsEmpty(Queue Q) { return Q->Front == Q->Rear; }

ElementType DeleteQ(Queue Q) {
  if (IsEmpty(Q)) {
    printf("QUEUE IS EMPTY\n");
    return -1;
  } else {
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];
  }
}

void PrintQueue(Queue Q) {
  for (int i = Q->Front + 1; i != Q->Rear; i = (i + 1) % Q->MaxSize) {
    printf("%d ", Q->Data[i]);
  }
  printf("%d\n", Q->Data[Q->Rear]);
}

int main() {
  Queue Q = CreateQueue(11);
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) {
    AddQ(Q, arr[i]);
  }
  PrintQueue(Q);

  DeleteQ(Q);
  PrintQueue(Q);
}
