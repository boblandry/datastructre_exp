#include"SeqCQueue.h"  //顺序循环队列
void Visit(DataType item)
{
	printf("%d ",item);
}	

void DepthFSearch(AdjMGraph G,int v,int visited[])
//以v为初始结点的访问操作为Visit()的DFS
//数组visited表示相应点是否已访问过，0表示未访问，1表示已访问
{
	int w;
	//Visit(G.Vertices.list[v]);  //访问结点v
	printf("%d ", v);
	visited[v]=1;  //标记为已访问
	w=GetFistVex(&G,v);  //取第一个邻接结点
	//printf("w:%d ",w);
	while(w!=-1)
	{
		if(!visited[w])//非0 还未访问
			DepthFSearch(G,w,visited);
		w=GetNextVex(&G,v,w);
	}
}

void DepthFirstSearch(AdjMGraph G,int x)
//G的访问操作为Visit()的DFS
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
//连通图G以v为初始结点的访问操作为Visit()的BFS

{
	DataType u,w;
	SeqCQueue queue;
	Visit(G.Vertices.list[v]);  //访问结点v
	visited[v]=1;  //标记为已访问
	QueueInitiate(&queue);  //队列初始化
	QueueAppend(&queue,v);  //初始结点v入队列
	while(QueueNotEmpty(queue))  //队列非空时
	{
		QueueDelete(&queue,&u);  //出队列
		w=GetFistVex(&G,u);  //取结点u的第一个邻接结点
		while(w!=-1)  //邻接结点w存在时
		{
			if(!visited[w])  //若没有访问过
			{
				Visit(G.Vertices.list[w]);  //访问结点w
				visited[w]=1;  //置已访问标记
				QueueAppend(&queue,w);  //结点w入队列
			}
			w=GetNextVex(&G,u,w);  //取下一个邻接结点                                              
		}
	}
}

void BroadFirstSearch(AdjMGraph G,int x)
//非连通图G访问操作为Visit()的BFS
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
//以v为初始结点的访问操作为Visit()的DFS
//数组visited表示相应点是否已访问过，0表示未访问，1表示已访问
{
	int w;
	Visit(G.Vertices.list[v]);  //访问结点v
	visited[v]=1;  //标记为已访问
	w=GetFistVex(&G,v);  //取第一个邻接结点
	while(w!=-1)
	{
		if(!visited[w])//非0 还未访问
			DepthFSearch(G,w,visited,Visit);
		w=GetNextVex(&G,v,w);
	}
}

void DepthFirstSearch(AdjMGraph G,void Visit(DataType item))
//G的访问操作为Visit()的DFS
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
//连通图G以v为初始结点的访问操作为Visit()的BFS

{
	DataType u,w;
	SeqCQueue queue;
	Visit(G.Vertices.list[v]);  //访问结点v
	visited[v]=1;  //标记为已访问
	QueueInitiate(&queue);  //队列初始化
	QueueAppend(&queue,v);  //初始结点v入队列
	while(QueueNotEmpty(queue))  //队列非空时
	{
		QueueDelete(&queue,&u);  //出队列
		w=GetFistVex(&G,u);  //取结点u的第一个邻接结点
		while(w!=-1)  //邻接结点w存在时
		{
			if(!visited[w])  //若没有访问过
			{
				Visit(G.Vertices.list[w]);  //访问结点w
				visited[w]=1;  //置已访问标记
				QueueAppend(&queue,w);  //结点w入队列
			}
			w=GetNextVex(&G,u,w);  //取下一个邻接结点                                              
		}
	}
}

void BroadFirstSearch(AdjMGraph G,void Visit(DataType item))
//非连通图G访问操作为Visit()的BFS
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
