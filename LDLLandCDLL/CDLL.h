#ifndef CDLL_H
#define CDLL_H
#include<iostream>
using namespace std;
#include"DNODE.h"
template <typename T>
class CDLL
{
	DNode<T>* head;
public:
	class iterator
	{
		DNode<T>* curr;
		DNode<T>* const start;
	public:
		iterator() :curr(nullptr)
		{}
		iterator(DNode<T>* Head) :curr(Head), start(Head)
		{}
		bool operator !=(iterator other)
		{
			return this->curr != other.curr;
		}
		typename iterator& operator ++()
		{
			if (curr)
			{
				if (curr->next == start)
					curr = nullptr;
				else
					curr = curr->next;
				return *this;
			}
			else
				exit(0);
		}
		typename iterator operator++(int)
		{
			if (curr)
			{
				DNode<T>* temp = curr;
				curr = curr->next;
     			return temp;
			}
			return curr;
		}
		typename iterator& operator --()
		{
			if (curr)
			{
				if (curr->prev == start)
					curr = nullptr;
				else
				curr = curr->prev;
				return *this;
			}
			else
				exit(0);
		}
		typename iterator operator--(int)
		{
			if (curr)
			{
				DNode<T>* temp = curr;
				curr = curr->prev;
				return temp;
			}
			exit(0);
		}
		T& operator *()
		{
			if (curr == nullptr)
				exit(0);
			return curr->info;
		}

	};
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	CDLL():head(nullptr)
	{}
	~CDLL()
	{
		while (head)
			removeAtHead();
	}
	void print()
	{
		if (!head)
			return;
		DNode<T>* p = head;
		do
		{
			cout << p->info<<'\t';
			p = p->next;
		} while (p != head);

	}

	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (!head)
		{
			head = p;
			p->next = p->prev = p;
			return;
		}
		p->prev = head->prev;
		head->prev->next = p;
		p->next = head;
		head->prev = p;
		head = p;
		return;
	}
	void insertAtTail(T val)
	{
		if (!head)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* x = head->prev;
		DNode<T>* p = new DNode<T>(val);
		p->next = x->next;
		p->prev=x;
		x->next = p;
		head->prev = p;
		return;
	}
	void insertBefore(T key, T val)
	{
		if (!head)
			return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
	    }
		DNode<T>* x = head->next;
		while (x != head && x->info != key)
		{
			x = x->next;
		}
		if (x == head)
			return;
		DNode<T>* p = new DNode<T>(val);
		p->prev = x->next;
		p->next = x;
		x->prev->next = p;
		x->prev = p;
		return;
	}
	void insertAfter(T key, T val)
	{
		if (!head)
			return;
		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				x->next = p->next;
				x->prev = p;
				p->next->prev = x;
				p->next = x;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	void removeAtHead()
	{
		if (!head)
			return;
		if (head->next == head)
		{
			DNode<T>* p = head;
			head = nullptr;
			delete p;
			return;
		}
		DNode<T>* x = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete x;
		return;
	}
	void removeAtTail()
	{
		if (!head)
			return;
		if (head->next == head)
		{
			removeAtHead();
			return;
		}
		DNode<T>* x = head->prev;
		x->prev->next = x->next;
		head->prev = x->prev;
		delete x;
	}
	void removeBefore(T key)
	{
		if (!head)
			return;
		if (head->info == key)
		{
			removeAtTail();
			return;
		}
		if (head->next->info == key)
		{
			removeAtHead();
			return;
		}
		DNode<T>* x = head->next->next;
		while (x != head && x->info!=key)
		{
			x = x->next;
		} 
		if (x->info == key)
		{
			DNode<T>* p = x->prev;
			x->prev->prev->next = x;
			x->prev = x->prev->prev;
			delete p;
			return;
		}
		return;
	}
	void removeAfter(T key)
	{
		if (!head)
			return;
		if (head->prev->info == key)
		{
			removeAtHead();
			return;
		}
		DNode<T>* x = head;
		do
		{
			if (x->info == key)
			{
				DNode<T>* p = x->next;
				x->next->next->prev = x;
				x->next = x->next->next;
				delete p;
				return;
			}
			x = x->next;
		} while (x != head);
	}
	void remove(T key)
	{
		if (!head)
			return;
		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				if (head == p)
					head = p->next;
				delete p;
				return;
			}
			p = p->next;
		} 
		while (p != head);
		return;
	}
	void swap(int first, int second)
	{
		if (first == second)
			return;
		DNode<T>* r = head;
		int count = 0;
		do
		{
			count++;
			r = r->next;
		} while (r != head);
		if (first <= 0 || second <= 0 || first > count || second > count)
			return;
		int n1, n2;
		if (first < second)
		{
			n1 = first;
			n2 = second;
		}
		else
		{
			n1 = second;
			n2 = first;
		}
		DNode<T>* p = head;
		DNode<T>* q = head;
		int i = 1;
		while (i != n1)
		{
			p = p->next;
			i++;
		}
		int j = 1;
		while (j != n2)
		{
			q = q->next;
			j++;
		}
		if (n1 == 1 && n2 == count)
		{
			DNode<T>* A = q->next;
			DNode<T>* B = p->prev;
			p->next->prev = q;
			q->prev->next = p;
			q->next = p->next;
			p->next = q;
			p->prev = q->prev;
			q->prev = p;
			head = q;
			return;
		}
		if (n1 == 1 && n2 != 2)
		{
			DNode<T>* A = q->next;
			DNode<T>* B = p->prev;
			q->prev->next = p;
			p->next->prev = q;
			q->next->prev = p;
			p->prev->next = q;
			q->next = p->next;
			p->next = A;
			p->prev = q->prev;
			q->prev = B;
			head = q;
			return;
		}
		if (n1 - n2 == 1 || n1 - n2 == -1)
		{
			if (n1 != 1)
			{
				p->prev->next = q;
				q->next->prev = p;
				p->next = q->next;
				q->next = p;
				q->prev = p->prev;
				p->prev = q;
				return;
			}
			else
			{
				p->next = q->next;
				q->next->prev = p;
				q->next = p;
				p->prev->next = q;
				q->prev = p->prev;
				p->prev = q;
				head = q;
				return;
			}
		}
		DNode<T>* A = p->next;
		DNode<T>* B = q->prev;
		p->prev->next = q;
		q->next->prev = p;
		p->next->prev = q;
		q->prev->next = p;
		q->prev = p->prev;
		p->next = q->next;
		p->prev = B;
		q->next = A;
		return;
	}
};
#endif