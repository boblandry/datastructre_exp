#include<iostream>
using namespace std;
#include "List.h"
#include "xcept.h"

int main()
{
	//����һ��������в���
	Chain<int> x;
	int a=10,b=25,c=8,d=33,e=60;
	x.append(a);x.append(b);x.append(c);x.append(d);x.append(e);
	cout<<"������Ϊ��"<<x<<endl;
	//��������һ������
	int size1;
	cout<<"������Ҫ���뼸������"<<endl;
	cin>>size1;
	int *list1 = new int[size1];
	Chain<int> X;
	for (int j=0;j<size1;j++)
	{
		cin>>list1[j];
		X.append(list1[j]);
	}
	cout<<"�������������Ϊ��"<<X<<endl;
	//Ѱ��
	cout<<"33�ڵ�"<<x.search(33)<<"��λ�á�"<<endl;
	//���Ա������Ĺ���
	cout<<"���Ա�������"<<endl;
	Chainiterator<int> z;
	int *y;
	y=z.initialize(x);
	while(y)
	{
		cout<<*y<<" ";
		y = z.Next();
	}
	cout<<endl;
	//ʹ�ñ�������������ķ������
	cout<<"����������Ϊ��"<<endl;
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
	//����������������ʹ�ñ�����ʵ������ĺϲ�
	//����1
	Chain<int> x1;
	int a1=10,b1=25,c1=26,d1=33,e1=60;
	x1.append(a1);x1.append(b1);x1.append(c1);x1.append(d1);x1.append(e1);
	cout<<"�½���������1Ϊ��"<<x1<<endl;
	//����2
	Chain<int> x2;
	int a2=1,b2=8,c2=12,d2=34,e2=65;
	x2.append(a2);x2.append(b2);x2.append(c2);x2.append(d2);x2.append(e2);
	cout<<"�½���������2Ϊ��"<<x2<<endl;

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
	cout<<"�ϲ��������Ϊ��"<<x3<<endl;

	return 0;
}