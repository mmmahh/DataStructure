#pragma once

#include<iostream>
using namespace std;
class MyException
{
public:
	MyException(string message = "");
	void what() const;
private:
	string s;
};