#include"HashTable.hpp"
int main()
{
	HashTable<string, string> ht;
	
	ht.Insert("aaa", "deyi");
	ht.Insert("bbb", "deyi");
	ht.Insert("ccc", "deyi");
	ht.Insert("ddd", "deyi");
	ht.Remove("aaa");
	HashTable<string, string> ht1;
	ht1 = ht;
	/*test();*/
	system("pause");
	return 0;
}