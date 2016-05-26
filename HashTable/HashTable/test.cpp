#include"HashTable.hpp"
int main()
{
	HashTable<string,string> ht;
	ht.Insert("a", "´ŞÓêĞù");
	ht.Insert("c", "¼ÍÁ¢ĞÂ");
	ht.Insert("d", "¸¶ĞÀ");
	ht.Insert("f", "ºòÈï");
	ht.Insert("b", "ÕÔÓ±ÄÈ");
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