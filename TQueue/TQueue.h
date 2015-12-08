#pragma once
#include <iostream>
using namespace std;

template <class T>
class TQueue
{
	int Begin,End,Len,MaxSize;
	T* Queue;
public:
	TQueue(int _MaxSize=10)
	{
		MaxSize=_MaxSize;
		Queue=new T[MaxSize];
		Begin=0;
		Len=0;
		End=-1;
	}

	TQueue(const TQueue& _q)
	{
		if (this!=*_q)
		{
			delete[] Queue;
			MaxSize=_q.MaxSize;
			Begin=_q.Begin;
			Len=_q.Len;
			End=_q.End;
			for (int i=0;i<Len;i++)
			{
				Queue[i]=_q.Queue[i];
			}
		}
		else
		
	}

	~TQueue(void)
	{
		delete[] Queue;
	}

	bool IsEmpty()
	{
		return (Len==0);
	}

	bool IsFull()
	{
		return (Len==MaxSize);
	}

	void Push(const T& Elem)
	{
		if (IsFull())
		{
			throw -1;
		}
		Queue[++End]=Elem;
		Len++;
	}

	T& Pop()
	{
		if (IsEmpty())
			throw -1;
		T tmp=Queue[Begin];
		if (Begin<MaxSize-1)
			Begin++;
		else
			Begin=0;
		Len--;
		return tmp;
	}

	void ShowQueue()
	{
		if (!IsEmpty())
			for (int i=0;i<=Len;i++)
				cout<<i<<" element is: "<<Queue[i]<<endl;
		else 
			cout<<"Queue is empty!"<<endl;
	}

	
};

