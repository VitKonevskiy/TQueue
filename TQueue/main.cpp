#include "TQueue.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	TQueue<int> Queue(50);
	double p;		//	probability - Push
	double q;		// probability - Pop
	double ourP;
	double ourQ;
	int tmp;
	int El = 7;


	/*if (Queue.IsEmpty())
		cout << Queue.IsEmpty() << endl;
	if (!Queue.IsFull())
		cout << Queue.IsFull() << endl;
	
	Queue.OutputQueue();
	Queue.Push(El);
	Queue.Push(El);
	Queue.Push(El);
	Queue.OutputQueue();
	El=-8;
	El = Queue.Pop();
	Queue.OutputQueue();
	cout<<endl<<El<<endl;
	*/


	printf("Input probability: p*=");
	scanf("%lf", &p);
	printf("p*=%lf\n",p); //Test

	printf("Input probability: q*=");
	scanf("%lf", &q);
	printf("q*=%lf\n", q); //Test
	for (int i = 0; i < 100; i++)
	{	
		ourP = GenerateRand();
		ourQ = GenerateRand();
		//printf("ourP=%lf,ourQ=%lf\n", ourP, ourQ);
		if (ourP < p)
			Queue.Push(El);
		if (ourQ < q)
			tmp=Queue.Pop();
	}

	return 0;
}