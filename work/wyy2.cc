#include <iostream>
#include <string>
using namespace std;

inline string isshorter(string s1, string s2)
{
    return s1.length() < s2.length() ? s1:s2 ;
}
/*string 类型不是字面值类型
constexpr string Isshorter(string s1, string s2)
{
    return s1.length() < s2.length() ? s1:s2 ;
}
*/

constexpr int low(int a1, int a2)
{
    return a1 < a2? a1:a2;
}

void f()
{
    cout << "f()" <<endl;
}
/*
void f(int a)
{
    cout << "f(int)" << endl;
}
*/
void f(int a ,int b)
{
    cout << "f(int ,int)\t" ;
    cout << a << "+" << b << "=" << a+b << endl;
}

void f(double a, double b = 3.14)
{
    cout << "f(double,double)\t";
    cout << a << "+" << b << "=" << a+b << endl;
}

int main()
{
    string s1 = "hello",s2 = "goodbye";
    cout << isshorter(s1,s2) << endl;
    cout << low(3,4) << endl;

    f();
   // f(2,1.1);
   // f(1.1,2);
    f(2,1);
    f(3);
    f(2.1,3.1);
    return 0;
}
