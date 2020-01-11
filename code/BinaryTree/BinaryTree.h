#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);//����������
void BinaryTreeDestory(BTNode* root);//���ٶ�����
void BinaryTreeDestory1(BTNode** root);
int BinaryTreeSize(BTNode* root);//���ĳ���
int BinaryTreeLeafSize(BTNode* root);//Ҷ����
int BinaryTreeLevelKSize(BTNode* root, int k);//ÿ��ڵ���
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//����
//�ݹ����
void BinaryTreePrevOrder(BTNode* root);// ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������
// �ǵݹ����
void BinaryTreeLevelOrder(BTNode* root);// �������
int BinaryTreeComplete(BTNode* root);// �ж϶������Ƿ�����ȫ������
void BinaryTreePrevOrderNonR(BTNode* root);//ǰ�����
void BinaryTreeInOrderNonR(BTNode* root);//�������
void BinaryTreePostOrderNonR(BTNode* root);//�������
