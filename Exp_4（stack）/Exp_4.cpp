#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include "Stack.h"
#include "xcept.h"
const int MaxLength = 100;

//��change������ɨ�赽����ջ��Ϊ��ʱ��Ϊ���Ϸ�!!!
double calculate(char *str)
{
	Stack<char> s(MaxLength);
	char j;
	char newstr[MaxLength];
	int length=strlen(str);int count=0;
	s.Add('#');
	for (int i =1;i<=length;i++)
	{
		//ɨ�赽����
		if (str[i-1]=='0'||str[i-1]=='1'||str[i-1]=='2'||str[i-1]=='3'||
			str[i-1]=='4'||str[i-1]=='5'||str[i-1]=='6'||str[i-1]=='7'||str[i-1]=='8'||str[i-1]=='9')
		{
			newstr[count]=str[i-1];
			count++;
		}	
		//ɨ�赽�Ĳ�����Ϊ+����-
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
				cout<<"����ı��ʽ�Ƿ���"<<endl;
				return 0;
			}
		}
		//ɨ�赽�Ĳ�����Ϊ*����/
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
				cout<<"����ı��ʽ�Ƿ���"<<endl;
				return 0;
			}
		}
		//ɨ�赽�Ĳ�����Ϊ��
		else if (str[i-1]=='(')
		{
			j=s.Top();
			if(j=='+'||j=='-'||j=='*'||j=='/'||j=='('||j=='#')
				s.Add(str[i-1]);
			else if (j==')')
				s.Delete(j);
		}
		//ɨ�赽�Ĳ�����Ϊ��
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
				cout<<"����ı��ʽ�Ƿ���"<<endl;
				return 0;
			}
		}	
	}//forѭ������
	
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
			cout<<"����ı��ʽ�Ƿ���"<<endl;
			return 0;
		}
	}//��׺���ʽת���ɺ�׺���ʽ������

	//��ʼ����
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
		cout<<"����ı��ʽ�Ƿ���"<<endl;
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