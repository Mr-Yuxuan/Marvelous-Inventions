
#include"HuffamCompress.hpp"
#include<time.h>
int main()
{
	/*__Trace("test");*/
	clock_t  a = clock();
	test3();
	clock_t  b = clock();
	cout << "压缩时间：" << (b - a) / 1000 << "s" << endl;
	clock_t  c = clock();
	test4();
	clock_t  d = clock();
	cout << "解压时间：" << (d - c) / 1000 << "s" << endl;
	system("pause");
	return 0;
}