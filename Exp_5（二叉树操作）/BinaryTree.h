#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryTreeNode.h"
#include "LinkedQueue.h"
int _count;
template<class T>
class BinaryTree
{
	public:
		BinaryTree(){root=0;};
		~BinaryTree(){};
		bool IsEmpty()const
		{return((root)?false:true);}
		bool Root(T& x)const;
		void createTree();
		void MakeTree(const T& element,BinaryTree<T>& left,BinaryTree<T>& right);
		void BreakTree(T& element,BinaryTree<T>& left,BinaryTree<T>& right);
		//�������
		void PreOrder(void(*Visit) (BinaryTreeNode<T> *u))
		{PreOrder(Visit,root);}
		void InOrder(void(*Visit) (BinaryTreeNode<T> *u))
		{InOrder(Visit,root);}
		void PostOrder(void(*Visit) (BinaryTreeNode<T> *u))
		{PostOrder(Visit,root);}
		void LevelOrder(void(*Visit) (BinaryTreeNode<T> *u));
		//������������
		void PreOutput(){PreOrder(Output,root);cout<<endl;}
		void InOutput(){InOrder(Output,root);cout<<endl;}
		void PostOutput(){PostOrder(Output,root);cout<<endl;}
		void LevelOutput(){LevelOrder(Output);cout<<endl;}

		void Delete(){PostOrder(Free,root);root=0;}
		//����������ĸ߶�
		int Height()const{return Height(root);}
		//����������Ľڵ���
		int Size()
		{
			_count=0;
			PreOrder(Addl,root);
			return _count;
		}
		//�ɶ�������ǰ�������  ����������  �������������Ľ��
		void PreIn()
		{
			int len;
			cout << "������ö������Ľڵ���!"<<endl;
			cin >> len;
			int* pre = new int[len];
			int* in = new int[len];
			cout << "������ö�������ǰ�����У�" << endl;
			for(int i = 0; i<len; i++)
				cin >> pre[i];
			cout << "������ö��������������У�" << endl;
				for(int j = 0; j<len; j++)
			cin >> in[j];
			PreInCreateTree(root, pre, in, 0, 0,len);
		}

		void PreInCreateTree(BinaryTreeNode<T>* & t,T* pre, T* in, int i, int j, int len);
	private:
		BinaryTreeNode<T> *root;//���ڵ�ָ��
		void PreOrder(void(*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
		void InOrder(void(*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
		void PostOrder(void(*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
		static void Output(BinaryTreeNode<T> *t)
		{cout<<t->data<<' ';}
		static void Free(BinaryTreeNode<T> *t){delete t;}
		int Height(BinaryTreeNode<T> *t)const;
		static void Addl(BinaryTreeNode<T> *t){_count++;}
		int getM(T* a, T x)
		{
			for(int i = 0; i < 20; i++)
				if(a[i]== x)
					return i;
		}
};


template<class T>
bool BinaryTree<T>::Root(T& x)const
{//ȡ���ڵ��data�򣬷���x
	//���û�и��ڵ㣬�򷵻�false
	if(root)
	{
		x=root->data;return true;
	}
	else return false;
}
//���ղ�α���˳����һ��������
template <class T>
void BinaryTree<T>::createTree()
{
    cout << "������һ������������һ����������" << endl;
    cout << "�����ղ�α���˳�򣬲���-1������" << endl;

    int tempData;
    BinaryTreeNode<T>* tempBT;
    BinaryTreeNode<T>* rear;
    LinkedQueue<BinaryTreeNode<T>*> tempQ;
    cin >> tempData;

    while(tempData!= -1)
    {
        tempBT = new BinaryTreeNode<T>(tempData);
        if(root == 0)
        {
            root = tempBT;
            rear = root;
            tempQ.Add(rear);
        }
        else if((rear->LeftChild != 0) && (rear->RightChild == 0))
        {
            rear->RightChild = tempBT;
            tempQ.Add(rear->RightChild);
        }
        else
        {
            tempQ.Delete(rear);
            rear->LeftChild = tempBT;
            tempQ.Add(rear->LeftChild);
        }
        cin >> tempData;
    }

}


template <class T>
void BinaryTree<T>::PreInCreateTree(BinaryTreeNode<T>*& t,T* pre, T* in, int i, int j, int len)
{
    if(len > 0)
    {
        t = new BinaryTreeNode<T>();
        t->data = pre[i];
        int m = getM(in, pre[i]);
        PreInCreateTree(t->LeftChild, pre, in, i+1, j, m-j);
        PreInCreateTree(t->RightChild, pre, in, i+(m-j)+1, m+1,len-1-(m-j));
    }
}

template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left,BinaryTree<T>& right)
{//��left��right��element�ϲ���һ������
	//left��right��this�����ǲ�ͬ����
	//��������
	root=new BinaryTreeNode<T>
		(element,left.root,right.root);
	//��֯����left��right
	left.root=right.root=0;
}


template<class T>
void BinaryTree<T>::BreakTree(T& element,BinaryTree<T>& left,BinaryTree<T>& right)
{
	//������Ƿ�Ϊ��
	if (!root) throw BadInput();
	//�ֽ���
	element=root->data;
	left.root=root->LeftChild;
	right.root=root->RightChild;

	delete root;root=0;
}

//ǰ�����
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if(t)
	{
		Visit(t);
		PreOrder(Visit,t->LeftChild);
		PreOrder(Visit,t->RightChild);
	}
}

//�������
template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if(t)
	{
		InOrder(Visit,t->LeftChild);
		Visit(t);
		InOrder(Visit,t->RightChild);
	}
}

//�������
template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if(t)
	{
		PostOrder(Visit,t->LeftChild);
		PostOrder(Visit,t->RightChild);
		Visit(t);
	}
}

//������
template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T> *u))
{
	LinkedQueue<BinaryTreeNode<T>*> Q;
	BinaryTreeNode<T> *t;
	t=root;
	while(t)
	{
		Visit(t);
		if(t->LeftChild) Q.Add(t->LeftChild);
		if(t->RightChild) Q.Add(t->RightChild);
		if(Q.IsEmpty())
			return;
		else 
			Q.Delete(t);
	}
}
//�������ĸ߶�
template<class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t)const
{
	if(!t) return 0;
	int hl=Height(t->LeftChild);
	int hr=Height(t->RightChild);
	if(hl>hr) return ++hl;
	else return ++hr;
}
#endif