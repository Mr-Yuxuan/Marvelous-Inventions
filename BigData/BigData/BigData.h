#pragma once
#define _CRT_SECURE_NO_DEPRECATE 1
#include<iostream>
#include<string>
#include<assert.h>
#define MAXINT64  9223372036854775807
#define MININT64 -9223372036854775807
using namespace std;
class BigData
{
public:
	friend ostream& operator<<(ostream& os, const BigData d);
	BigData(long long value=0);
    BigData(const char* data);
	BigData operator*(BigData b);
	BigData operator+(BigData b);
	BigData operator-(BigData b);
	BigData operator/(BigData b);
protected:
	void Itoa(long long value);
	bool IsOvOfSum(long long Lvalue, long long Rvalue);
	bool IsOvOfMul(long long Lvalue, long long Rvalue);
	long long Aoti(const char* data,int& state);
	size_t Disgit(long long value);
	char* _Add(string& left, string& right, string& s);
	char* _Sub(string& left, string& right, string& s);
	char* _Mul(string& left, string& right, string& s);
	char* _Div(string& left, string& right, string& s);
	bool LeftBig(char* pleft, size_t plsize, char* pright, size_t prsize);
	size_t SubLoop(char* &pleft, size_t& plsize, char* pright, size_t prsize);
private:
	string _sdata;
	long long _value;
	bool _isvalueov;
};
