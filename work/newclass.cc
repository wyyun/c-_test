#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Base{
    private:
        string name;
    public:
        Base() {cout << "Base默认构造函数" << endl;}
        Base(string s):
            name(s) {cout << "Base构造函数" << endl;}
        void show();
        virtual ~Base() {cout << "Base希构函数" << endl;  }
};

void Base::show()
{
    cout <<"show    Base : name " << this->name << endl;
}

class Derived1:public /*virtual*/ Base{
    private:
        string book;
    public:
        Derived1() {cout << "Derived1默认构造函数" << endl;}
        Derived1(string s1,string b):
            Base(s1),book(b) {cout << "Derived1构造函数" << endl;}
        void show2();
        virtual ~Derived1() {cout << "Derived1希构函数" << endl;}
        //~Base() {cout << "Derived1希构函数" << endl;}
};

void Derived1::show2()
{
    show();
    cout << "show2      Derived:book " << book << endl;
}

class Derived2:public Derived1{
    private:
        int num;
    public:
        Derived2(string s,string b,int n):
            Derived1(s,b),num(n) {cout << "Derived2构造函数" << endl;}
        void show3();
        virtual ~Derived2() {cout << "Derived2希构函数" << endl;};
        //~Base() {cout << "Derived2希构函数" << endl;};
};

void Derived2::show3()
{
    cout << "show3      Derived2:Derived1:Base" << endl;
 /*   show();
    show2();
    cout << "show3      num = " << num << endl;*/
}

class Derived3:public Derived1 ,/* virtual*/ public Base{
    private:
        double price;
    public:
        Derived3(string s,string b,double d):
            Derived1(s,b),price(d) {cout << "Derived3构造函数" << endl;}
        void show4();
        virtual ~Derived3() {cout << "Derived3希构函数" << endl;}
        //~Base() {cout << "Derived3希构函数" << endl;}
};

void Derived3::show4()
{
    cout << "show4      Derived3:Derived1 + Base" << endl;
//    show();
    show2();
    cout << "show4      price = " << price << endl;
}



/*关于深拷贝与浅拷贝*/
class A{
    private:
        string *name;
        char *book;
    public:
        /*A(string *n,char *c):
            name(n),book(c) {}  */
        A()
        {
            cout << "A构造函数" << endl;
            name = new string;
            book = new char(100);
        }

        void setvalue(string s, char *c)
        {
            name = new string(s);
            //name = &s;
            //book = c;//直接赋值不可以，会对指针两次释放，内存泄漏
            memcpy(book,c,strlen(c));
            cout << "setvalue  name = " << *name << " book = " << book << endl;
           // cout << "setvalue  name = " << *name <<  endl;
        }
        ~A()
        {
            delete book;
            delete name;
            cout << "A 析构函数" << endl;
        }

};



int main()
{
    /*
    //Base *base = new Derived1("Bao");//不可以，调用Derived1构造函数，但指针是指向Base类
    Base *base = new Derived1("Aao","A++ primer");
    base->show();
    //base->show2();//不可以，Base中没有show2成员
    */

    Base *base1 = new Derived2("Bao","B++ primer",12);
    Derived1 *derived1 = dynamic_cast<Derived1 *>(base1);
    derived1->show2();
    //derived1->show3();
    derived1->~Derived1();

    cout << endl << endl;
    Derived1 *derived11 = new Derived1("Cao","C++ primer");
    Derived2 *derived2 = dynamic_cast<Derived2 *>(derived11);
    derived2->show3();
    derived11->show2();
    derived11->~Derived1();
    //derived2->~Derived2();不可以，Derived2的构造未完成
    //derived2->~Base();

    /*
    cout << endl << endl;
    Base *base2 = new Derived3("Dao","D++ primer",42.22);
    Derived1 *derived111 = dynamic_cast<Derived1 *>(base2);
    derived111->show2();
    */

    /*关于深拷贝与浅拷贝*/
    cout << endl << endl;
    A a;
//    string s = "EAO";
    char *c = "E++ primer";
    a.setvalue("EAO",c);
}
