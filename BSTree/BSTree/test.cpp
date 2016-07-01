#include"BSTree.hpp"
void Test1()
{
	BSTree<int, int> b;
	int a[] = { 1, 3, 6, 7, 2, 8, 0 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		b.InsertR(a[i], i);
	}
	b.InOder();
	cout<<b.IsBlanceTree()<<endl;
	b.RemoveR(7);
	b.RemoveR(6);
	b.RemoveR(8);
	b.RemoveR(0);
	b.RemoveR(3);
	b.RemoveR(2);
	b.RemoveR(1);
	b.InOder();
	return;
}
int main()
{
	Test1();
	system("pause");
	return 0;
}