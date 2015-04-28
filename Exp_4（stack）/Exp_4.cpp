#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include "Stack.h"
#include "xcept.h"
const int MaxLength = 100;

//在change方法中扫描到）且栈顶为（时视为不合法!!!
double calculate(char *str)
{
	Stack<char> s(MaxLength);
	char j;
	char newstr[MaxLength];
	int length=strlen(str);int count=0;
	s.Add('#');
	for (int i =1;i<=length;i++)
	{
		//扫描到数字
		if (str[i-1]=='0'||str[i-1]=='1'||str[i-1]=='2'||str[i-1]=='3'||
			str[i-1]=='4'||str[i-1]=='5'||str[i-1]=='6'||str[i-1]=='7'||str[i-1]=='8'||str[i-1]=='9')
		{
			newstr[count]=str[i-1];
			count++;
		}	
		//扫描到的操作符为+或者-
		else if (str[i-1]=='+'||str[i-1]=='-')
		{
			j=s.Top();
			while(j=='+'||j=='-'||j=='*'||j=='/')
			{
				s.Delete(j);
				newstr[count]=j;
				count++;
				j=s.Top();
			}
			j=s.Top();
			if(j=='('||j=='#')
				s.Add(str[i-1]);
			else 
			{
				cout<<"输入的表达式非法！"<<endl;
				return 0;
			}
		}
		//扫描到的操作符为*或者/
		else if (str[i-1]=='*'||str[i-1]=='/')
		{
			j=s.Top();
			while(j=='*'||j=='/')
			{
				s.Delete(j);
				newstr[count]=j;
				count++;
				j=s.Top();
			}
			j=s.Top();
			if(j==')')
				s.Delete(j);
			else if(j=='('||j=='#'||j=='+'||j=='-')
				s.Add(str[i-1]);
			else 
			{
				cout<<"输入的表达式非法！"<<endl;
				return 0;
			}
		}
		//扫描到的操作符为（
		else if (str[i-1]=='(')
		{
			j=s.Top();
			if(j=='+'||j=='-'||j=='*'||j=='/'||j=='('||j=='#')
				s.Add(str[i-1]);
			else if (j==')')
				s.Delete(j);
		}
		//扫描到的操作符为）
		else if (str[i-1]==')')
		{	
			j=s.Top();
			while(j=='+'||j=='-'||j=='*'||j=='/')
			{
				s.Delete(j);
				newstr[count]=j;
				count++;
				j=s.Top();
			}
			j=s.Top();
			if(j==')'||j=='(')
				s.Delete(j);
			else 
			{
				cout<<"输入的表达式非法！"<<endl;
				return 0;
			}
		}	
	}//for循环结束
	
	while(s.Top()!='#')
	{
		j=s.Top();
		if(j=='+'||j=='-'||j=='*'||j=='/')
		{
			s.Delete(j);
			newstr[count]=j;
			count++;
			j=s.Top();
		}
		else if(j==')')
			s.Delete(j);
		else 
		{
			cout<<"输入的表达式非法！"<<endl;
			return 0;
		}
	}//中缀表达式转换成后缀表达式结束！

	//开始计算
	int m,n,ans;
	Stack<int> s2(MaxLength);
	for (int k=0;k<count;k++)
	{
		if(newstr[k]=='0') s2.Add(0);
		else if(newstr[k]=='1') s2.Add(1);
		else if(newstr[k]=='2') s2.Add(2);
		else if(newstr[k]=='3') s2.Add(3);
		else if(newstr[k]=='4') s2.Add(4);
		else if(newstr[k]=='5') s2.Add(5);
		else if(newstr[k]=='6') s2.Add(6);
		else if(newstr[k]=='7') s2.Add(7);
		else if(newstr[k]=='8') s2.Add(8);
		else if(newstr[k]=='9') s2.Add(9);

		if(newstr[k]=='+')
		{
			s2.Delete(m);
			s2.Delete(n);
			ans=m+n;
			s2.Add(ans);
		}
		else if(newstr[k]=='-')
		{
			s2.Delete(m);
			s2.Delete(n);
			ans=n-m;
			s2.Add(ans);
		}
		else if(newstr[k]=='*')
		{
			s2.Delete(m);
			s2.Delete(n);
			ans=m*n;
			s2.Add(ans);
		}
		else if(newstr[k]=='/')
		{
			s2.Delete(m);
			s2.Delete(n);
			ans=n/m;
			s2.Add(ans);
		}
	}
	s2.Delete(ans);
	if (s2.IsEmpty())
		return ans;
	else 
	{
		cout<<"输入的表达式非法！"<<endl;
		return 0;
	}
}


void main()
{
	char str[MaxLength+1];
	cout<<"Input"<<endl;

	cin.getline(str,MaxLength);
		cout<<"Output"<<endl;

	cout<<calculate(str)<<endl;
		cout<<"End"<<endl;
}