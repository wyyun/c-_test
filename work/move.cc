#include <iostream>
#include <string>

using namespace std;

class Base{
    private:
        string book;
        /* char *name; */
        string name;
        double price;
    public:
        /* Base(string s, char *c, double d): */
        Base(string s, string c, double d):
            book(s),name(c),price(d) {}
        Base(Base &&);
        Base &operator=(Base &&);
        ~Base() {cout << "Base 析构函数！" << endl;}
        void show();
};
Base::Base(Base &&rval):
    book(rval.book),name(rval.name),price(rval.price)
{
    rval.book = rval.name = nullptr;
}

Base &Base::operator=(Base &&rval)
{
    if(this != &rval)
    {
        //free();
        /* delete name; */
        book = rval.book;
        name = rval.name;
        price = rval.price;
        rval.book = rval.name = nullptr;
        /* rval.book = rval.name = rval.price = nullptr; */
    }
    return *this;
}

void Base::show()
{
    /* cout << *name << ":" << book << " price is "<< price << endl; */
    cout << name << ":" << book << " price is "<< price << endl;
}

class Base1{
    private:
        int year;
    public:
        Base1(int y):
            year(y) {}
        Base1(Base1 &&base):
            year(base.year) {cout << "Base1 move 构造函数" << endl;}
        Base1 &operator= (Base1 &&base);
        void show();
        ~Base1() {cout << "Base1 析构函数" << endl;}
};

Base1 & Base1::operator= (Base1 &&base)
{
    if(this != &base)
    {
        year = base.year;
    }
    return *this;
}

void Base1::show()
{
    cout << this->year << endl;
}

int main()
{
    Base1 base1(1314);
    Base1 base12(move(base1));
    base12.show();
    base1.show();
    /* char *name = "wang"; */
    string name = "wang";
    Base base("A++ primer",name,12);
    /* Base basecopy(std::move(base)); */
    Base basecopy = std::move(base);
    basecopy.show();
    /* base = std::move(base);
    base.show(); */
}

