typedef struct
{	
	int row;  //行下标
	int col;  //列下标
	int weight;  //权值
}RowColWeight;  //边信息结构体定义

void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight E[],int e)
//在图G中插入n个结点信息v和e条边信息E
{
	int i,k;
	Initiate(G,n);  //结点顺序表初始化
	for(i=0;i<n;i++)
		InsertVertex(G,v[i]);  //结点插入
	for(k=0;k<e;k++)
		InsertEdge(G,E[k].row,E[k].col,E[k].weight);  //边插入
}
