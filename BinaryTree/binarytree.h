// binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct treenode {
	ElementType data;
	struct treenode* right;
	struct treenode* left;
} Node;
typedef Node* TreeNode;


bool tree_isempty(TreeNode);
void tree_preordertraverse(TreeNode,void (*)(Node*));
void tree_inordertraverse(TreeNode,void (*)(Node*));
void tree_postordertraverse(TreeNode,void (*)(Node*));
void tree_levelordertraverse(TreeNode,void (*)(Node*));
void tree_clear(TreeNode);

#endif