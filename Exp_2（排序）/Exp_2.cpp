#include<iostream>
using namespace std;
#define for if(false){}else for

//ѡ�������㷨
void SelectSort(int list[],int n)
{
	int i,j,k;
	int x;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(list[j]<list[k])  k=j;
		if(i!=k)
		{
			x=list[i];
			list[i]=list[k];
			list[k]=x;
			for (int j=0; j<n; j++)
			cout<<list[j]<<"  ";
		cout<<endl;
		}	
	}
}

//ð�������㷨
void BubbleSort(int list[], int n)
{
	int m,i=0,j,flag=1; //��flagΪ0��ֹͣ����
	int x;
	m=n-1;//m��ʾ����
	while((m>0)&&(flag==1))
	{ 
		flag=0; //��ʼʱԪ��δ����
		for(j=0; j<m; j++)
			if(list[j]>list[j+1])
			{ //�������� 
				flag=1;
				x=list[j];
				list[j]=list[j+1];
				list[j+1]=x;
				
				for (int j=0; j<n; j++)
					cout<<list[j]<<"  ";
				cout<<endl;
			} //����������Ƿ����˽���
		m--;
	}
}

//���������㷨
void InsertSort(int list[], int n)
{
	int j;
    for(int i=1;i<n;i++)  //i��ʾ���������������n-1�β���
		if(list[i]<list[i-1])   //��list[i]���뵽������list[0],��,list[i-1]�У�
		//��a[i]<a[i-1]
		{
		int x=list[i];   //�Ѵ�����Ԫ�ظ��� x
		//��a[i-2]��ʼ�Ƚ�
		for(int j=i-1; (x<list[j])&&(j>=0); j--)
			list[j+1]=list[j]; //��list[i-1]��ʼ����һλ		
		list[j+1]=x;//ֱ���ҵ�һ��Ԫ�أ����뵽��ȷλ�� 
		
		for (int k=0; k<n; k++)
			cout<<list[k]<<"  ";
		cout<<endl;
	}
}

//���������㷨
//������Ҫ������������
int maxBit(int list[],int size)
{
    int maxNum = 0;
    int counts = 0;
    for(int i = 1; i < size; i++)
    {
        if(list[maxNum] < list[i])
            maxNum = i;
    }
    int maxNumber = list[maxNum];
    while(maxNumber != 0)
    {
        counts++;
        maxNumber = maxNumber/10;
    }
    return counts;
}

void radixSort(int list[],int size)
{
    int maxB = maxBit(list,size);
    int *bin = new int[10];
    int *temp = new int[size];
    int radix = 1;

    //cout << "-----------------------" << endl;
	//����� ���ж��ٴ���������
    for(int i = 0; i < maxB; i++)
    {
		//��ʼ��
        for(int j = 0; j <10; j++)
            bin[j] = 0;
		//��¼����
	
        for(int k = 0; k < size; k++)
        {
            int x = list[k]/radix%10;
            bin[x]++;
        }
	
        for(int j = 1; j < 10; j++)
        {
            bin[j] = bin[j] + bin [j - 1];
        }
		
        for(int k = size-1; k >= 0; k--)
        {
            int x = list[k]/radix%10;
            temp[bin[x]-1] = list[k];
            bin[x]--;
        }
		
        for(int k = 0; k < size; k++)
            list[k] = temp[k];
        //cout << "��" << (i+1) << "�Σ�";
		//�������
        for(int i = 0; i < size; i++)
			cout << list[i] << "  ";
		cout << endl;
        radix *= 10;
    }
    delete [] bin;
    delete [] temp; 
}

//���������㷨
void qksort(int list[], int t, int w)
{
	int i, j;
	int x;
	if(t>=w)  
		return;
	i=t; j=w; x=list[i];
	while(i<j)
	{
		while((i<j)&&(list[j]>=x))  
			j--;
		if(i<j) 
		{ 
			list[i]=list[j]; 
			i++; 
		}
		while((i<j)&&(list[i]<=x))  
			i++;
		if(i<j) 
		{ 
			list[j]=list[i]; 
			j--; 
		}
	}
	list[i]=x;
	qksort(list,t,j-1);
	qksort(list,j+1,w);
}
//�鲢�����㷨
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
	cout<<"��ѡ������ʽ��������1��2��3��4��5����һ�ּ��ɣ�"<<endl;
	cout<<"1.ѡ������"<<endl;
	cout<<"2.ð������"<<endl;
	cout<<"3.��������"<<endl;
	cout<<"4.��������"<<endl;
	cout<<"5.��������"<<endl;
	int n;
	cin>>n;
	if (n==1)
		SelectSort(list,size);
	else if(n==2)
		BubbleSort(list,size);
	else if(n==3)
		InsertSort(list,size);
	else if(n==4)
		radixSort(list,size);
	else if(n==5)
	{
		cout<<"��������..."<<endl;
		qksort(list, 0, size-1);
	}
	else cout<<"�����޷�ʶ�������³���..."<<endl;
	cout<<"���ս��Ϊ��"<<endl;
	for(int i = 0; i < size; i++)
			cout << list[i] << "  ";
		cout << endl;
}
