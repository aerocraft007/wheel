// 提供了一个简单的字符串比较函数，指针参数，用户手动输入两个字符串后
//进行比较
//对指针与字符数组的内存分配有了初步的认识
#include <iostream>
#include <string>
//#include "stdafx.h"
using namespace std;//错误2，忘记了
int StrCmp(char* p1,char* p2)
{
	for(;*p1!='\0'||*p2!='\0';p1++,p2++)//群里有人建议改成&&但是hello,helloo，返回值为0;
		if(*p1!=*p2)
			return *p1-*p2;
	return 0;
}

int main()//直接改成这样的形式，而不是tmain带参数形式，去不使用预编译头
{
	//char* a,b;//错误1
  // char *a，*b;//错误
	//char *a;
	//char *b;
 // 	cout<<"a=";
	//cin>>a;
	//cout<<endl<<"b=";
	//cin>>b;   //错误3
	
	//char* a1;
	//char* b1;
	//cout<<"a=";
	//cin>>*a1;
	//cout<<endl<<"b=";
	//cin>>*b1;  
	//a=a1;b=b1;//错误四

	//getline(cin,*a);
	//getline(cin,*b);

	//cin.get(a,)
//一直想动态输入字符串，而不是用数组,不要忘记为数组和动态内存赋初值。防止将未被初始化的内存作为右值使用。
	//所以，一定要记住给指针做初始化
	char *a,*b;
	a = NULL;//后面初始化，分配内存，故此句并无大的用处；但是给其NULL是一个非常好的习惯
	int n1, n2;//用户输入用来表示自己想要的字符串大小；
	cin>>n1;
	a = (char*)malloc(sizeof(char)*(n1+1));
	memset(a,0,n1+1);
	if(a)//一定要判断初始化后是否开辟了正确的内存空间而不是NULL
	cin>>a;
	cin>>n2;
	b = (char*)malloc(sizeof(char)*(n2+1));
	memset(b,0,n2+1);
	if(b)
	cin>>b;
	int c;
	c= StrCmp(a,b);//对于边际及容错性，还有待考虑
	free(a);
	free(b);//释放内存
	a = NULL;//释放内存后指针必须指向NULL，否则成为乱码
	b = NULL;
	return 0;
}
/*在程序执行时，遇到问题，cin>>a处崩掉
是*/

/*
内存的使用规则
  1.在使用malloc()或new申请空间时,要检查有没有分配空间成功,判断方法是判断指针是否为NULL,如申请一块很大的内存而没有这么大的内存则分配内存会失败
  2.申请成功后最好是将该内存清空,使用memset()后ZeroMemory()清空,不然存在垃圾而造成有时候输出很大乱码
  3.不要忘记为数组和动态内存赋初值。防止将未被初始化的内存作为右值使用。(特别注意)
  4.要防止数组或指针内存越界,
  5.申请内存成功后,使用结束后要释放,系统不会自动释放手动分配的内存
  6.内存释放后,指针还是指向那块地址,不过这指针已经是"野指针"了,所以释放内存后指针要指向NULL,不然很危险,容易出错,if()对野指针的判断不起作用
*/