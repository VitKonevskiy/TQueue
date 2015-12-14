#pragma once
#include <iostream>
#include <ctime>
using namespace std;


template <class T>
class TQueue
{
private:
	int begin;    
	int end;      
	int len;      
	T* mas;       
	int maxsize;  
public:
	TQueue(int _maxsize = 10);
	TQueue(const TQueue& Q);
	~TQueue<T>(){ delete[] mas; }


	bool IsEmpty();       
	bool IsFull();        
	void Push(const T n); 
	T Pop();              
	int GetMaxsize()
	{
		return maxsize;
	}
	int GetLen()
	{
		return len;
	}
	void OutputQueue();
	
};//----------------------------------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int _maxsize)
{
	maxsize = _maxsize;
	mas = new T[maxsize];
	begin = 0;
	end = -1;
	len = 0;
}/*-------------------------------------------------------------------------*/

template <class T>
TQueue<T>::TQueue(const TQueue& Q)
{
	maxsize = Q.maxsize;
	mas = new T[maxsize];
	for (int i = 0; i < maxsize; i++)
		mas[i] = Q.mas[i];
	begin = Q.begin;
	end = Q.end;
	len = Q.len;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsEmpty()
{
	if (len == 0)
		return true;
	return false;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsFull()
{
	if (len == maxsize)
		return true;
	return false;
}/*-------------------------------------------------------------------------*/

template <class T>
void TQueue<T>::Push(const T n)
{
	if (IsFull())
		printf("Queue is Full\n");
	else
	{
		if (end < (maxsize - 1))
			end++;
		else
			end = 0;
		mas[end] = n;
		printf("Push:%d\n", mas[end]);
		len++;
	}
}/*-------------------------------------------------------------------------*/

template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
		//throw - 1;
		printf("Queue is Empty\n");
	else
	{
		T tmp = mas[begin];
		if (begin < (maxsize - 1))
			begin++;
		else
			begin = 0;
		len--;
		printf("Pop:%d\n",tmp);
		return tmp;
	}
}/*-------------------------------------------------------------------------*/
 template <class T>
void TQueue<T>::OutputQueue()
{
	if (!IsEmpty())
	for (int i = 0; i < len; i++)
		cout << i << " In Queue: " << mas[i] << endl;
	else
		cout << "Queue is empty!" << endl;
}/*-------------------------------------------------------------------------*/


double GenerateRand()
{
	double a, b, tmp;

	a = 1 + rand() % 100; // 1 .. 10000
	/*b = 1 + rand() % 100; // 1 .. 10000
	if (a < b)
		tmp = a / b;
	else
		tmp = b / a;*/
	tmp = a / 100;
	return tmp;
}/*-------------------------------------------------------------------------*/