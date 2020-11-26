#include <stdio.h>
#include <stdlib.h>

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode {
  ElementType Data;
  PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

int Length(List L) {
  Position p;
  int count = 0;

  p = L;
  while(p) {
    count++;
    p = p->Next;
  }

  return count;
}

ElementType FindKth(List L, int K) {
  Position p;
  int count = 1;
  p = L->Next;
  
  while(p && count < K) {
    p = p->Next;
    count++;
  }

  if ((count == K) && p) {
    return p->Data;
  } else {
    return -1;
  }
}

Position Find(List L, ElementType X) {
  Position p = L->Next;
  while (p && p->Data != X) {
    p = p->Next;
  }
  return p;
}

bool Insert(List L, ElementType X, int i) {
  Position tmp, pre;
  int count = 0;

  pre = L;
  while (pre && count < i-1) {
    pre = pre->Next;
    count++;
  }
  if (pre == NULL || count != i-1) {
    printf("INSERT ERROR\n");
    return false;
  } else {
    tmp = (Position)malloc(sizeof(struct LNode));
    tmp->Data = X;
    tmp->Next = pre->Next;
    pre->Next = tmp;
    return true;
  }

}

bool Delete(List L, int i) {
  Position tmp, pre;
  int count = 0;

  pre = L;
  while (pre && count < i-1) {
    pre = pre->Next;
    count++;
  }
  if (pre == NULL || count != i-1 || pre->Next == NULL) {
    printf("DELETE ERROR\n");
    return false;
  } else {
    tmp = pre->Next;
    pre->Next = tmp->Next;
    free(tmp);
    return true;
  }
}

void PrintList(List L) {
  if (!L || !L->Data || !L->Next) return;
  Position p;
  p = L->Next;
  while (p) {
    printf("%d ", p->Data);
    p = p->Next;
  }
  printf("\n");
}


int main() {
  int arr[] = {12, 99, 9, 1323, 42, 45, 6, 24, 91, 67};

  List L = (List)malloc(sizeof(struct LNode));
  L->Data = 10;

  for (int i = 0; i < L->Data; i++) {
    Insert(L, arr[i], i+1);
  }
  PrintList(L);

  Position p = Find(L, 42);
  printf("%d\n", p->Data);

  printf("%d\n", FindKth(L, 9));

  Delete(L, 1);
  PrintList(L);

  return 0;
}
