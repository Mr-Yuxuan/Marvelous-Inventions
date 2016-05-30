#include"BoolmFilter.hpp"
int main()
{
	/*BitMap bt(100);
	bt.Set(1);
	bt.Set(3);
	bt.Set(4);
	bt.Set(2);
	bt.Reset(2);
	cout<<bt.Test(1)<<endl;
	cout << bt.Test(2) << endl;
	cout << bt.Test(5) << endl;*/
	
	BoolmFilter bt(100);
	bt.Set("https://mail.qq.com/cgi-bin/frame_html?sid=Jrph6VXhLHM4XWUy&r=6c6bfef8543f7726178853031eef44f2");
	bt.Set("addd");
	bt.Set("cccc");
	bt.Set("qqqq");
	cout << bt.Test("https://mail.qq.com/cgi-bin/frame_html?sid=Jrph6VXhLHM4XWUy&r=6c6bfef8543f7726178853031eef44f2") << endl;
	cout << bt.Test("hhhh") << endl;
	cout << bt.Test("qqqq") << endl;
	system("pause");
	return 0;
}