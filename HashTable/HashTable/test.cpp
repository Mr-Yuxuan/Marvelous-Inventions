#include"HashTable.hpp"
int main()
{
	HashTable<string,string> ht;
	ht.Insert("a", "������");
	ht.Insert("c", "������");
	ht.Insert("d", "����");
	ht.Insert("f", "����");
	ht.Insert("b", "��ӱ��");
	ht.Print();
	HashTable<int, int> ht1;
	ht1.Insert(1, 1);
	ht1.Insert(2, 3);
	ht1.Insert(4, 7);
	ht1.Insert(9, 15);
	ht1.Print();
	system("pause");
	return 0;
}