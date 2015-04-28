#include "xcept.h"
#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include "Stack.h"
const int maxlength=100;
void print(char *expr)
{
	Stack<int> s(maxlength);
	int j,length=strlen(expr);
	for (int i=1;i<=length;i++)
	{
		if(expr[i-1]=='(') s.Add(i);
		else if(expr[i-1]==')')
			try
			{
				s.Delete(j);
				cout<<j<<' '<<i<<endl;
			}
			catch(OutOfBounds)
			{cout<<"No match...     "<<"at"<<i<<endl;}
	}
	while(!s.IsEmpty())
	{
		s.Delete(j);
		cout<<"No match..."<<j<<endl;
	}
}


void main()
{
	char expr[maxlength];
	cin.getline(expr,maxlength);
	puts(expr);
	cout<<"are"<<endl;
	print(expr);
}