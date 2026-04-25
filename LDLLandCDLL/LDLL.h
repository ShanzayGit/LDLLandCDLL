#ifndef LDLL_H
#define LDLL_H
#include"DNODE.h"
#include<iostream>
using namespace std;
template<typename T>
class LDLL
{
	DNode<T>* head;
	void reverseListRecer(DNode<T>* p, DNode<T>* q, DNode<T>* r)
	{
		if (r == nullptr)
		{
			q->next = p;
			q->prev = nullptr;
			head = q;
			return;
		}
		q->next = p;
		q->prev = r;
		p = q;
		q = r;
		r = r->next;
		reverseListRecer(p, q, r);
	}
public:
	class Iterator
	{
		DNode<T>* curr;
	public:
		Iterator() :curr(nullptr)
		{}
		Iterator(DNode<T>* Head) :curr(Head)
		{}
		bool operator !=(Iterator other)
		{
			return this->curr != other.curr;
		}
		typename Iterator& operator ++()
		{
			if (curr)
			{
				curr = curr->next;
				return *this;
			}
			else
				exit(0);
		}
		typename Iterator operator++(int)
		{
			if (curr)
			{
				DNode<T>* temp = curr;
				curr = curr->next;
				return temp;
			}
			exit(0);
		}
		typename Iterator& operator --()
		{
			if (curr)
			{
				curr = curr->prev;
				return *this;
			}
			else
				exit(0);
		}
		typename Iterator operator--(int)
		{
			DNode<T>* temp = curr;
			curr = curr->prev;
			return temp;
		}
		T& operator *()
		{
			if (curr == nullptr)
				exit(0);
			return curr->info;
		}

	};
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
	void reverseList()
	{
		if (isEmpty() || head->next == nullptr)
			return;
		DNode<T>* p = head;
		DNode<T>* q = head->next;
		DNode<T> *r= head->next->next;
		p->next = nullptr;
		p->prev = q;
		while (r)
		{
			q->next = p;
			q->prev = r;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		q->prev = nullptr;
		head = q;
	}
	void findPairs(LDLL<T>& l, int sum)
	{
		/*int endPoint = sum / 2;
		DNode<T>* p = head;
		while (p->info <= endPoint)
		{
			DNode<T>* q = p->next;
			while (q)
			{
				if (q->info + p->info == sum)
				{
					cout << "(" << p->info << "," << q->info << ")" << '\n';
				}
				q = q->next;
			}
			p = p->next;
		}*/
		if (head->next == nullptr)
			return;
		int endPoint = sum / 2;
		DNode<T>* p = head;
		while (p->info <= endPoint)
		{
			p = p->next;
		}
		if(p!=head)
		   p = p->prev;
		DNode<T>* r = p;
		while (r->next && p->info + r->next->info <= sum )
		{
			r = r->next;
		}
		if (p == r)
			r = r->next;
		while (p != head)
		{

			if (r->info + p->info == sum)
			{
				cout << "(" << p->info << " , " << r->info << " )\n";
				r = r->next;
				p = p->prev;
			}
			else if (r->info + p->info > sum)
			{
				p = p->prev;
			}

		}
		if(p->info+r->info==sum)
			cout << "(" << p->info << " , " << r->info << " )\n";

	}
	void reverseListRec()
	{
		if (isEmpty() || head->next == nullptr)
			return;
		DNode<T>* p = head;
		DNode<T>* q = head->next;
		DNode<T>* r = head->next->next;
		p->next = nullptr;
		p->prev = q;
		reverseListRecer(p, q, r);
	}
	LDLL():head(nullptr)
	{}
	~LDLL()
	{
		while (head)
			removeAtHead();
	}
	void print()
	{
		if (isEmpty())
			return;
		DNode<T>* p = head;
		//while (p->next)
		//{
		//	//cout << p->info << "\t";
		//	p = p->next;
		//}
		while (p)
		{
			cout << p->info<<"\t";
			p = p->next;
		}

	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (isEmpty())
		{
			head = p;
			return;
		}
		p->next = head;
		head->prev = p;
		head = p;
	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
		{
			return;
		}
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* p = head;
		while (p  && p->info != key)
			p = p->next;
		if (!p)
			return;
		DNode<T>* x = new DNode<T>(val);
		x->next = p;
		x->prev = p->prev;
		p->prev = x;
		x->prev->next = x;
		return;
	}
	void insertAtTail(T val)
	{
		if (isEmpty())
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* x = head;
		while (x->next != nullptr)
		{
			x = x->next;
		}
		DNode<T>* p = new DNode<T>(val);
		p->prev = x;
		x->next = p;
	}
	void insertAfter(T key,T val)
	{
		DNode<T>* x = head;
		if (isEmpty())
			return;
		while (x && key!= x->info  )
		{
			x = x->next;
		}
		if (x==nullptr)
			return;
		DNode<T>* p = new DNode<T>(val);
		p->prev = x;
		p->next = x->next;
		if(x->next!=nullptr)//if last entry insert at tail 
	    	x->next->prev = p;
		x->next = p;
		return;
	}
	void removeAtHead()
	{
		if (isEmpty())
			return;
		DNode<T>* p = head;
		head = p->next;
		if(head)//only one entry
		   head->prev = nullptr;
		delete p;
	}
	void removeAtTail()
	{
		if (isEmpty())
			return;
		if (head->next == nullptr)
		{
			removeAtHead();
			return;
		}
		DNode<T>* x = head->next;
		while (x->next)
			x = x->next;
		x->prev->next = x->next;
		delete x;
	}
	void remove(T key)
	{
		if (isEmpty())
		{
			return;
		}
		if (head->info == key)
		{
			removeAtHead();
			return;
		}

		DNode<T>* x = head->next;
		while (x && x->info != key)
			x = x->next;
		if (!x)
			return;
		x->prev->next = x->next;
		if (x->next)//if last entry
			x->next->prev = x->prev;
		delete x;
	}
	void removeAfter(T key)
	{
		if (isEmpty())
			return;
		DNode<T>* x = head;
		while (x->next && x->info != key)
			x = x->next;
		if (!x->next)
			return;
		if (!x->next->next)//second last element
		{
			removeAtTail();
			return;
		}
		DNode<T>* p = x->next;
		x->next->next->prev = x;
	    x->next = x->next->next;
		delete p;
	}
	void removeBefore(T key)
	{
		if (isEmpty())
			return;
		if (head->info == key)
			return;
		if (head->next->info == key)//head pointer update
		{
			removeAtHead();
			return;
		}
		DNode<T>* x = head->next->next;
		while (x && x->info != key)
			x = x->next;
		if (!x)
			return;
		DNode<T>* p = x->prev;

		x->prev->prev->next = x;
		x->prev = x->prev->prev;
		delete p;

	}
	
};
#endif

