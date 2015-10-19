#include <iostream>
#include <string>
using namespace std;

class Base_no_vir{
    public:
        int Base_ch;
        Base_no_vir() = default;
        virtual void show()
        {
            cout << "Base checker the char and 字节补全" << endl;
        }
        int Base_int;
};
class Derived_no_vir:public Base_no_vir
{
    public:
        int Derived_no_int;
        Derived_no_vir() = default;
        virtual ~Derived_no_vir() = default;
};
class Two_Derived_no_vir:public Derived_no_vir{
    public:
        int Derived_int;
};


class Base1{
    public:
        int Base_int;
        Base1(int a):
            Base_int(a)
        {
            cout << "Base1 构造函数" << endl;
        }

        Base1() = default;
        void show();
        virtual ~Base1()
        {
            cout << "Base1 析构函数" << endl;
        }

        int Base_int2;
};

void Base1::show()
{
    cout << " Base1::show()" << endl;
}

class Base2:public Base1{
/* class Base2:virtual public Base1{ */
    public:
        string Base2_str;
        Base2(string str,int a):
            Base1(a),Base2_str(str)
        {
            cout << "Base2构造函数" << endl;
        }
        virtual ~Base2()
        {
            cout << "Base2析构函数" << endl;
        }
};


class Derived1{
    public:
        int Base_int;
        Derived1(int a):
            Base_int(a)
        {
            cout << "Derived1 构造函数" << endl;
        }

        void show();
        virtual ~Derived1()
        {
            cout << "Derived1 析构函数" << endl;
        }

        int Base_int2;
};

void Derived1::show()
{
    cout << " Base1::show()" << endl;
}
/* class Derived:virtual public Base1{ */
class Derived:public Derived1{
    public:
        int Derived_int;
        Derived(int a,int b):
            Derived1(a),Derived_int(b) {}
};

class Derived2: public Base2,public Derived{
    public:
        int Derived2_int;
        Derived2(int a,int b,string str):
            Base2(str,a),Derived(a,b) {}
            /* Base1(a),Base2(str,a),Derived(a,b) {} */
};

class Base21:public Base1{
/* class Base21:virtual public Base1{ */
    public:
        int B21_int;
        void show();
        Base21() = default;
};

void Base21::show()
{
    cout << "Base21 show" << endl;
}

class Base22:public Base1{
/* class Base22:virtual public Base1{ */
    public:
        string B22_str;
        Base22() = default;
        void show()
        {
            cout << "Base22 show" << endl;
        }
};

class Derived3:public Base21,public Base22{
    public:
        int D3_int;
        Derived3():
            Base21(),Base22(){}
            /* Base21(),Base22(),Base1() {} */
};

int main()
{
    Derived_no_vir derived_no;
    cout << "Derived_no_vir:" << &derived_no << "    sizeof(derived_no) = " << sizeof(derived_no) << endl;
    Base_no_vir *b_no_vir = &derived_no;
    cout << "Base_no_vir:" << b_no_vir << "     sizeof(Base_no_vir) = " << sizeof(*b_no_vir) << endl;
    cout << "Base_no_vir:char:" << &derived_no.Base_no_vir::Base_ch << endl;
    cout << "Base_no_vir:int:" << &derived_no.Base_no_vir::Base_int << endl;
    cout << "Derived_no_vir:int:" << &derived_no.Derived_no_int << endl;


    cout <<"\n" << endl;
    Two_Derived_no_vir two_derived;
    cout << "Two_Derived_no_vir:" << &two_derived <<"   sizeof(two_derived) = " <<sizeof(two_derived) << endl;




    cout << "\n\n" << endl;
    Base2 base2("C++ primer",11);
    cout <<"base2:" << &base2  <<"  sizeof() = " << sizeof(base2)<< endl;
    cout << "Base1:int1 " << &base2.Base_int << endl;
    cout << "Base1:int2 " << &base2.Base_int2 << endl;
    cout << "base2: Base2_str :" << &base2.Base2_str << endl;

    cout << "\n\n" << endl;
    Derived derived(12,13);
    cout << "Derived:" <<&derived <<"  sizeof()=" << sizeof(derived) << endl;
    cout << "Base1:" << &derived.Base_int << endl;
    cout << "Base1:int2 " << &derived.Base_int2 << endl;
    cout << "Base2:" << &derived.Derived_int << endl;


    cout << "\n\n" << endl;
    Derived2 derived2(22,23,"world");
    Base1 *b1 = &derived2;
    Base2 *b2 = &derived2;
    cout << "Derived3:" <<&derived2 << "  sizeof(Derived3) = " << sizeof(derived2) << endl;
    cout << "Base1 " << b1 << " sizeof(Base1) = " << sizeof(*b1) << endl;
    cout << "Base2 " << b1 << " sizeof(Base2) = " << sizeof(*b2) << endl;
    cout << "Base1:int " << &derived2.Base2::Base_int << endl;
    cout << "Base1:int2 " << &derived2.Base2::Base_int2 << endl;
    cout << "Base2:str " << &derived2.Base2_str << endl;
    Derived1 *d1 = &derived2;
    Derived  *d2 = &derived2;
    cout << "Derived1 " << d1 << " sizeof(Derived1) = " << sizeof(*d1) << endl;
    cout << "Derived2 " << d2 << " sizeof(Derived2) = " << sizeof(*d2) << endl;
    cout << "Derived1:int " << &derived2.Derived::Base_int << endl;
    cout << "Derived1:int2 " << &derived2.Derived::Base_int2 << endl;
    cout << "Derived2:int " << &derived2.Derived_int  << endl;
    cout << "Derived3:int " << &derived2.Derived2_int  << endl;


    cout << "\n\n" << endl;
    Derived3 derived3;
    cout << "Derived3:" << &derived3 << "  sizeof(Derived3) = " << sizeof(derived3) << endl;
    Base21 *b21 = &derived3;
    /* Base1 *b11 = &derived3;
    cout << "Base21:" << b21 << "  sizeof(Base21) = " << sizeof(*b21) << endl;
    cout << "Base1:" << b11 << "  sizeof(Base1) = " << sizeof(*b1) << endl; */

    cout << "Base1:int " << &derived3.Base21::Base_int << endl;
    cout << "Base1:int2 " << &derived3.Base21::Base_int2 << endl;
    cout << "Base21:int " << &derived3.B21_int << endl;

    Base22 *b22 = &derived3;
    cout << "Base22:" << b22 << "   sizeof(Base22) = " << sizeof(*b22) << endl;
    cout << "Base1:int " << &derived3.Base22::Base_int << endl;
    cout << "Base1:int2 " << &derived3.Base22::Base_int2 << endl;
    cout << "Base22:str " << &derived3.Base22::B22_str << endl;
    cout << "Derived3:int "<< &derived3.D3_int << endl;
    return 0;
}
