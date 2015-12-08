#include "TQueue.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	TQueue<int> q(3);
	if(q.IsEmpty())
		cout<<q.IsEmpty()<<endl;
	if(!q.IsFull())
		cout<<q.IsFull()<<endl;
	int El=-3;
	q.ShowQueue();
	q.Push(El);
	q.Push(El);
	q.Push(El);
	q.ShowQueue();
	El=-8;
	El=q.Pop();
	q.ShowQueue();
	cout<<endl<<El<<endl;
	return 0;
}