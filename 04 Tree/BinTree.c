#include <stdio.h>
#include <stdlib.h>

#define NoInfo 0

typedef int ElementType;

typedef struct TNode *Position;

typedef Position BinTree;

struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};

// 中序遍历（递归）
void InorderTraversalRecursion(BinTree BT) {
  if (BT) {
    InorderTraversal(BT->Left);
    printf("%d", BT->Data);
    InorderTraversal(BT->Right);
  }
}

// 先序遍历（递归）
void PreorderTraversalRecursion(BinTree BT) {
  if (BT) {
    printf("%d", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
  }
}

// 后序遍历（递归）
void PostorderTraversalRecursion(BinTree BT) {
  if (BT) {
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf("%d", BT->Data);
  }
}

void InorderTraversal(BinTree BT) {
  BinTree T;
  Stack S = CreateStack();

}
