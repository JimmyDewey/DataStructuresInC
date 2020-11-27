#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef struct SNode * PtrToSNode;
typedef int ElementType;
struct SNode {
  ElementType * Data;
  Position Top;
  int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize) {
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->Top = -1;
  S->MaxSize = MaxSize;
  return S;
}

bool IsFull(Stack S) {
  return S->Top == S->MaxSize;
}

bool Push(Stack S, ElementType X) {
  if (IsFull(S)) {
    printf("STACK IS FULL");
    return false;
  } else {
    S->Data[++(S->Top)] = X;
    return true;
  }
}

bool IsEmpty(Stack S) {
  return S->Top == -1;
}

ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    printf("STACK IS EMPTY");
    return -999;
  } else {
    return S->Data[(S->Top)--];
  }
}

void PrintStack(Stack S) {
  for (int i = 0; i <= S->Top; i++) {
   printf("%d ", S->Data[i]); 
  }
  printf("\n");
}

int main() {
  Stack S = CreateStack(10);

  int arr[] = {123, 33, 2, 623, 234, 67, 78, 94, 99, 2345, 672, 54};

  for (int i = 0; i < S->MaxSize; i++) {
    Push(S, arr[i]);
  }
  PrintStack(S);

  printf("%d\n", Pop(S));
  PrintStack(S);

  return 0;
}
