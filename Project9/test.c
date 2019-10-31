#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//printf  小数点后6位 
int IsPowTow1(int n)
{
	int i = 0;
	for (i = 1; i <= n; i <<= 1)
	{
		if (i == n)
		{
			return 1;
		}
	}
	return 0;
}
int IsPowTow(int n)
{
	int m = n&(n - 1);
	if (n < 1)
	{
		return 0;
	}
	if (m == 0)
	{
		return 1;
	}
	return 0;
}
void Compress1(char *str)
{
	int i = 0;
	int count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			if (count != 1)
				printf("%d", count);

			printf("%c", str[i]);
			count = 1;
		}
		i++;
	}
}

void Compress(char *str)
{
	int i = 0;
	int j = 0;
	int count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			str[j++] = count + '0';//9
			str[j++] = str[i];
			count = 1;
		}
		i++;
	}
	str[j] = '\0';
}

void DelBlank(char *str)
{
	int flg = 0;//还没开始处理空格
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && !flg)
		{
			i++;
		}
		else if (str[i] != ' ' && !flg)
		{
			str[j++] = str[i++];
			flg = 1;
		}
		else if (str[i] == ' ' && flg)
		{
			str[j++] = str[i++];
			flg = 0;
		}
		else
		{
			str[j++] = str[i++];
		}
	}
	if (str[j - 1] == ' ')
	{
		str[j - 1] = '\0';
	}
	else
	{
		str[j] = '\0';
	}
}

int main()
{
	char str[] = "    abc   d  e     f     ";
	DelBlank(str);//2a3b2ac2d
	printf("%s", str);

	return 0;
}