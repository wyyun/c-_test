/*函数指针&&成员函数指针&&嵌套类*/
#include <iostream>
#include <string>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

double add(double a,double b)
{
    return a+b;
}

int decrease(int a,int b)
{
    return a-b;
}

class A{
    private:
        string name;
        double price;
        void (A::*Menu[])(double d);//函数表
        //static Action Menu[];//函数表
        void (A::*p)(double);//函数表
    public:
        A() = default;
        A(string n,double d):
            name(n),price(d) {};
        enum Discount {Up,DOWN};
     //   using Action = void (A::*)(double);
        void makedis(A &a,Discount,double);
        void Upprice(double);
        void Downprice(double);
//        virtual ~A() {delete []Menu;}
        void show1(A &a,double d);
};

void A::Upprice(double d)
{
    price = (1+d)*price;cout << "Upprice price = " << price << endl;
}

void A::Downprice(double d)
{
    price = (1-d)*price;cout << "Downprice price = "<< price << endl;
}

void A::show1(A &a,double d)
{
    cout << "A show1 ";
    p = &A::Upprice;
    //((A*)this)->A::p(d);
    (a.*p)(d);
}
//A::Action Menu[] = { &A::Upprice, &A::Downprice, };
void (A::* Menu[]) (double d) = {&A::Upprice,&A::Downprice,};

void A::makedis(A &a,Discount d,double dis)
{
    cout << "enum: " << d << endl;
    (a.*(Menu[d]))(dis);
}

class C{
    private:
        string book;
        int num;
    protected:
        double price;
    public:
        class D;
        C(string s,int  n,double d):
            book(s),num(n),price(d) {cout << "C构造函数" << endl;}
        void showC();
        void showCD(D &d);
        ~C() {cout << "C析构函数" << endl;}
};

class C::D{
    private:
        string name;
    protected:
        int age;
    public:
        D(string n,int a):
            name(n),age(a) {cout << "D构造函数"<< endl;}
        void showD();
        void showDC(C &c);
        ~D() {cout << "D析构函数" << endl;}
};

void C::showC()
{
    cout <<"C class:" << book <<" " << num << " " << price << endl;
}

void C::showCD(D &d)
{
    cout << "C D: " ;
    d.showD();
   // cout << d.name << " " << d.age << endl;//不可以调用嵌套类中的private和protected成员
}

/*
void C::showCD()
{
    cout << "C D :";
    showD();
}
*/

void C::D::showD()
{
    cout <<"D class:" << name <<" " << age << endl;
}

void C::D::showDC(C &c)
{
    cout <<"D C: " ;
    c.showC();
    cout << c.book <<" " << c.num << " " << c.price << endl;//嵌套类可以用外层类中的private,protected成员
}

int main()
{
    int (*p[2])(int a,int b);
    p[0] = add;
    p[1] = decrease;
    cout << p[1](5,2) <<endl;
   // cout << (p[0](2,3)) <<" " << p[1](1.4,2.0) << endl;

    cout << "   成员函数指针" << endl;
    A book1("A++ primer",10);
    book1.show1(book1,0.2);
    book1.makedis(book1,A::Up,0.2);
    //book1.makedis(book1,A::Up,0.2);
    //book1.makedis(book1,A::DOWN,0.2);


    /*嵌套类*/
    cout << endl << endl;
    C bookc("C++ primer",22,22.2);
    bookc.showC();
    C::D personD("shadan",24);
    bookc.showCD(personD);
    cout << endl << endl;

    personD.showD();
    personD.showDC(bookc);

}
