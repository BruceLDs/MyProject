#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

//请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 / 。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
//
//示例 1：
//
//输入："/home/"
//输出："/home"
//解释：注意，最后一个目录名后面没有斜杠。
//示例 2：
//
//输入："/…/"
//输出："/"
//解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
//示例 3：
//
//输入："/home//foo/"
//输出："/home/foo"
//解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
//示例 4：
//
//输入："/a/./b/…/…/c/"
//输出："/c"
//示例 5：
//
//输入："/a/…/…/b/…/c//.//"
//输出："/c"
//示例 6：
//
//输入："/a//b////c/d//././/…"
//输出："/a/b/c"
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
			//i++;顺序错误
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
	newpath = (char *)malloc(sizeof(char)*(s1->top + 20));//多分配字节留给结束符
	strncpy(newpath, s1->character, s1->top);//拷贝不带结束符的字符串
	newpath[s1->top] = '\0';//手动添加结束符
	return newpath;
}

int main()
{
	//char *p ="/";典型错误，指针存地址不存常量
	char p[] = "/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./";//"/";
	char *path = simplifyPath(p);
	printf("%sthe length is %d\n", path, strlen(path));
	system("pause");
	return 0;
}
