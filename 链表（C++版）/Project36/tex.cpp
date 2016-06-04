#include "Slist.h"
void test1()
{
	Slist s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.PopBack();
	s.PushFront(5);
	cout << s << endl;
}
void test2()
{
	Slist s;
	s.PushFront(5);
	s.PushFront(4);
	s.PushFront(3);
	s.PushFront(2);
	/*s.PopFront();*/
	Node* ret = s.Find(4);
	/*s.Insert(ret, 7);
	s.Reverse();*/
	s.EarseNotTail(ret);
	cout << s<< endl;
}
void test3()
{
	Slist s;
	s.PushBack(1);
	s.PushBack(8);
	s.PushBack(3);
	s.PushBack(2);
	s.Sort();
	s.Remove(2);
	cout << s << endl;
}
void test4()
{
	Slist s;
	s.PushBack(1);
	s.PushBack(8);
	s.PushBack(3);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(3);
	s.PushBack(4);
	s.PushBack(8);
	/*s.RemoveAll(3);*/
	s.DelKNode(5);
	cout << s << endl;
}
void test5()
{
	Slist s;
	s.PushFront(5);
	s.PushFront(4);
	s.PushFront(3);
	s.PushFront(2);
	s.PushFront(1);
	Node* ret = s.FindMidNode();
	cout << ret->_data << endl;
}
void test6()
{
	Slist s1;
	Slist s2;
	s1.PushBack(1);
	s1.PushBack(3);
	s1.PushBack(5);
	s1.PushBack(7);
	s2.PushBack(2);
	s2.PushBack(4);
	s2.PushBack(6);
	s2.PushBack(8);
	Slist s3;
	s3._Merge(s1, s2);
	cout << s3 << endl;
}
void test7()
{
	Slist s1;
	Slist s2;
	s1.PushBack(1);
	s1.PushBack(3);
	s1.PushBack(5);
	s1.PushBack(7);
	s2.PushBack(2);
	s2.PushBack(4);
	s2.PushBack(6);
	s2.PushBack(8);
	Node* ret = s1.Find(5);
	Node* cur = s2.Find(8);
	cur->next = ret;
	/*cur = GetLinkCross(s1, s2);*/
	/*cout << cur->_data << endl;*/
}
int main()
{
	test6();
	system("pause");
	return 0;
}