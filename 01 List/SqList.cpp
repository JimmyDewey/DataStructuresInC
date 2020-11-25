#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 255
#define ERROR -1

typedef int Position;
typedef int ElementType;

typedef struct LNode * List;

List L;
//访问下标为 i 的元素：L->Data[i]
//线性表的长度：L->Last+1

// 初始化顺序表
List MakeEmpty(); 

// 返回与X相等的数据元素的存储下标
int Find(List L, ElementType X);  

// 在指定位置插入元素X
bool Insert(List L, ElementType X, Position i); 

// 删除指定位置的元素
bool Delete(List L, Position i); 

// 查找在第K个位置第元素，并把它返回
ElementType FindKth(List L, Position K);

// 返回顺序线性表的长度
int Length(List L); 

struct LNode {
  ElementType Data[MAXSIZE];

  Position Last;
};

List MakeEmpty() {
  List L;
  L = (List)malloc(sizeof(struct LNode));
  L->Last = -1;
  return L;
}

int Find(List L, ElementType X) {
  Position i = 0;

  while (i < L->Last && L->Data[i] != X) {
    i++;
  }

  return i > L->Last ? ERROR : i;
}

bool Insert(List L, ElementType X, Position i) {
  Position j;

  // 如果表满，则不能插入
  if (L->Last+1 > MAXSIZE) {
    printf("顺序列表已满，不可插入\n");
    return ERROR;
  }

  if (i < 1 || i > L->Last+2) {
    printf("插入位序不合法\n");
    return ERROR;
  }

  for (j = L->Last; j > i; j--) {
    L->Data[j+1] = L->Data[j];
  }
  L->Data[i-1] = X;
  L->Last++;
  return true;
}

bool Delete(List L, Position i) {
  Position j;

  if (i < 1 || i > L->Last+1) {
    printf("位序%d 不存在元素", i);
    return ERROR;
  }

  for (j = i; j < L->Last; j++) {
    L->Data[j] = L->Data[j+1];
  }
  L->Last--;
  return true;
}

bool PrintSqList(List L) {
  if (L->Last < 0) {
    printf("列表异常\n");
    return ERROR;
  }
  for (int i = 0; i <= L->Last; i++) {
    printf("%d ", L->Data[i]);
  }
  printf("\n");
  return true;
}

ElementType FindKth(List L, Position K) {
  if (K < 1 || K > L->Last) {
    printf("位序不合法\n");
    return ERROR;
  }
  return L->Data[K];
}

int Length(List L) {
  return L->Last+1;
}

int main() {
  List L = MakeEmpty();

  int arr[] = {23, 13, 33, 44, 55, 42, 24, 94, 57, 26, 78, 22, 91, 32};

  for (int i = 0; i < 14; i++) {
    Insert(L, arr[i], i + 1);
  }
  PrintSqList(L);

  Delete(L, 1);
  PrintSqList(L);

  printf("%d\n", FindKth(L, 6));

  printf("%d\n", Length(L));


  return 0;
}
