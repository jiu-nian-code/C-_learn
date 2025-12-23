#include"BinaryTree.h"



BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[(*pi)] == '#' || !a)
	{
		++(*pi);
		return NULL;
	}
	BTNode* newnode = (BTNode*)calloc(1, sizeof(BTNode));
	newnode->_data = a[(*pi)++];
	newnode->_left = BinaryTreeCreate(a, pi);
	newnode->_right = BinaryTreeCreate(a, pi);
	return newnode;
}

void BinaryTreeDestory(BTNode** root)
{
	if (!*root)
		return;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (!root)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	if (!root->_left && !root->_right)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	--k;
	if (!root)
	{
		return 0;
	}
	if (k == 0)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k) + BinaryTreeLevelKSize(root->_right, k);
}

//int BTLKSize(BTNode* root, int* k)
//{
//	--*k;
//	if (*k == 0)
//		return 1;
//	int ck = *k;
//	return BTLKSize(root->_left, &ck) + BTLKSize(root->_right, k);
//}
 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;
	return BinaryTreeFind(root->_right, x);
}

void BinaryTreePrevOrder(BTNode* root)//Ç°
{
	if (!root)
	{
		printf("# ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)//ÖÐ
{
	if (!root)
	{
		printf("# ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)//ºó
{
	if (!root)
	{
		printf("# ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	if (!root)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* curr = QueueFront(&q);
		printf("%c ", curr->_data);
		QueuePop(&q);
		if(curr->_left)
			QueuePush(&q, curr->_left);
		if(curr->_right)
			QueuePush(&q, curr->_right);
	}
	QueueDestory(&q);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode* cur;
	int tag = 0;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->_data);
		if (cur->_right && !cur->_left)
			return 0;
		if (tag && (cur->_right || cur->_left))
			return 0;
		if (cur->_left)
			QueuePush(&qu, cur->_left);
		if (cur->_right)
			QueuePush(&qu, cur->_right);
		else
			tag = 1;
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}