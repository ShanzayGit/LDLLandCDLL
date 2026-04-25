#ifndef DNODE_H
#define DNODE_H
template <typename T>
struct DNode
{
	T info;
	DNode<T>* prev;
	DNode<T>* next;
	DNode():info(0),prev(nullptr),next(nullptr)
	{}
	DNode(T val):info(val),prev(nullptr),next(nullptr)
	{}
};
#endif