typedef struct
{	
	int row;  //���±�
	int col;  //���±�
	int weight;  //Ȩֵ
}RowColWeight;  //����Ϣ�ṹ�嶨��

void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight E[],int e)
//��ͼG�в���n�������Ϣv��e������ϢE
{
	int i,k;
	Initiate(G,n);  //���˳����ʼ��
	for(i=0;i<n;i++)
		InsertVertex(G,v[i]);  //������
	for(k=0;k<e;k++)
		InsertEdge(G,E[k].row,E[k].col,E[k].weight);  //�߲���
}
