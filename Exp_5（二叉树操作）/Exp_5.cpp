#include <iostream.h>
#include "BinaryTree.h"
#include "LinkedQueue.h"
int count=0;
BinaryTree<int> a,x,y,z;

template<class T>
void ct(BinaryTreeNode<T> *t){count++;}

void main()
{
	/*y.MakeTree(1,a,a);
	z.MakeTree(2,a,a);
	x.MakeTree(3,y,z);
	y.MakeTree(4,x,a);
	y.PreOrder(ct);
	y.PreOutput();
	y.InOutput();
	y.PostOutput();
	y.LevelOutput();
	int h,s;
	h=y.Height();
	s=y.Size();
	cout<<"�ö�������"<<h<<"��"<<endl;
	cout<<"�ö�������"<<s<<"���ڵ�"<<endl;
	cout<< count<<endl;*/
	/*LinkedQueue<int> l;
	l.Add(2).Add(1).Add(3);
	int t;
	l.Delete(t);cout<<t<<endl;*/
	BinaryTree<int> newtree;
	newtree.createTree();
	cout<<"ǰ�����Ϊ��"<<endl;
	newtree.PreOutput();
	cout<<"�������Ϊ��"<<endl;
	newtree.InOutput();
	cout<<"�������Ϊ��"<<endl;
	newtree.PostOutput();
	cout<<"��α���Ϊ��"<<endl;
	newtree.LevelOutput();
	int h,s;
	h=newtree.Height();s=newtree.Size();
	cout<<"�ö�������"<<h<<"��"<<endl;
	cout<<"�ö�������"<<s<<"���ڵ�"<<endl;
	cout<<"-----------------------"<<endl;
	BinaryTree<int> tree1;
	tree1.PreIn();
	cout<<"�ö������ĺ�������Ϊ��"<<endl;
	tree1.PostOutput();
}