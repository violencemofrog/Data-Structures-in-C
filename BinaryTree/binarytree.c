// binarytree.c

#include "binarytree.h"

// 判断树是否为空（空树返回true）
bool tree_isempty(TreeNode root) {
	if(root)
		return false;
	else
		return true;
}

// 销毁树
void tree_clear(TreeNode root) {
	if(root) {
		tree_clear(root->left);
		tree_clear(root->right);
		free(root);
	}
}