#include<iostream>
#include"myException.h"
using namespace std;
MyException::MyException(string message)
{
	s = message;
}
void MyException::what() const
{
	 cout << "ERROR: " <<s << "." << endl; 
}