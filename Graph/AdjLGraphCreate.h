typedef struct
{
	int row;  //���±�
	int col;  //���±�
}RowCol;  //����Ϣ�ṹ�嶨��

void CreatLGraph(AdjLGraph *G,DataType v[],int n,RowCol d[],int e)
{
	int i,k;
	LAdjInitiate(G);
	for(i=0;i<n;i++)
		LInsertVertex(G,i,v[i]);
	for(k=0;k<e;k++)
		LInsertEdge(G,d[k].row,d[k].col);
}


