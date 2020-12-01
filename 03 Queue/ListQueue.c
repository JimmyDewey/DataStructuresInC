#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
  ElementType Data;
  PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *PtrToQNode;
struct QNode {
  Position Front, Rear;
  int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize) {
  Queue Q = (Queue)malloc(sizeof(struct QNode));
  Q->MaxSize = MaxSize;
  return Q;
}

bool IsFull(Queue Q) { return Q->Rear - Q->Front + 1 == Q->MaxSize; }

bool AddQ(Queue Q, ElementType X) {
  if (IsFull(Q)) {
    printf("QUEUE IS FULL");
    return false;
  } else {
    Q->Rear->Next = (Position)malloc(sizeof(struct Node));
    Q->Rear = Q->Rear->Next;
    Q->Rear->Data = X;
    return true;
  }
}

bool IsEmpty(Queue Q) { return Q->Front == NULL; }

ElementType DeleteQ(Queue Q) {
  Position FrontCell;
  ElementType FrontElem;

  if (IsEmpty(Q)) {
    printf("QUEUE IS EMPTY");
    return -1;
  } else {
    FrontCell = Q->Front;
    if (Q->Front == Q->Rear) { // the last one in this queue
      Q->Front = Q->Rear = NULL;
    } else {
      Q->Front = Q->Front->Next;
    }
    FrontElem = FrontCell->Data;

    free(FrontCell);
    return FrontElem;
  }
}

int Length(Queue Q) {
  int count = 0;
  for (Position p = Q->Front; p != Q->Rear + 1; p++) {
    count++;
    p = p->Next;
  }
  return count;
}

void PrintQueue(Queue Q) {
  if(!Q->Front || !Q->Rear)
    return;
  for(Position p = Q->Front; p != Q->Rear; p++) {
    printf("%d ", p->Data);
  }
  printf("%d\n", Q->Rear->Data);
}

int main() {
  Queue Q = CreateQueue(10);
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  PrintQueue(Q);

  for (int i = 0; i < Q->MaxSize; i++) {
    AddQ(Q, arr[i]);
  }
  PrintQueue(Q);

  return 0;
}
