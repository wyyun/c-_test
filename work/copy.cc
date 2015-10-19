#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
    private:
        char c;
        double wid;
    protected:
        string name;
    public:
        int len;
        double tal;
        Base() {cout << "Base 构造函数NULL" << endl;};
        Base(char ch,int a,double b,double d,string s):
            c(ch),len(a),wid(b),tal(d),name(s)
        {
            cout << "Base 构造函数赋值" << endl;
        }
        Base(Base &base)
        {
            c = base.c;
            wid = base.wid;
            name = base.name;
            len = base.len;
            tal = base.tal;
            cout << "Base 赋值构造函数" << endl;
        }
        Base &operator= (Base &base)
        {
            c = base.c;
            wid = base.wid;
            name = base.name;
            len = base.len;
            tal = base.tal;
            cout << "Base 拷贝赋值运算符" << endl;
        }
        virtual void show();
        virtual void show_pri();
        virtual void add_num() {cout << "Base : false add_num" << endl;}
        double length() {return len;}
        double width() {return wid;}
        double tall() {return tal;}
};

void Base::show()
{
    cout << "Base:" ;
    cout << c << "," << " len " <<len << "," << " wid "<<wid << " ,tal " << tal << endl;
}

void Base::show_pri()
{
    cout << "\nBase shared virable:";
    cout << "len = " << len << endl;
}

class PubBase:public Base{
    private:
        int num;
    public:
        int len;
        double wid;
        PubBase(char ch,int a,double b,double d,string s,int n):
            Base(ch,a,b,d,s)
        {
            cout << "PubBase 构造函数赋值" << endl;
            len = a;
            num = n;
            wid = b;
        }
        PubBase(int l,double w):
            len(l),wid(w)
        {
            cout << "PubBase 构造函数赋值 shared virable" << endl;
        }
        /*
        PubBase(int l):
            len(l);
        PubBase (PubBase &base)
        {
            *this = base;
            cout << "PubBase 赋值构造函数" << endl;
        }*/
        PubBase &operator= (PubBase &base)
        {
            num = base.num;
            len = base.len;
            wid = base.wid;
            cout << "PubBase 赋值运算符" << endl;
        }
        //double space() {return len*tal*wid;}
        void show();
        void show_pri();
        void add_num() {num++;cout << "PubBase :ture add_num  & num = " << num << endl;}

};
void PubBase::show()
{
    cout << "PubBase:";
    //cout << c << "," << "len " <<len << "," << "wid "<<wid << "tal " << tal << "num " << num << endl;
    cout << "len " << len << ",num " << num << endl;
}

void PubBase::show_pri()
{
    cout << "PubBase shared virable:";
    cout << "len = " << len << ",wid = " << wid << endl;
}

int main()
{
    //Base base;
    PubBase pbase('A',10,9,8.1,"Happy",7);
    pbase.show();

    /*利用指针和引用进行派生类对基类的赋值，该对象只能用基类的成员（编译器检查基类中是否有该成员，不能用在派生类的成员），但真正运行基类还是派生类的对象，动态类型，（一般是运行派生类的成员）
     * 利用派生类对象初始化基类，基类的拷贝构造函数或者拷贝赋值函数进行拷贝，只是对基类的成员进行赋值，运行是执行基类的成员*/
    cout << "\n****Base &base = pbase******" << endl;
    Base &base = pbase;
    base.show();
    base.show_pri();
    base.add_num();

    cout << "\n****Base *base = &pbase******" << endl;
    Base *base1 = &pbase;
    base1->show();
    base1->show_pri();
    base1->add_num();

    cout << "\n****Base base(pbase)******" << endl;
    Base base2(pbase);//基类的拷贝构造函数
    base2.show();
    base2.add_num();

    cout << "\n****Base base = pbase******" << endl;
    Base base3;
    base3 = pbase;//基类的拷贝赋值运算符
    base3.show();

    cout << "\n";
    PubBase pbase1(22,23.5);
    pbase1.show_pri();

   // PubBase pbase2(base);
}
