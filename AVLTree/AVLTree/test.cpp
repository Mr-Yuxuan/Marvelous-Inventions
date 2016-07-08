#include"AVLTree.hpp"
void test()
{
	AVLTree<int, int> tl;
	int a1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (size_t i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
	{
		tl.Insert(a1[i], i);

	}
	tl.InOder();
	cout << tl.IsBlance() << endl;
	return;
}
void test2()
{
	AVLTree<int, int> t;
	int a1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < 10; ++i)
	{
		t.Insert(a1[i], i);
	}
	t.InOder();
	cout << t.IsBlance() << endl;
	return;

}
int main()
{
	test();
	system("pause");
	return 0;
}