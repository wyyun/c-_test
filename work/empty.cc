#include <iostream>
using namespace std;

class A{
};

class A1:public A
{};

class A2:public A
{};

class A3:public A1,public A2
{};

class B{
};

class B1:virtual public B
{};

class B2:virtual public B
{};

class B3:virtual public B1,public B2
{};

class Base1{
    public:
        int a;
        Base1(int i):
            a(i) {}
        virtual void show() {cout << "Base1 a = " << a << endl;}
};
class Base2{
    public:
        int b;
        Base2(int i):
            b(i) {}
        void show() {cout << "Base2 b = "<< b << endl;}
};

class Derived1:public Base1,public Base2
{
    public:
        int d;
        Derived1(int i1,int i2,int i3):
            Base1(i1),Base2(i2),d(i3) {}
        void show() {cout << "Derived1 d = "<< d << endl;}
};

int main()
{
    cout <<"sizeof(A):" << sizeof(A) << " sizeof(A1):" <<sizeof(A1) <<" sizeof(A2):" << sizeof(A2) << " sizeof(A3):"<< sizeof(A3)<< endl;
    cout <<"sizeof(B):" << sizeof(B) << " sizeof(B1):" <<sizeof(B1) <<" sizeof(B2):" << sizeof(B2) << " sizeof(B3):"<< sizeof(B3)<< endl;
    A a; A1 a1;
    cout << &a << "\t" << &a1 << endl;
    B b; B1 b1;
    cout << &b << "\t" << &b1 << "\n\n"<< endl;

    Derived1 derived1(1,2,3);
    cout <<"派生类的首地址：" << &derived1 <<"\tsizeof 派生类：" << sizeof(derived1);
    cout << "\t" << derived1.a <<"\t" <<derived1.b <<"\t" << derived1.d << endl;


    Base1 *pb1 = &derived1;
    cout <<"第一个基类指针指向的首地址："<<pb1 <<"\tsizeof(*pb1):"<<sizeof(*pb1);
    /*pb1是指向Base1的指针，发生了切割，不能访问Derived1的其它成员*/
    /* cout << pb1->a <<"\t" <<pb1->b <<"\t" << pb1->d << endl; */
    cout << "\tBase1中第一个int变量的地址" << &(pb1->a);
    cout << "\ta = " << pb1->a << endl;

    Base2 *pb2 = &derived1;
    cout <<"第二个基类指针指向的首地址："<<pb2 <<"\tsizeof(*pb2):"<<sizeof(*pb2) ;
    /*pb2是指向Base2的指针，发生了切割，不能访问Derived1的其它成员*/
    /* cout << pb2->a <<"\t" <<pb2->b <<"\t" << pb2->d << endl; */
    cout << "\tBase2中第一个int变量的地址" << &(pb2->b);
    cout << "\tb = " << pb2->b << endl;

    Derived1 *pd1;
    /*不能将父类的对象或指针或者引用赋值给子类*/
    /* pd1 = pb1; */
    pd1 = &derived1;
    cout << "Derived1派生类的首地址：" << &derived1 <<"\t派生类中一个int元素地址:" << &(pd1->a) << endl;
    cout <<"\t派生类中第二个int元素地址：" << &(pd1->b) <<"\t派生类中第三个int元素地址:"<<&(pd1->d) << endl ;//<<"\t虚函数地址："<< &(pd1->show) << endl;

}
