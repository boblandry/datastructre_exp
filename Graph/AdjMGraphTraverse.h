#include"SeqCQueue.h"  //˳��ѭ������
void Visit(DataType item)
{
	printf("%d ",item);
}	

void DepthFSearch(AdjMGraph G,int v,int visited[])
//��vΪ��ʼ���ķ��ʲ���ΪVisit()��DFS
//����visited��ʾ��Ӧ���Ƿ��ѷ��ʹ���0��ʾδ���ʣ�1��ʾ�ѷ���
{
	int w;
	//Visit(G.Vertices.list[v]);  //���ʽ��v
	printf("%d ", v);
	visited[v]=1;  //���Ϊ�ѷ���
	w=GetFistVex(&G,v);  //ȡ��һ���ڽӽ��
	//printf("w:%d ",w);
	while(w!=-1)
	{
		if(!visited[w])//��0 ��δ����
			DepthFSearch(G,w,visited);
		w=GetNextVex(&G,v,w);
	}
}

void DepthFirstSearch(AdjMGraph G,int x)
//G�ķ��ʲ���ΪVisit()��DFS
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);
	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;
	//for(i=0;i<G.Vertices.size;i++)
		//if(!visited[i])
			DepthFSearch(G,x,visited);
	free(visited);
}
void BroadFSearch(AdjMGraph G,int v,int visited[],void Visit(DataType item))
//��ͨͼG��vΪ��ʼ���ķ��ʲ���ΪVisit()��BFS

{
	DataType u,w;
	SeqCQueue queue;
	Visit(G.Vertices.list[v]);  //���ʽ��v
	visited[v]=1;  //���Ϊ�ѷ���
	QueueInitiate(&queue);  //���г�ʼ��
	QueueAppend(&queue,v);  //��ʼ���v�����
	while(QueueNotEmpty(queue))  //���зǿ�ʱ
	{
		QueueDelete(&queue,&u);  //������
		w=GetFistVex(&G,u);  //ȡ���u�ĵ�һ���ڽӽ��
		while(w!=-1)  //�ڽӽ��w����ʱ
		{
			if(!visited[w])  //��û�з��ʹ�
			{
				Visit(G.Vertices.list[w]);  //���ʽ��w
				visited[w]=1;  //���ѷ��ʱ��
				QueueAppend(&queue,w);  //���w�����
			}
			w=GetNextVex(&G,u,w);  //ȡ��һ���ڽӽ��                                              
		}
	}
}

void BroadFirstSearch(AdjMGraph G,int x)
//����ͨͼG���ʲ���ΪVisit()��BFS
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);
	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;
	//for(i=0;i<G.Vertices.size;i++)
		//if(!visited[i])
			BroadFSearch(G,x,visited,Visit);
		free(visited);
}

/*
void DepthFSearch(AdjMGraph G,int v,int visited[],void Visit(DataType item))
//��vΪ��ʼ���ķ��ʲ���ΪVisit()��DFS
//����visited��ʾ��Ӧ���Ƿ��ѷ��ʹ���0��ʾδ���ʣ�1��ʾ�ѷ���
{
	int w;
	Visit(G.Vertices.list[v]);  //���ʽ��v
	visited[v]=1;  //���Ϊ�ѷ���
	w=GetFistVex(&G,v);  //ȡ��һ���ڽӽ��
	while(w!=-1)
	{
		if(!visited[w])//��0 ��δ����
			DepthFSearch(G,w,visited,Visit);
		w=GetNextVex(&G,v,w);
	}
}

void DepthFirstSearch(AdjMGraph G,void Visit(DataType item))
//G�ķ��ʲ���ΪVisit()��DFS
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);
	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;
	for(i=0;i<G.Vertices.size;i++)
		if(!visited[i])
			DepthFSearch(G,i,visited,Visit);
	free(visited);
}


void BroadFSearch(AdjMGraph G,int v,int visited[],void Visit(DataType item))
//��ͨͼG��vΪ��ʼ���ķ��ʲ���ΪVisit()��BFS

{
	DataType u,w;
	SeqCQueue queue;
	Visit(G.Vertices.list[v]);  //���ʽ��v
	visited[v]=1;  //���Ϊ�ѷ���
	QueueInitiate(&queue);  //���г�ʼ��
	QueueAppend(&queue,v);  //��ʼ���v�����
	while(QueueNotEmpty(queue))  //���зǿ�ʱ
	{
		QueueDelete(&queue,&u);  //������
		w=GetFistVex(&G,u);  //ȡ���u�ĵ�һ���ڽӽ��
		while(w!=-1)  //�ڽӽ��w����ʱ
		{
			if(!visited[w])  //��û�з��ʹ�
			{
				Visit(G.Vertices.list[w]);  //���ʽ��w
				visited[w]=1;  //���ѷ��ʱ��
				QueueAppend(&queue,w);  //���w�����
			}
			w=GetNextVex(&G,u,w);  //ȡ��һ���ڽӽ��                                              
		}
	}
}

void BroadFirstSearch(AdjMGraph G,void Visit(DataType item))
//����ͨͼG���ʲ���ΪVisit()��BFS
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);
	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;
	//for(i=0;i<G.Vertices.size;i++)
		//if(!visited[i])
			BroadFSearch(G,i,visited,Visit);
		free(visited);
}*/
