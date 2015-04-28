#include<iostream>
using namespace std;
#include "List.h"
#include "xcept.h"

int main()
{
	//建立一个链表进行测试
	Chain<int> x;
	int a=10,b=25,c=8,d=33,e=60;
	x.append(a);x.append(b);x.append(c);x.append(d);x.append(e);
	cout<<"该链表为："<<x<<endl;
	//键盘输入一个链表
	int size1;
	cout<<"请问需要输入几个数？"<<endl;
	cin>>size1;
	int *list1 = new int[size1];
	Chain<int> X;
	for (int j=0;j<size1;j++)
	{
		cin>>list1[j];
		X.append(list1[j]);
	}
	cout<<"键盘输入的链表为："<<X<<endl;
	//寻找
	cout<<"33在第"<<x.search(33)<<"个位置。"<<endl;
	//测试遍历器的功能
	cout<<"测试遍历器："<<endl;
	Chainiterator<int> z;
	int *y;
	y=z.initialize(x);
	while(y)
	{
		cout<<*y<<" ";
		y = z.Next();
	}
	cout<<endl;
	//使用遍历器进行链表的反序输出
	cout<<"反序输出结果为："<<endl;
	int size=x.length();
	int *list = new int[size];
	Chainiterator<int> z1;
	int *y1;int count=0;
	y1=z1.initialize(x);
	while(y1)
	{
		list[count]=*y1;
		count++;
		y1 = z1.Next();
	}
	for (int i=size-1;i>=0;i--)
		cout<<list[i]<<" ";
	cout<<endl;
	//创建两个有序链表，使用遍历器实现链表的合并
	//链表1
	Chain<int> x1;
	int a1=10,b1=25,c1=26,d1=33,e1=60;
	x1.append(a1);x1.append(b1);x1.append(c1);x1.append(d1);x1.append(e1);
	cout<<"新建有序链表1为："<<x1<<endl;
	//链表2
	Chain<int> x2;
	int a2=1,b2=8,c2=12,d2=34,e2=65;
	x2.append(a2);x2.append(b2);x2.append(c2);x2.append(d2);x2.append(e2);
	cout<<"新建有序链表2为："<<x2<<endl;

	Chain<int> x3;
	Chainiterator<int> z2;
	int *y2;
	y2=z2.initialize(x1);
	Chainiterator<int> z3;
	int *y3;
	y3=z3.initialize(x2);
	while(y2&&y3)
	{
		//cout<<"----------"<<endl;
		if(*y2>*y3)
		{
			x3.append(*y3);
			y3=z3.Next();
		}
		else
		{
			x3.append(*y2);
			y2=z2.Next();
		}
	}
	if(y2)
	{
		while(y2)
		{
			x3.append(*y2);
			y2=z2.Next();
		}
	}
	else
	{
		while(y3)
		{
			x3.append(*y3);
			y3=z3.Next();
		}
	}
	cout<<"合并后的链表为："<<x3<<endl;

	return 0;
}