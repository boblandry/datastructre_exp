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
	cout<<"该二叉树有"<<h<<"层"<<endl;
	cout<<"该二叉树有"<<s<<"个节点"<<endl;
	cout<< count<<endl;*/
	/*LinkedQueue<int> l;
	l.Add(2).Add(1).Add(3);
	int t;
	l.Delete(t);cout<<t<<endl;*/
	BinaryTree<int> newtree;
	newtree.createTree();
	cout<<"前序遍历为："<<endl;
	newtree.PreOutput();
	cout<<"中序遍历为："<<endl;
	newtree.InOutput();
	cout<<"后序遍历为："<<endl;
	newtree.PostOutput();
	cout<<"层次遍历为："<<endl;
	newtree.LevelOutput();
	int h,s;
	h=newtree.Height();s=newtree.Size();
	cout<<"该二叉树有"<<h<<"层"<<endl;
	cout<<"该二叉树有"<<s<<"个节点"<<endl;
	cout<<"-----------------------"<<endl;
	BinaryTree<int> tree1;
	tree1.PreIn();
	cout<<"该二叉树的后序序列为："<<endl;
	tree1.PostOutput();
}