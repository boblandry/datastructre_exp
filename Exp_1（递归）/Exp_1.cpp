#include<iostream>
using namespace std;

//����������
void Swap(int &a, int &b)
{
	int i=b;
	b=a;
	a=i;
}

//���õݹ�ȫ����
void Perm(int list[], int k, int m)
{
	int i;
	if (k==m)
	{
		for (i=0; i<=m; i++)
			cout<<list[i]<<"    ";
		cout<<endl;
	}
	else
		for (i=k; i<=m; i++)
		{
			Swap(list[k], list[i]);
			Perm(list, k+1, m);
			Swap(list[k], list[i]);
		}
}



//������
void main()
{
	int size;
	cout<<"���������:"<<endl;
	cin>>size;
	int *list = new int[size];
	cout<<"������..."<<endl;
	for (int i=0; i<size; i++)
		cin>>list[i];
	cout<<"ȫ����Ϊ:"<<endl;
	Perm(list,0,size-1);
	cout<<"�Ӽ�Ϊ:"<<endl<<"{��}"<<endl;
	for(i=1; i<=size; i++)
		cout<<"{"<<list[i-1]<<"} ";
	cout<<endl;

	int num=0;
	for(i=2; i<=size; i++)
	{
		int temp=1;
		while(temp+i-1<=size)
		{
			int s=temp+1;
			
			while(s+i-2<=size)
			{
				cout<<"{ ";
				cout<<list[temp-1]<<" ";
				for(int cur=s; cur<s+i-1; cur++)
					cout<<list[cur-1]<<" ";
				cout<<"}    ";
				s+=1;
			}
			temp++;
		}
		cout<<endl;
	}
}