#include <iostream>
#include <string>
using namespace std;
#define String_d char*
typedef char* String_t;


static int age;
void foo()
{
    static int price = 2;
    price++;
    cout << "   price=" << price ;
}

static void foo1()
{
    cout << "foo1" << endl;
    foo();
    cout << age << endl;
}

int main()
{
    /* static int m; */
    age++;
    for(int i = 0; i < 5 ;i++)
        foo();
    cout  << "\nage " << age << endl;

    char p[] = "hello";
    /* char *p = ch; */
    String_d a,b;
    a = p;
    a[2] += ('A'-'a');
    /* b = p;b是一个char类型而不是一个char*
    typedef *String_t 定义了一个新的类型别名，有类型检查。而#define String_d char * 只是做了个简单的替换，无类型检查，前者在编译的时候处理，后者在预编译的时候处理。
    同时定义多个变量的时候有区别，主要区别在于这种使用方式String_t a,b; String_d c,d; a,b ,c 都是char*类型，而d 为char 类型
    由于typedef 还要做类型检查。。#define 没有。。所以typedef 比#define 安全。。
    */
    b = p[0];
    String_t c,d;
    c = p; d = p;
    cout << a <<" "<< b <<" " << c << " " << d << endl;


    foo1();
    return 0;
}
