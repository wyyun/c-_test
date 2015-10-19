#include <iostream>
#include <string>

using namespace std;

class Base{
    private:
        string name;
        int *vec_int;
    public:
        Base(string s,int *i):
            name(s)
    {
        /* 深拷贝 */
        vec_int = new int;// (int *)malloc(sizeof(int));
        *vec_int = *i;
    }
        void show();
        /* ~Base() {delete vec_int;} 利用dynamic_cast时基类必须有虚函数，否则编译不过，
         * 而static_cast没有这个要求*/
        virtual ~Base() {delete vec_int;}
};
void Base::show()
{
    cout <<"Base " << name << endl;
    if(vec_int)
        cout << "Base " << *vec_int << endl;
}

class Derived:public Base
{
    private:
       const string book;
    public:
       int price;
        Derived(string s,string b,int *i,int p):
            Base(s,i),book(b),price(p) {}
        void showbook();
        string returnbook() {return book;}
};

void Derived::showbook()
{
    cout <<"Derived: "<< book <<" price = "<< price<< endl;
}

class A
{
    public:
        void show() {cout << " A ";}
};
class B
{
    public:
    void show() {cout << "B" ;}
};

int main()
{
    int a = 22;
    Base base("wang",&a);
    Derived * derived1 = static_cast<Derived *>(&base);
/*static_cast:基类不需要有虚函数，当把派生类转化成基类指针类型时，是安全的，但把基类
 * 转化成派生类时，不会进行动态类型检查*/
    //derived1->showbook();

    Derived * derived12 = dynamic_cast<Derived *>(&base);
/*dynamic_cast，基类必须有虚函数，否则编译不过，而static_cast
 * 没有这个要求，当利用dynamic_cast把基类转化成派生类类型时，会动态检验操作是否安全，如
 * 对派生类的成员函数showbook访问*/
  //  derived12->showbook();

    int *p = &a;
    /* int p1 = reinterpret_cast<int>(p); */
/*reinterpret_cast,用于将普通类型转换成指针或者指针转换成整形，两个不相关的类之间也可转换
 * 慎用*/
    cout << "int *p; reinterpret_cast<int>(p): "<< p1 << endl;

    const int *con;
    con = &a;
    int* con1 = const_cast<int *>(con);
    *con1 = 11;
    cout << *con << " const_cast " << *con1 << endl;
    *con1 = 33;
    cout << *con << " const_cast " << *con1 << endl;
/*const_cast,用于改变const或者volitale属性，但只能改变指针，引用，或者类的对象(新声明的对象为其引用，否则会出现析构两次的情况)
 并且改变之后的变量不具有const等属性，但之前的变量仍具有const等属性*/
   // *con = 0;
    const Derived derivedconst("wyy","C++ Primer",&a,88);
    //string book1 = const_cast<string>(&(derivedconst.returnbook));
    Derived &derivedconst1 = const_cast<Derived&>(derivedconst);
    cout << "class " << derivedconst.price << "  modified to ";
    derivedconst1.price = 77;
    cout << derivedconst1.price << endl;

    A *pa = new A();
    pa->show();
    B *pb = (B *)pa;
    pb->show();
    delete pa,pb;
    /* pa = new B();
    pa->show();
    pb = (B *)pa;
    pb->show();
    cout << endl; */
    return 0;
}

