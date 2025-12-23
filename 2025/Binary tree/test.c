#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

/*
A
B C
D E F G
*/


void test()
{
	char a[] = "ABD##E#H##CF##G##";//ABD##E##CF##G##
	int i = 0;
	BTNode* ret = BinaryTreeCreate(a, &i);
	BinaryTreeLevelOrder(ret);
	//BinaryTreePrevOrder(ret);
	//printf("\n");
	//BinaryTreeInOrder(ret);
	//printf("\n");
	//BinaryTreePostOrder(ret);
	//printf("\n");
	//printf("%d\n", BinaryTreeSize(ret));
	//printf("%d\n", BinaryTreeLeafSize(ret));
	//printf("%d\n", BinaryTreeLevelKSize(ret, 2));
	//BTNode* find = BinaryTreeFind(ret, 'G');
	//printf("%c", find->_data);
}


int main()
{
	test();
	return 0;
}


/*
ABD##E#H##CF##G##

                     A
			B                     C
		D       E             F         G
	#   #    #     H      #      #  #       #
	           #      #




*/