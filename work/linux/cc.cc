#include<iostream>
#include <stdint.h>
#include <string>
#pragma pack(2)
using namespace std;

class base
{
    int a;
    char b;
    char b1;
    struct{
        int a1;
        //char b2;
        double d;
    };
    union{
        int a2;
        char b3;
        //double d1;
    };
};

struct A{
    double t;
    char b;
    int a;
    short c;
};

struct B{
    char b;
    double t;
    int a;
    short c;
};

class classA{
    int i;
    union U
    {
        char buff[13];
        int i;
    };
    void foo() {}
    typedef char * (*f)(void *);
    enum{red,green,blue} color;
}classa;

int main()
{
    cout <<"bool:"<< sizeof(bool)<< endl;
    cout <<"short:"<< sizeof(short)<< endl;
    cout <<"char:" << sizeof(char) << endl;
    cout << "int:" << sizeof(int) << endl;
    cout << "float:" << sizeof(float) << endl;
    cout << "double:" << sizeof(double) << endl;
    cout << "long:" << sizeof(long) << endl;
    cout << "long long:" << sizeof(long long) << endl;
    cout << "class base:" << sizeof(base) << endl;
    cout << "struct A:" << sizeof(A) << " struct B:" << sizeof(B) << endl;
    cout << "string " << sizeof(string) << endl;
    uint32_t a[10];
    uint32_t b;
    cout << "uint32 " << sizeof(b) << endl;
    /* unsigned int32 a[10]; */
    cout << "uint32 * 10 = " << sizeof(a) << endl;
    int (*n)[10];
    cout << "int (*n)[10] = " << sizeof(n) << endl;
    cout << "unsigned int " << sizeof(unsigned int) << endl;
    cout << "classa:" << sizeof(classa) << endl;

    enum{red,green,blue,yellow,black} color;
    cout << "enum:"<< sizeof(color) << endl;
    return 0;
}
