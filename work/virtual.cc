#include <iostream>
#include <string>
using namespace std;

class Base{
    private:
        string book;
    public:
        Base(string s):
            book(s) {}
        virtual void show() {cout <<"Base" << endl;}
        ~Base() {cout << "Base 析构函数！" << endl;}
        /* virtual ~Base() {cout << "Base 析构函数！" << endl;} */
};
class Case
{
    int cas;
    public:
        Case(int c):
            cas(c) {}
        ~Case() {cout << "Case希构函数" << endl;}
};

class Derived:public Base
{
    private:
        int d;
        char *c;
    public:
//        Base Bbase;
        /* friend Case; */
        Case cas;
        Derived(int i,string s,Case c):
            Base(s),d(i)，cas(c)
        {
            /* Case ccase(33); */
        }
        /* Derived(char *ch)
        {
        } */
        void show() {cout <<"Derived" << endl;}
        ~Derived() {cout <<"Derived 析构函数！" << endl;}
};

int main()
{
    Base b("A++");
    Case c(33);
    Base *base;
    Derived *derived = new Derived(12,"C++Primer",c);
    /* base = derived; */
    derived->show();
    /* Derived derived1(11,"qwe",b); */
}
