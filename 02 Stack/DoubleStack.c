#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Position;
typedef struct SNode *PtrToSNode;
typedef int ElementType;
struct SNode {
  ElementType *Data;
  Position Top1;
  Position Top2;
  int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize) {
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->Top1 = -1;
  S->Top2 = MaxSize;
  S->MaxSize = MaxSize;
  return S;
}

bool Push(Stack S, ElementType X, int Tag) {
  if (S->Top2 - S->Top1 == 1) {
    printf("STACK IS FULL");
    return false;
  } else {
    if (Tag == 1) {
      S->Data[++(S->Top1)] = X;
    } else {
      S->Data[--(S->Top2)] = X;
    }
    return true;
  }
}

ElementType Pop(Stack S, int Tag) {
  if (Tag == 1) {
    if (S->Top1 == -1) {
      printf("STACK1 IS EMPTY");
      return -1;
    } else {
      return S->Data[(S->Top1)--];
    }
  } else {
    if (S->Top2 == S->MaxSize) {
      printf("STACK2 IS EMPTY");
      return -1;
    } else {
      return S->Data[(S->Top2)++];
    }
  }
}

void PrintStack(Stack S, int Tag) {
  if (Tag == 1) {
    for (int i = 0; i <= S->Top1; i++) {
      printf("%d ", S->Data[i]);
    }
  } else {
    for (int i = S->MaxSize-1; i >= S->Top2; i--) {
      printf("%d ", S->Data[i]);
    }
  }
  printf("\n");
}

int main() {
  Stack S = CreateStack(10);
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {10, 9, 8, 7, 6};

  for (int i = 0; i < 5; i++) {
    Push(S, arr1[i], 1);
    Push(S, arr2[i], 2);
  }

  PrintStack(S, 1);
  PrintStack(S, 2);

  printf("%d\n", Pop(S, 1));
  printf("%d\n", Pop(S, 2));

}
