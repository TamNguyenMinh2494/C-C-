// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct Stack
{
	int top;
	char a[MAX];
};
void Initialize(Stack &s)
{
	s.top = 0;
}
bool IsEmpty(Stack s)
{
	if (s.top == 0) return true;
	return false;
}
bool IsFull(Stack s)
{
	if (s.top == MAX) return true;
	return false;
}
char Pop(Stack &s)
{
	char x;
	if (!IsEmpty(s))
	{
		x = s.a[s.top - 1];
		s.top--;
	} return x;
}
bool Push(Stack &s, char x)
{
	if (IsFull(s)) return false;
	s.a[s.top] = x;
	s.top++;
	return true;
}
char getTop(Stack &s)
{
	char x;
	if (!IsEmpty(s))
	{
		x = s.a[s.top - 1];
	} return x;
}
int HauTo(char O1)
{
	switch (O1)
	{
	case '(': return 0;
	case '+':case '-': return 1;
	case '*':case '/': return 2;
	default:
		break;
	}
}
void main()
{
	Stack s;
	Initialize(s);
	char n[20];
	cout << "Nhap bieu thuc: " << endl;
	gets_s(n);
	char ans[20];
	int j = 0;
	for (int i = 0; i < strlen(n); i++)
	{
		if (n[i] >= '0' && n[i] <= '9')
		{
			ans[j] = n[i];
			j++;
		}
		else if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/')
		{
			{
				while (!IsEmpty(s) && HauTo(n[i]) <= HauTo(getTop(s)))
				{
					ans[j] = Pop(s);
					j++;
				}Push(s, n[i]);
			}
		}
		else if (n[i] = ')')
		{
			char c;
			do {
				c = Pop(s);
				if (c != '(')
				{
					ans[j] = c;
					j++;
				}
				else break;
			} while (1);
		}
	}
	while (!IsEmpty(s))
	{
		ans[j] = Pop(s);
		j++;
	}
	ans[j] = '\0';
	puts(ans);
	_getch();
}

