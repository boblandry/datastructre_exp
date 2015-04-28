//�ڽӱ�Ĵ洢�ṹ
typedef struct Node  
{
	int dest;  //����
	struct Node *next;  
}Edge;  

typedef struct
{
	DataType data;   //ͷ 
	int sorce;  //����
	Edge *adj;  //ָ��
}AdjLHeight; //�ڽӱ�����

typedef struct
{
	AdjLHeight a[MaxVertices];  //�ڽӱ�����
	int numOfVerts;
	int numOfEdges;  
}AdjLGraph;  //�ڽӱ�ṹ��

void LAdjInitiate(AdjLGraph *G)//��ʼ��
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

//������������
void LAdjDestroy(AdjLGraph *G)
//����ͼG�е������ڽӱߵ�����
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

//������
void LInsertVertex(AdjLGraph *G,int i,DataType vertex)
//��ͼG�еĵ�i��λ�ò�������
{
	if(i>=0&&i<MaxVertices)
	{
		G->a[i].data=vertex;  
		G->numOfVerts++;      
	}
	else
		printf("���Խ��");
}

//�����
void LInsertEdge(AdjLGraph *G,int v1,int v2)

{
	Edge *p;  
	if(v1<0||v1>=G->numOfVerts||v2<0||v2>=G->numOfVerts)
	{
		printf("����v1��v2Խ�����");
		exit(0);
	}

	p=(Edge *)malloc(sizeof(Edge));  //����ռ�
	p->dest=v2;  //��ֵ����
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


//ɾ����
void LDeleteEdge(AdjLGraph *G,int v1,int v2)
{
	Edge *curr,*pre;
	if(v1<0||v1>=G->numOfVerts||v2<0||v2>=G->numOfVerts)
	{
		printf("����v1��v2Խ�����!");
		exit(0);
	}
	pre=NULL;
	curr=G->a[v1].adj;
	while(curr!=NULL&&curr->dest!=v2)
	//��v1�����ڽӱߵ������в���v2���
	{
		pre=curr;
		curr=curr->next;
	}
	//ɾ����ʾ�ڽӱ�<v1,v2>�Ľ��
	if(curr!=NULL&&curr->dest==v2&&pre==NULL)
    //���ڽӱ�<v1,v2>�Ľ���ǵ�����ĵ�һ�����ʱ
	{
		G->a[v1].adj=curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else if(curr!=NULL&&curr->dest==v2&&pre!=NULL)
	//���ڽӱ�<v1,v2>�Ľ�㲻�ǵ�����ĵ�һ�����ʱ	
	{
		pre->next=curr->next;
		free(curr);
		G->numOfEdges--;
	}
	else
	printf("��<v1,v2>������ʱ");
}

//ȡ��һ���ڽӽ��
int LGetFirstVex(AdjLGraph *G,int v)
//ȡͼG�н��v�ĵ�һ���ڽӽ��
//ȡ��ʱ���ظ��ڽӽ��Ķ�Ӧ��ţ����򷵻�-1
{
	Edge *p;
	if(v<0||v>G->numOfVerts)
	{
		printf("����v1��v2Խ�����!");
		exit(0);
	}
	p=G->a[v].adj;
	if(p!=NULL)
		return p->dest;  //���ظ��ڽӽ��Ķ�Ӧ���
	else
		return -1;  //����-1
}

//ȡ��һ���ڽӽ��
int LGetNextVex(AdjLGraph *G,int v1,int v2)
//ȡͼG�н��v1���ڽӽ��v2����һ���ڽӽ��
//ȡ��ʱ���ظ��ڽӽ��Ķ�Ӧ��ţ����򷵻�-1
{
	Edge *p;
	if(v1<0||v1>G->numOfVerts||v2<0||v2>G->numOfVerts)
	{
		printf("����v1��v2Խ�����!");
		exit(0);
	}
	p=G->a[v1].adj;
	while(p!=NULL)  //Ѱ�ҽ��v1���ڽӽ��v2
	{
		if(p->dest!=v2)
		{
			p=p->next;
			continue;
		}
		else
			break;
	}
	p=p->next;  //pָ���ڽӽ��v2����һ���ڽӽ��
	if(p!=NULL)
		return p->dest;  //���ظ��ڽӽ��Ķ�Ӧ���
	else
		return -1;  //����-1
}

//�ڽӱ�洢����ÿ������ĶȲ�������
void LVertices(AdjLGraph *G,DataType a[])
{
	printf("�ڽӱ�洢�ṹ�µ�ͼ�Ķ���Ķ�Ϊ:\n");
	int OutDegree[MaxVertices],InDegree[MaxVertices];//����һ�����Ⱥ���ȵ�����
	int i;
	for(i=0;i<G->numOfVerts;i++)  //���Ƚ����Ⱥ���������ÿ����Ա����0
	{
		OutDegree[i]=0;
		InDegree[i]=0;
	}
	Edge *p;  //����һ���ڽӱ�ָ��
	for(i=0;i<G->numOfVerts;i++)
	{
		p=G->a[i].adj;  //ָ��ָ��a[i]���ڽӱߵ�����ͷ���
		while(p!=NULL)//��p��ָ����ڽӱ߽�㲻��ʱ
		{
			OutDegree[i]++; //���ȼ�1
			InDegree[p->dest]++; //�ڽӱ߻�ͷ������ȼ�1
			p=p->next; //pָ����һ���ڽӱ߽��
		}
	}
	for(i=0;i<G->numOfVerts;i++) //���ÿ�����Ķ�
	{
		printf("����%d�Ķ�Ϊ:",a[i]);
		printf("%d",OutDegree[i]+InDegree[i]); //ÿ�����Ķȼ������������ӵĺ�
		printf("\n");
	}
}
//�ж�����ͼG�Ƿ�Ϊǿ��ͨͼ
int LianTong(AdjLGraph *G,DataType a[]) 
{
	int i,b[MaxVertices],k=0;
	for(i=0;i<G->numOfVerts;i++)
		b[i]=0;
	Edge *q,*p;  //�ڽӱ�ָ��
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
