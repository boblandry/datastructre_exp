#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;//定义DataType为整形
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 45
#define MaxWeight  10000  //定义无穷大的具体值
#define MaxQueueSize 100
#include "AdjMGraph.h"
#include"AdjMGraphCreate.h"
#include"AdjMGraphTraverse.h"
#include"AdjLGraph.h"
#include"AdjLGraphCreate.h"
void main()
{
	AdjMGraph g1; //定义一个邻接矩阵存储结构的图g1
	RowColWeight rcw[MaxEdges];//定义边信息数组
	int n,e,i;//int j;
	printf("本次试验的目的是为了实现图的基本操作\n");
	printf("请输入有向图的顶点数:");
	scanf("%d",&n);

	printf("请输入有向图的边数:");
	scanf("%d",&e);
	
	DataType a[MaxVertices];//数组存储顶点类型为整形
	printf("该图的%d个顶点分别为:",n);
	//输出每个顶点字符
	for(i=0;i<n;i++)
	{
		a[i]=i;
		printf("%2d",a[i]);
	}
	printf("\n");
	
	//存储边的信息
	for(i=0;i<e;i++)
	{
		printf("请输入一条边依附的顶点v1,v2及权值(v1,v2,w):");
		scanf("%d%d%d",&rcw[i].row,&rcw[i].col,&rcw[i].weight);
	}

	CreatGraph(&g1,a,n,rcw,e);//创建一个邻接矩阵存储结构的图g1
	printf("该图的邻接矩阵为:\n");
	Print(&g1);//输出图g1的邻接矩阵
	
	printf("---------------------------------------------------\n");
    //求出邻接矩阵存储结构下图g1的每个顶点的度
	MVertices(&g1,a);

	printf("---------------------------------------------------\n");
	AdjLGraph g2;//定义一个邻接表存储结构的图g2
	RowCol rwc[MaxEdges];//定义边信息数组
	//用邻接矩阵生成邻接表
	for(i=0;i<e;i++)
	{
		rwc[i].col=rcw[i].col;
		rwc[i].row=rcw[i].row;
	}
	CreatLGraph(&g2,a,g1.Vertices.size,rwc,g1.numOfEdges);
	printf("邻接链表：\n");
	print(&g2);
	//求出邻接表存储结构下图g2每个顶点的度
    //LVertices(&g2,a);


	
	printf("---------------------------------------------------\n");
	// 两种遍历
	printf("深度优先遍历序列为(请输入开始顶点):");//DFS
	int zz;
	scanf("%d", &zz);
	DepthFirstSearch(g1,zz);
	printf("\n");
	printf("广度优先遍历序列为(请输入开始顶点):");//BFS
	scanf("%d", &zz);
	BroadFirstSearch(g1,zz);
    printf("\n");
	

	printf("---------------------------------------------------\n");
	//输入顶点x,查找图g1:若存在含x的顶点,则删除该结点及与之相关连的边,
	//并作DFS遍历否则输出信息"无x";
	int x;
	printf("请输入要查找的顶点:");
	scanf("%d",&x);
	if(ChaZhao(&g1,x))
	{
		MDelete(&g1,x);
		printf("删除顶点%d后的图的邻接矩阵为:\n",x);
		Print(&g1);
		printf("删除顶点%d后的深度优先遍历序列为(请输入开始顶点):",x);
		scanf("%d", &zz);
		DepthFirstSearch(g1,zz);
		printf("\n");
	}
	else
		printf("无%d\n",x);
	
	printf("---------------------------------------------------\n");
	



	//判断图g1的连通性
	printf("图g1是否为强连通图:\n");
	if(LianTong(&g2,a))
		printf("YES\n");
	else
		printf("NO\n");	
	//printf("11111\n");


	
	printf("本次试验到此结束!");
}
