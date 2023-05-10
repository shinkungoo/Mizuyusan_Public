#ifndef DATASTRUCTURE_AVL_TREE_H
#define DATASTRUCTURE_AVL_TREE_H
#include <stdio.h>
#include <stdbool.h>

typedef int keyType;
typedef int valType;
typedef struct AVLTreeNode * Tree;
typedef struct AVLTreeNode * Position;
typedef struct AVLTreeNode * Ptr;

struct AVLTreeNode{
    keyType key;
    valType val;
    Ptr left, right, parent;
    int height;
    bool isInit;
};

Position CreateNode(keyType key, valType val, int height)
{

}



void Test(){
    printf("test\n");
};
#endif //DATASTRUCTURE_AVL_TREE_H
