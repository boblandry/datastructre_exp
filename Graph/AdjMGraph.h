#include"SeqList.h"
typedef struct
{
	SeqList Vertices;
	int edge[MaxVertices][MaxVertices];  
	int numOfEdges;   //�ߵ�����
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

void InsertVertex(AdjMGraph *G,DataType vertex)  //��ͼG�в�����vertex
{
	ListInsert(&G->Vertices,G->Vertices.size,vertex);  //˳���β����
}

void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)
//��ͼG�в����
{
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);
	}
	G->edge[v1][v2]=weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjMGraph *G,int v1,int v2)  //��ͼ��ɾ����
{
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size||v1==v2)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);
	}
	if(G->edge[v1][v2]==MaxWeight)
	{
		printf("�ñ߲�����!\n");
		exit(0);
	}
	G->edge[v1][v2]=MaxWeight;
	G->numOfEdges--;
}

void DeleteVerten(AdjMGraph *G,int v)  //ɾ�����
{
	int n=ListLength(G->Vertices),i,j;  
	DataType x;
	for(i=0;i<n;i++)  //����ɾ����ı���
	{
		for(j=0;j<n;j++)
			if((i==v||j==v)&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				G->numOfEdges--;  //���㱻ɾ����
	}
	for(i=v;i<n;i++)  //ɾ����v��
	{
		for(j=0;j<n;j++)
			G->edge[i][j]=G->edge[i+1][j];
	}
	for(i=0;i<n;i++)  //ɾ����v��
	{
		for(j=v;j<n;j++)
			G->edge[i][j]=G->edge[i][j+1];
	}
	ListDelete(&G->Vertices,v,&x);  //ɾ�����
}

int GetFistVex(AdjMGraph *G,int v)  
//��ͼG��Ѱ�����Ϊv�Ľ��ĵ�һ���ڽӽ��
//����������ڽӽ����ڣ����ظ��ڽӽ�����ţ����򣬷���-1
{
	int col;

	if(v<0||v>G->Vertices.size)
	{
		printf("����v1Խ�����!\n");
		exit(1);
	}
	for(col=0;col<G->Vertices.size;col++)
		if(G->edge[v][col]>0&&G->edge[v][col]<MaxWeight)
			return col;
		return -1;
}

int GetNextVex(AdjMGraph*G,int v1,int v2)
//��ͼ��Ѱ��v1�����ڽӽ��v2����һ���ڽӽ��
//��������Ľ����ڣ����ظ��ڽӽ�����ţ����򣬷���-1
{
	int col;
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size)
	{
		printf("����v1��v2Խ�����!\n");
		exit(1);    
	}
	for(col=v2+1;col<G->Vertices.size;col++)
			if(G->edge[v1][col]>0&&G->edge[v1][col]<MaxWeight)return col;
		return -1;
}

//���ͼG���ڽӾ���
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

//�ڽӾ���洢�ṹ�����ÿ������ĶȲ����
void MVertices(AdjMGraph *G,DataType a[])  
{
	int i,j,m;
	DataType b[MaxVertices];//��¼��Ӧ�ڵ�Ķ�
	DataType c[MaxVertices];
	for(i=0;i<G->Vertices.size;i++)
	{
		b[i]=0;  //��ʼ��
		c[i] = 0;
	}
	printf("�ڽӾ���洢�ṹ��ͼ�Ķ���Ķ�Ϊ:\n");
	for(m=0;m<G->Vertices.size;m++)  //���ÿ�����Ķ�
	{
		for(i=0;i<G->Vertices.size;i++)
			for(j=0;j<G->Vertices.size;j++)
			{
				if(i==m&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				//����ڽӾ����i��Ȩֵ���ڵıߵĸ���,����<m,j>����ʱ,b[m]��1
					b[m]++;
				if(j==m&&i!=m&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				//����ڽӾ����j��Ȩֵ���ڵıߵĸ���,����<i,m>����ʱ��b[m]��1
					c[m]++;
			}
		printf("����%d�ĳ���Ϊ:%d; ���Ϊ��%d\n",a[m],b[m],c[m]);
	}
}

 

//����ͼG���Ƿ���ڵ�v
int ChaZhao(AdjMGraph *G,int v)  
{
	if(0<=v&&v<G->Vertices.size)
	{
		printf("���ڶ���%d\n",v);
		return 1;
	}
		
	else
	{
		printf("�����ڶ���%d\n",v);
		return 0;
	}
}

//ɾ�����ҵ��Ľ��v��ɾ���ý�㼰��֮��صı�
void MDelete(AdjMGraph *G,int v)
{
	int i;
	for(i=0;i<G->Vertices.size;i++)
	{
		if(G->edge[v][i]>0&&G->edge[v][i]<MaxWeight)
		//���ڽӾ���ĵ�v���б�<v,i>����ʱ,ɾ����<v,i>
			DeleteEdge(G,v,i);

		if(G->edge[i][v]>0&&G->edge[i][v]<MaxWeight)
		//���ڽӾ���ĵ�j���б�<i,v>����ʱ,ɾ����<i,v>
			DeleteEdge(G,i,v);
	}
	DeleteVerten(G,v);//ɾ�����v
}

