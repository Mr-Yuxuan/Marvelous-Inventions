
#include"HuffamCompress.hpp"
#include<time.h>
int main()
{
	/*__Trace("test");*/
	clock_t  a = clock();
	test3();
	clock_t  b = clock();
	cout << "ѹ��ʱ�䣺" << (b - a) / 1000 << "s" << endl;
	clock_t  c = clock();
	test4();
	clock_t  d = clock();
	cout << "��ѹʱ�䣺" << (d - c) / 1000 << "s" << endl;
	system("pause");
	return 0;
}