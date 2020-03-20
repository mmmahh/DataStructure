#include<iostream>
#include<ctime>
#include<windows.h>
#include"myException.h"
#include "testFunction.h"
#include"_03_stack.h"
#include"_04_queue.h"
#include"_11_matrix.h"
#include"_23_heap.h"
#include"_31_graph.h"
#include"graphAlgorithm.h"
#include"_41_sorting.h"
void test_03_stack()
{
	cout << "/*******test for 03 stack********/" << endl;
	cout << "initial stack(10):";
	Stack s(10);
	cout << "initial success" << endl;
	cout << "test function push:";
	try
	{
		for (int i = 0; i < 20; i++)
		{
			cout << "begin push(" << i << ")......";
			s.push(i);
			cout << "push success, stack lenght: "<<s.length()<< endl;
		}
	}
	catch (const MyException & error)
	{
		error.what();
	}
	cout << "test Top:" << s.Top() << endl;
	cout << "test pop:";
	try
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "begin pop("<<s.pop()<<")";
			cout << "pop success" << endl;
		}
	}
	catch (const MyException & error)
	{
		error.what();
	}
	cout << "test clear:stack length:" << s.length();
	s.clear();
	cout << " after clear stack length:" << s.length() << endl;
}

void test_04_queue()
{
	cout << "test for AQueue:" << endl;
	AQueue aqueue(10);
	try
	{
		for (int i = 0; i < 20; i++)
		{
			cout << "enqueue(" << i << ")......";
			aqueue.enqueue(i);
			cout << "success";
			cout << "length:" << aqueue.Length() << endl;

		}
	}
	catch (const MyException & error)
	{
		error.what();
	}
	try
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "dequeue(" << aqueue.dequeue() << ")" << "success ";
			cout<< "length:" << aqueue.Length() << endl;
		}
	}
	catch (const MyException& error)
	{
		error.what();
	}
	cout << "front value:" << aqueue.frontValue() << endl;
	cout << "clear...";
	aqueue.clear();
	cout << "length:" << aqueue.Length() << endl;
	cout << "print:";
	aqueue.printQueue();
	cout << endl;

	cout << "test for LQueue:" << endl;
	LQueue lqueue;
	try
	{
		for (int i = 0; i < 20; i++)
		{
			cout << "enqueue(" << i << ")......";
			lqueue.enqueue(i);
			cout << "success";
			cout << "length:" << lqueue.Length() << endl;

		}
	}
	catch (const MyException & error)
	{
		error.what();
	}
	try
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "dequeue(" << lqueue.dequeue() << ")" << "success ";
			cout<<"length:"<< lqueue.Length() << endl;
		}
	}
	catch (const MyException & error)
	{
		error.what();
	}
	cout << "front value:" << lqueue.frontValue() << endl;
	cout << "clear...";
	lqueue.clear();
	cout << "length:" << lqueue.Length() << endl;
	cout << "print:";
	lqueue.printQueue();
	cout << endl;
}

void test_11_matrix()
{
	cout << "test for Matrix" << endl;
	Matrix mat(4, 5, 0);
	cout << "set matrix:";
	mat.set(0, 0, 4);
	mat.set(0, 1, 8);
	mat.set(1, 3, 9);
	mat.set(2, 3, 7);
	mat.set(3, 1, 1);
	cout << "print:" << endl;
	mat.printMatrix();
	cout << "get:" << endl;
	cout<<mat.get(2, 3)<<endl;
	cout << "transpose:" << endl;
	try 
	{
		mat.transpose();
	}
	catch (const MyException & error)
	{
		error.what();
	}
	mat.printMatrix();

	cout << "test for SymmetricMatrix:" << endl;
	SymmetricMatrix smat(4, 0);
	cout << "set:" << endl;
	smat.set(3, 3, 4);
	smat.set(1, 3, 8);
	smat.set(0, 2, 9);
	smat.set(2, 1, 3);
	smat.printMatrix();
	cout << "get:" << endl;
	cout << smat.get(1, 3) << " " << smat.get(2, 0) << endl;

	cout << "test for SparseMatrix" << endl;
	SparseMatrix spmat;
	spmat.init(mat);
	cout << "print:" << endl;
	spmat.printMatrix();
	cout << "fastTrans and print:" << endl;
	spmat.fastTrans();
	spmat.printMatrix();
}

void test_graphTraversal()
{
	GraphM g(10);
	g.setEdge(0, 1, 1); g.setEdge(1, 0, 1);
	g.setEdge(0, 4, 1); g.setEdge(4, 0, 1);
	g.setEdge(0, 5, 1); g.setEdge(5, 0, 1);
	g.setEdge(1, 8, 1); g.setEdge(8, 1, 1);
	g.setEdge(2, 3, 1); g.setEdge(3, 2, 1);
	g.setEdge(2, 6, 1); g.setEdge(6, 2, 1);
	g.setEdge(2, 8, 1); g.setEdge(8, 2, 1);
	g.setEdge(2, 9, 1); g.setEdge(9, 2, 1);
	g.setEdge(5, 6, 1); g.setEdge(6, 5, 1);
	g.setEdge(5, 7, 1); g.setEdge(7, 5, 1);

	cout << "test DFS:" << endl;
	DFS(g);
	cout << "\ntest BFS:" << endl;
	BFS(g);
	cout << endl;
}

void test_Dijkstra()
{
	GraphM g(10);
	g.setEdge(0, 1, 2); g.setEdge(1, 0, 2);
	g.setEdge(0, 4, 2); g.setEdge(4, 0, 2);
	g.setEdge(0, 5, 4); g.setEdge(5, 0, 4);
	g.setEdge(1, 8, 1); g.setEdge(8, 1, 1);
	g.setEdge(2, 3, 8); g.setEdge(3, 2, 8);
	g.setEdge(2, 6, 5); g.setEdge(6, 2, 5);
	g.setEdge(2, 8, 7); g.setEdge(8, 2, 7);
	g.setEdge(2, 9, 3); g.setEdge(9, 2, 3);
	g.setEdge(5, 6, 1); g.setEdge(6, 5, 1);
	g.setEdge(5, 7, 9); g.setEdge(7, 5, 9);
	cout << "test Dijkstra:" << endl;
	Dijkstra(g);
}

void test_23_heap()
{
	const int n = 20;
	cout << "test MinHeap:" << endl;
	MinHeap heap(n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 50;
		heap.push(x);
	}
	heap.printHeap();

	cout << endl;
	cout << "pop("<<heap.top()<<")" << endl;
	heap.pop();
	heap.printHeap();

	cout << endl;
	Sleep(2000);
}
/**********************************************/
void printArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}
void getUnsortedArray(int* array, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		int j = rand() % n;
		swap(array[i], array[j]);
	}
}
void test_41_sorting()
{
	const int n = 20;
	const int sleeptime = 1000;
	int array[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % n;
	}
	int temp[n];
	cout << "test sort" << endl;
	//
	cout << "test insertSort:" << endl;
	cout << "unsort: ";
	printArray(array, n);
	insertSort(array, n);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test bubbleSort:"<<endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	bubbleSort(array, n);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test selectSort:" << endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	selectSort(array, n);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test shellSort:" << endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	shellSort(array, n);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test mergeSort:" << endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	mergeSort(array, temp, 0, n-1);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test quickSort:" << endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	quickSort(array, 0, n - 1);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
	//
	cout << "test heapSort:" << endl;
	cout << "unsort: ";
	getUnsortedArray(array, n);
	printArray(array, n);
	heapSort(array, n);
	cout << "\nsorted: ";
	printArray(array, n);
	cout << endl;

	Sleep(sleeptime);
}