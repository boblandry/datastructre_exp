#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;//����DataTypeΪ����
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 45
#define MaxWeight  10000  //���������ľ���ֵ
#define MaxQueueSize 100
#include "AdjMGraph.h"
#include"AdjMGraphCreate.h"
#include"AdjMGraphTraverse.h"
#include"AdjLGraph.h"
#include"AdjLGraphCreate.h"
void main()
{
	AdjMGraph g1; //����һ���ڽӾ���洢�ṹ��ͼg1
	RowColWeight rcw[MaxEdges];//�������Ϣ����
	int n,e,i;//int j;
	printf("���������Ŀ����Ϊ��ʵ��ͼ�Ļ�������\n");
	printf("����������ͼ�Ķ�����:");
	scanf("%d",&n);

	printf("����������ͼ�ı���:");
	scanf("%d",&e);
	
	DataType a[MaxVertices];//����洢��������Ϊ����
	printf("��ͼ��%d������ֱ�Ϊ:",n);
	//���ÿ�������ַ�
	for(i=0;i<n;i++)
	{
		a[i]=i;
		printf("%2d",a[i]);
	}
	printf("\n");
	
	//�洢�ߵ���Ϣ
	for(i=0;i<e;i++)
	{
		printf("������һ���������Ķ���v1,v2��Ȩֵ(v1,v2,w):");
		scanf("%d%d%d",&rcw[i].row,&rcw[i].col,&rcw[i].weight);
	}

	CreatGraph(&g1,a,n,rcw,e);//����һ���ڽӾ���洢�ṹ��ͼg1
	printf("��ͼ���ڽӾ���Ϊ:\n");
	Print(&g1);//���ͼg1���ڽӾ���
	
	printf("---------------------------------------------------\n");
    //����ڽӾ���洢�ṹ��ͼg1��ÿ������Ķ�
	MVertices(&g1,a);

	printf("---------------------------------------------------\n");
	AdjLGraph g2;//����һ���ڽӱ�洢�ṹ��ͼg2
	RowCol rwc[MaxEdges];//�������Ϣ����
	//���ڽӾ��������ڽӱ�
	for(i=0;i<e;i++)
	{
		rwc[i].col=rcw[i].col;
		rwc[i].row=rcw[i].row;
	}
	CreatLGraph(&g2,a,g1.Vertices.size,rwc,g1.numOfEdges);
	printf("�ڽ�����\n");
	print(&g2);
	//����ڽӱ�洢�ṹ��ͼg2ÿ������Ķ�
    //LVertices(&g2,a);


	
	printf("---------------------------------------------------\n");
	// ���ֱ���
	printf("������ȱ�������Ϊ(�����뿪ʼ����):");//DFS
	int zz;
	scanf("%d", &zz);
	DepthFirstSearch(g1,zz);
	printf("\n");
	printf("������ȱ�������Ϊ(�����뿪ʼ����):");//BFS
	scanf("%d", &zz);
	BroadFirstSearch(g1,zz);
    printf("\n");
	

	printf("---------------------------------------------------\n");
	//���붥��x,����ͼg1:�����ں�x�Ķ���,��ɾ���ý�㼰��֮������ı�,
	//����DFS�������������Ϣ"��x";
	int x;
	printf("������Ҫ���ҵĶ���:");
	scanf("%d",&x);
	if(ChaZhao(&g1,x))
	{
		MDelete(&g1,x);
		printf("ɾ������%d���ͼ���ڽӾ���Ϊ:\n",x);
		Print(&g1);
		printf("ɾ������%d���������ȱ�������Ϊ(�����뿪ʼ����):",x);
		scanf("%d", &zz);
		DepthFirstSearch(g1,zz);
		printf("\n");
	}
	else
		printf("��%d\n",x);
	
	printf("---------------------------------------------------\n");
	



	//�ж�ͼg1����ͨ��
	printf("ͼg1�Ƿ�Ϊǿ��ͨͼ:\n");
	if(LianTong(&g2,a))
		printf("YES\n");
	else
		printf("NO\n");	
	//printf("11111\n");


	
	printf("�������鵽�˽���!");
}
