#include <iostream>
using namespace std;
#include "xcept.h"
template<class T>
class Chain;
template<class T>
class Chainiterator;
template<class T>
class ChainNode
{
	friend Chain<T>;
	friend Chainiterator<T>;
	private:
		T data;
		ChainNode<T> *link;
};
template<class T>
class Chain
{
	friend Chainiterator<T>;
	public:
		Chain() {first=0;}
		~Chain();
		bool isempty() const {return first==0;}
		int length() const;
		bool find(int k,T& x)const;
		int search(const T& x)const;
		Chain<T>& Delete(int k,T& x);
		Chain<T>& insert(int k,const T& x);
		Chain<T>& append(const T& x);
		void output(ostream& out)const;
	private:
		ChainNode<T> *first;//指向第一个节点的指针
		ChainNode<T> *last;
};
//删除链表中的所有节点
template<class T>
Chain<T>::~Chain()
{//链表的析构函数，用于删除链表中的所有节点
	ChainNode<T> *next;
	while(first)
	{
		next=first->link;//下一个节点
		delete first;
		first=next;
	}
}
//确定链表的长度
template<class T>
int Chain<T>::length() const
{
	ChainNode<T> *current=first;
	int len=0;
	while(current)
	{
		len++;
		current=current->link;
	}
	return len;
}
//在链表中查找第K个元素
template<class T>
bool Chain<T>::find(int k,T& x)const
{
	//寻找链表中的第K个元素，并将其传送至X
	//如果不存在第K个元素，则返回false，否则返回true
	if (k<1) return false;
	ChainNode<T> *current=first;
	int index=1;//current的索引
	while(index<k&&current)
	{
		current=current->link;
		index++;
	}
	if (current){x=current->data;return true;}
	return false;//不存在第K个元素
}
//在链表中搜索
template<class T>
int Chain<T>::search(const T& x)const
{
	ChainNode<T> *current=first;
	int index=1;
	while(current && current->data!=x)
	{
		current=current->link;
		index++;
	}
	if(current) return index;
	return 0;
}
//输出链表
template<class T>
void Chain<T>::output(ostream& out)const
{
	ChainNode<T> *current;
	for(current=first;current;current=current->link)
		out<<current->data<<" ";
}
template<class T>
ostream& operator<<(ostream& out,const Chain<T>& x)
{x.output(out);return out;}
//从链表中删除一个元素
template<class T>
Chain<T>& Chain<T>::Delete(int k,T& x)
{
	if(k<1||!first)
		throw OutOfBounds();
	ChainNode<T> *p=first;
	if(k==1)
		first=first->link;
	else
	{
		ChainNode<T> *q=first;
		for(int index=1;index<k-1&&q;index++)
			q=q->link;
		if(!q||!q->link)
			throw OutOfBounds();
		p=q->link;
		if(p==last) last=q;
		q->link=p->link;	
	}
	x=p->data;
	delete p;
	return *this;
}
//向链表中插入元素
template<class T>
Chain<T>& Chain<T>::insert(int k,const T& x)
{
	if(k<0) throw OutOfBounds();
	ChainNode<T> *p=first;
	for (int index=1;index<k&&p;index++)
		p=p->link;
	if(k<0&&!p) throw OutOfBounds();
	ChainNode<T> *y=new ChainNode<T>;
	y->data=x;
	if(k)
	{
		y->link=p->link;
		p->link=y;
	}
	else
	{
		y->link=first;
		first=y;
	}
	if(!y->link) last=y;
	return *this;
}
//在链表右端添加一个元素
template<class T>
Chain<T>& Chain<T>::append(const T& x)
{
	ChainNode<T> *y;
	y= new ChainNode<T>;
	y->data=x;y->link=0;
	if(first)
	{
		last->link=y;
		last=y;
	}
	else
		first=last=y;
	return *this;
}
//链表遍历器类
template<class T>
class Chainiterator
{
	public:
		T* initialize(const Chain<T>& c)
		{
			location=c.first;
			if(location) return &location->data;
			return 0;
		}
		T* Next()
		{
			if(!location) return 0;
			location=location->link;
			if(location) return &location->data;
			return 0;
		}
	
	private:
		ChainNode<T> *location;
};
