//邻接表的存储结构
typedef struct Node  
{
	int dest;  //数据
	struct Node *next;  
}Edge;  

typedef struct
{
	DataType data;   //头 
	int sorce;  //数据
	Edge *adj;  //指针
}AdjLHeight; //邻接表数组

typedef struct
{
	AdjLHeight a[MaxVertices];  //邻接表数组
	int numOfVerts;
	int numOfEdges;  
}AdjLGraph;  //邻接表结构体

void LAdjInitiate(AdjLGraph *G)//初始化
{
	int i;
	G->numOfVerts=0;
	G->numOfEdges=0;
	for(i=0;i<MaxVertices;i++)
	{
		G->a[i].sorce=i;
		G->a[i].adj=NULL;
	}
}

//撤销操作函数
void LAdjDestroy(AdjLGraph *G)
//撤销图G中的所有邻接边单链表
{
	int i;
	Edge *p,*q;
	for(i=0;i<G->numOfVerts;i++)
	{
		p=G->a[i].adj;
		while(p!=NULL)
		{
			q=p->next;
			free(p);
			p=q;
		}
	}
}

//插入结点
void LInsertVertex(AdjLGraph *G,int i,DataType vertex)
//在图G中的第i个位置插入数据
{
	if(i>=0&&i<MaxVertices)
	{
		G->a[i].data=vertex;  
		G->numOfVerts++;      
	}
	else
		printf("结点越界");
}

//插入边
void LInsertEdge(AdjLGraph *G,int v1,int v2)

{
	Edge *p;  
	if(v1<0||v1>=G->numOfVerts||v2<0||v2>=G->numOfVerts)
	{
		printf("参数v1或v2越界出错");
		exit(0);
	}

	p=(Edge *)malloc(sizeof(Edge));  //申请空间
	p->dest=v2;  //赋值数据
	p->next=G->a[v1].adj; 
	//if(	G->a[v1].adj==NULL)
	//{printf("(%d)NULL%d", v1,v2);
		G->a[v1].adj=p;  
	//else
	//{printf("(%d)---%d",v1, v2);
	//G->a[v1].adj->next = p;}
	G->numOfEdges++;  
} 

void print(AdjLGraph * G)
{
	for(int i = 0; i< G->numOfVerts;i++)
	{
		printf("%d: ", G->a[i].data);
		Edge * temp = G->a[i].adj;
		while(temp!=NULL)
		{printf("%d",temp->dest);
		
		temp = temp->next;
		if(temp!=NULL)
			printf("->");
		}
		printf("\n");
	}
}


//删除边
void LDeleteEdge(AdjLGraph *G,int v1,int v2)
{
	Edge *curr,*pre;
	if(v1<0||v1>=G->numOfVerts||v2<0||v2>=G->numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}
	pre=NULL;
	curr=G->a[v1].adj;
	while(curr!=NULL&&curr->dest!=v2)
	//在v1结点的邻接边单链表中查找v2结点
	{
		pre=curr;
		curr=curr->next;
	}
	//删除表示邻接边<v1,v2>的结点
	if(curr!=NULL&&curr->dest==v2&&pre==NULL)
    //当邻接边<v1,v2>的结点是单链表的第一个结点时
	{
		G->a[v1].adj=curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else if(curr!=NULL&&curr->dest==v2&&pre!=NULL)
	//当邻接边<v1,v2>的结点不是单链表的第一个结点时	
	{
		pre->next=curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else
	printf("边<v1,v2>不存在时");
}

//取第一个邻接结点
int LGetFirstVex(AdjLGraph *G,int v)
//取图G中结点v的第一个邻接结点
//取到时返回该邻接结点的对应序号，否则返回-1
{
	Edge *p;
	if(v<0||v>G->numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}
	p=G->a[v].adj;
	if(p!=NULL)
		return p->dest;  //返回该邻接结点的对应序号
	else
		return -1;  //返回-1
}

//取下一个邻接结点
int LGetNextVex(AdjLGraph *G,int v1,int v2)
//取图G中结点v1的邻接结点v2的下一个邻接结点
//取到时返回该邻接结点的对应序号，否则返回-1
{
	Edge *p;
	if(v1<0||v1>G->numOfVerts||v2<0||v2>G->numOfVerts)
	{
		printf("参数v1或v2越界出错!");
		exit(0);
	}
	p=G->a[v1].adj;
	while(p!=NULL)  //寻找结点v1的邻接结点v2
	{
		if(p->dest!=v2)
		{
			p=p->next;
			continue;
		}
		else
			break;
	}
	p=p->next;  //p指向邻接结点v2的下一个邻接结点
	if(p!=NULL)
		return p->dest;  //返回该邻接结点的对应序号
	else
		return -1;  //返回-1
}

//邻接表存储下求每个顶点的度并输出结果
void LVertices(AdjLGraph *G,DataType a[])
{
	printf("邻接表存储结构下的图的顶点的度为:\n");
	int OutDegree[MaxVertices],InDegree[MaxVertices];//定义一个出度和入度的数组
	int i;
	for(i=0;i<G->numOfVerts;i++)  //首先将出度和入度数组的每个成员都置0
	{
		OutDegree[i]=0;
		InDegree[i]=0;
	}
	Edge *p;  //定义一个邻接边指针
	for(i=0;i<G->numOfVerts;i++)
	{
		p=G->a[i].adj;  //指针指向a[i]的邻接边单链表头结点
		while(p!=NULL)//当p所指向的邻接边结点不空时
		{
			OutDegree[i]++; //出度加1
			InDegree[p->dest]++; //邻接边弧头结点的入度加1
			p=p->next; //p指向下一个邻接边结点
		}
	}
	for(i=0;i<G->numOfVerts;i++) //输出每个结点的度
	{
		printf("顶点%d的度为:",a[i]);
		printf("%d",OutDegree[i]+InDegree[i]); //每个结点的度即出度与入度相加的和
		printf("\n");
	}
}
//判断有向图G是否为强连通图
int LianTong(AdjLGraph *G,DataType a[]) 
{
	int i,b[MaxVertices],k=0;
	for(i=0;i<G->numOfVerts;i++)
		b[i]=0;
	Edge *q,*p;  //邻接边指针
	for(i=0;i<G->numOfVerts;i++)
	{
		q=G->a[i].adj;
		while(q!=NULL)
		{
			b[i]++;
			q=q->next;
		}
	}
	for(i=0;i<G->numOfVerts;i++)
	{
		if(b[i]==1)
			k++;
	}
	p=G->a[G->numOfVerts-1].adj;
	if(k==G->numOfVerts&&p->dest==a[0])
		return 1;
	else
		return 0;
}
