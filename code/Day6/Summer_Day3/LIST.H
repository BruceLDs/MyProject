#ifndef __LIST_H__
#define __LIST_H__
//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *pList;

//初始化
void InitList(pList plsit);
Node *GetNode(int val);
//头插
void InsertHead(pList plist, int val);
//尾插
void InsertTail(pList plist, int val);
//打印
void Show(pList plist);
void Show1(pList plist);
//任意位置插入
Node *LastNode(pList plist, int k);//倒数第k个节点
//删除
void Delete(pList plist, int k);
//逆置
void InverseList(pList plist);
Node* ReverseLink(pList plist);
//查找
Node *FindMidleNode(pList plist);
#endif