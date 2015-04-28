#include"SeqList.h"
typedef struct
{
	SeqList Vertices;
	int edge[MaxVertices][MaxVertices];  
	int numOfEdges;   //边的条数
}AdjMGraph;  

void Initiate(AdjMGraph *G,int n)   
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i==j)
				G->edge[i][j]=0;
			else
				G->edge[i][j]=MaxWeight;
		}
		G->numOfEdges=0;   
		ListInitiate(&G->Vertices);  
}

void InsertVertex(AdjMGraph *G,DataType vertex)  //在图G中插入结点vertex
{
	ListInsert(&G->Vertices,G->Vertices.size,vertex);  //顺序表尾插入
}

void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)
//在图G中插入边
{
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);
	}
	G->edge[v1][v2]=weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjMGraph *G,int v1,int v2)  //在图中删除边
{
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size||v1==v2)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);
	}
	if(G->edge[v1][v2]==MaxWeight)
	{
		printf("该边不存在!\n");
		exit(0);
	}
	G->edge[v1][v2]=MaxWeight;
	G->numOfEdges--;
}

void DeleteVerten(AdjMGraph *G,int v)  //删除结点
{
	int n=ListLength(G->Vertices),i,j;  
	DataType x;
	for(i=0;i<n;i++)  //计算删除后的边数
	{
		for(j=0;j<n;j++)
			if((i==v||j==v)&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				G->numOfEdges--;  //计算被删除边
	}
	for(i=v;i<n;i++)  //删除第v行
	{
		for(j=0;j<n;j++)
			G->edge[i][j]=G->edge[i+1][j];
	}
	for(i=0;i<n;i++)  //删除第v列
	{
		for(j=v;j<n;j++)
			G->edge[i][j]=G->edge[i][j+1];
	}
	ListDelete(&G->Vertices,v,&x);  //删除结点
}

int GetFistVex(AdjMGraph *G,int v)  
//在图G中寻找序号为v的结点的第一个邻接结点
//如果这样的邻接结点存在，返回该邻接结点的序号；否则，返回-1
{
	int col;

	if(v<0||v>G->Vertices.size)
	{
		printf("参数v1越界出错!\n");
		exit(1);
	}
	for(col=0;col<G->Vertices.size;col++)
		if(G->edge[v][col]>0&&G->edge[v][col]<MaxWeight)
			return col;
		return -1;
}

int GetNextVex(AdjMGraph*G,int v1,int v2)
//在图中寻找v1结点的邻接结点v2的下一个邻接结点
//如果这样的结点存在，返回该邻接结点的序号；否则，返回-1
{
	int col;
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size)
	{
		printf("参数v1或v2越界出错!\n");
		exit(1);    
	}
	for(col=v2+1;col<G->Vertices.size;col++)
			if(G->edge[v1][col]>0&&G->edge[v1][col]<MaxWeight)return col;
		return -1;
}

//输出图G的邻接矩阵
void Print(AdjMGraph *G)  
{
	int i,j;
	for(i=0;i<G->Vertices.size;i++)
	{
		for(j=0;j<G->Vertices.size;j++)
			if(G->edge[i][j]!=MaxWeight)
				printf("%6d ",G->edge[i][j]);
			else
				printf("%6c ", '#');
		printf("\n");
	}
}

//邻接矩阵存储结构下求出每个顶点的度并输出
void MVertices(AdjMGraph *G,DataType a[])  
{
	int i,j,m;
	DataType b[MaxVertices];//记录相应节点的度
	DataType c[MaxVertices];
	for(i=0;i<G->Vertices.size;i++)
	{
		b[i]=0;  //初始化
		c[i] = 0;
	}
	printf("邻接矩阵存储结构下图的顶点的度为:\n");
	for(m=0;m<G->Vertices.size;m++)  //求出每个结点的度
	{
		for(i=0;i<G->Vertices.size;i++)
			for(j=0;j<G->Vertices.size;j++)
			{
				if(i==m&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				//求出邻接矩阵第i行权值存在的边的个数,当边<m,j>存在时,b[m]加1
					b[m]++;
				if(j==m&&i!=m&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				//求出邻接矩阵第j列权值存在的边的个数,当边<i,m>存在时，b[m]加1
					c[m]++;
			}
		printf("顶点%d的出度为:%d; 入度为：%d\n",a[m],b[m],c[m]);
	}
}

 

//查找图G中是否存在点v
int ChaZhao(AdjMGraph *G,int v)  
{
	if(0<=v&&v<G->Vertices.size)
	{
		printf("存在顶点%d\n",v);
		return 1;
	}
		
	else
	{
		printf("不存在顶点%d\n",v);
		return 0;
	}
}

//删除查找到的结点v并删除该结点及与之相关的边
void MDelete(AdjMGraph *G,int v)
{
	int i;
	for(i=0;i<G->Vertices.size;i++)
	{
		if(G->edge[v][i]>0&&G->edge[v][i]<MaxWeight)
		//当邻接矩阵的第v行有边<v,i>存在时,删除边<v,i>
			DeleteEdge(G,v,i);

		if(G->edge[i][v]>0&&G->edge[i][v]<MaxWeight)
		//当邻接矩阵的第j行有边<i,v>存在时,删除边<i,v>
			DeleteEdge(G,i,v);
	}
	DeleteVerten(G,v);//删除结点v
}

