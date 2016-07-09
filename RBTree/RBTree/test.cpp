#include"RBTree.hpp"
void test()
{
	RBTree<int, int> rb;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		rb.Insert(a[i],i);
	}
	cout << rb.IsBlance() << endl;
	return;
}
void test1()
{
	RBTree<int, int> rb;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		rb.Insert(a[i], i);
	}
	cout << rb.IsBlance() << endl;
	return;
}
int main()
{
	test();
	system("pause");
	return 0;
}