#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

//��ע�⣬���صĹ淶·������ʼ����б�� / ��ͷ����������Ŀ¼��֮�����ֻ��һ��б�� / �����һ��Ŀ¼����������ڣ������� / ��β�����⣬�淶·�������Ǳ�ʾ����·��������ַ�����
//
//ʾ�� 1��
//
//���룺"/home/"
//�����"/home"
//���ͣ�ע�⣬���һ��Ŀ¼������û��б�ܡ�
//ʾ�� 2��
//
//���룺"/��/"
//�����"/"
//���ͣ��Ӹ�Ŀ¼����һ���ǲ����еģ���Ϊ��������Ե������߼���
//ʾ�� 3��
//
//���룺"/home//foo/"
//�����"/home/foo"
//���ͣ��ڹ淶·���У��������б����Ҫ��һ��б���滻��
//ʾ�� 4��
//
//���룺"/a/./b/��/��/c/"
//�����"/c"
//ʾ�� 5��
//
//���룺"/a/��/��/b/��/c//.//"
//�����"/c"
//ʾ�� 6��
//
//���룺"/a//b////c/d//././/��"
//�����"/a/b/c"
//2018-12-27
//2018-12-28   "/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./"
//2018-12-29   "/...",    "/.",   "/.."
char* simplifyPath(char* path) {
	typedef struct stack
	{
		char character[1000];
		int top;
	}stack;
	char *newpath;
	int i = 0;
	int dotcount = 0;
	stack *s1 = (stack *)malloc(sizeof(stack));
	memset(s1, 0, sizeof(stack));
	if (path[0] == '\0')
	{
		return NULL;
	}
	while (path[i] != '\0')
	{
		switch (path[i])
		{
		case '/':
			if (dotcount == 1 && s1->character[s1->top - 1] == '.')
			{
				dotcount = 0;
				s1->top -= 1;
				if (s1->character[s1->top - 1] != '/')
				{
					s1->character[s1->top] = path[i];
					s1->top++;
					i++;
					break;
				}
				else
				{
					i++;
					break;
				}
			}
			else if (dotcount == 2 && s1->character[s1->top - 1] == '.')
			{

				dotcount = 0;
				s1->top -= 2;


				if (s1->top == 1 && s1->character[s1->top - 1] == '/')
				{
					i++;
					break;
				}
				s1->top -= 1;
				while (s1->top>0 && s1->character[s1->top - 1] != '/')
				{
					s1->top--;
				}
				if (s1->character[s1->top - 1] != '/')
				{
					s1->character[s1->top] = path[i];
					s1->top++;
					i++;
					break;
				}
				else
				{
					i++;
					break;
				}
			}
			else
			{
				if (s1->top>0)
				{
					if (s1->character[s1->top - 1] == '/')
					{
						i++;
						break;
					}
				}
				s1->character[s1->top] = path[i];
				s1->top++;
				i++;
				break;
			}
		case '.':
			dotcount++;
			//i++;˳�����
			s1->character[s1->top] = path[i];
			i++;
			s1->top++;
			break;
		default:
			dotcount = 0;
			s1->character[s1->top] = path[i];
			s1->top++;
			i++;
			break;
		}
	}

	if (s1->top>1)
	{
		if (dotcount == 2 && s1->character[s1->top - 1] == '.')
		{
			dotcount = 0;
			s1->top -= 2;
			if (s1->top>1 && s1->character[s1->top - 1] == '/')
			{
				s1->top -= 1;
				while (s1->top>0 && s1->character[s1->top - 1] != '/')
				{
					s1->top--;
				}
			}
		}
		if (dotcount == 1 && s1->character[s1->top - 1] == '.')
		{
			dotcount = 0;
			s1->top -= 1;
		}
		if (s1->top>1 && s1->character[s1->top - 1] == '/')
		{
			s1->top--;
		}


	}
	newpath = (char *)malloc(sizeof(char)*(s1->top + 20));//������ֽ�����������
	strncpy(newpath, s1->character, s1->top);//�����������������ַ���
	newpath[s1->top] = '\0';//�ֶ���ӽ�����
	return newpath;
}

int main()
{
	//char *p ="/";���ʹ���ָ����ַ���泣��
	char p[] = "/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./";//"/";
	char *path = simplifyPath(p);
	printf("%sthe length is %d\n", path, strlen(path));
	system("pause");
	return 0;
}
