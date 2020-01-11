#define  _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
//ABD##E#H##CF##G##
test(){
	BTDataType arr[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	int pi = 0;
	BTNode *root = BinaryTreeCreate(arr,&pi);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	int k = BinaryTreeSize(root);
	printf("%d\n", k);
	BinaryTreeDestory(root);

}
int main()
{
	test();
	return 0;
}