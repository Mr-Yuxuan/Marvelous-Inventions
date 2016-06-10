#include<iostream>
#include"SmartPtr.hpp"
using namespace std;
void AutoTest()
{
	
	AutoPtr<A> ptr1(new A);
	AutoPtr<A> ptr2(ptr1);
	AutoPtr<A> ptr3;
	ptr3 = ptr2;
	ptr3->_a = 4;
	AutoPtr<int> ptr4(new int(1));
	*ptr4 = 5;
}

void SharedTest()
{
	SharedPtr<int> sptr1(new int(1));
	SharedPtr<int> sptr2(sptr1);
	SharedPtr<int> sptr3;
	sptr3 = sptr2;
	SharedPtr<int> sptr4(new int(2));
	sptr1 = sptr4;
}
void ScopedArryTest()
{
	
	ScopedArry<int> sptr(new int[10]);
	sptr[5] = 6;
	sptr[1] = 3;
}
void SharedArryTest()
{
	SharedArry<int> sptr1(new int[10]);
	SharedArry<int> sptr2(sptr1);
	SharedArry<int> sptr3;
	sptr3 = sptr2;
	SharedArry<int> sptr4(new int[20]);
	sptr1 = sptr4;
}
int main()
{
	AutoTest();
	/*ScopedTest();*/
	SharedTest();
	ScopedArryTest();
	SharedArryTest();
	system("pause");
	return 0;
}
