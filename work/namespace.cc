#include <iostream>
#include <string>
using namespace std;

namespace A{
    int num = 5;
    int price = 15;
    class B{
        private:
            int num;//隐藏了外部的num和price变量
            string name;
        public:
            B() = default;
            B(int n, string nm):
                num(n),name(nm) {}
            B(int n, string nm, int h):
                num(n),name(nm),price(h) {}
            void show1();
            void show2() { cout << " B:price = " << price << endl; }
            string return_name() {return name;}
            friend void show4();
            friend void show5(const B& b);
            int price;
    };
    string book;
    void show3(B &b);
    void show4();
    void show5(B &b);
}

void A::B::show1()
{
    cout << "class B:name " << this->name << "  namespace A:book:" << book  << "  num=" << num << "   price=" << price << endl;
}

void A::show3(B &b)
{
    cout << "class B:name " << b.return_name() << "    namespace A:book:" << book << "    num= "<< num << "  price=" << price << endl;
}

void A::show4()
{
    cout << "A: num = " << num << "     price" << price << endl;
}

//void A::show5(const B &b)
void A::show5(B &b)
{

    cout << "class B:name " << b.return_name() << "    namespace A:book:" << book << "    num= "<< num << "  price=" << price << endl;
}

int main()
{
    using namespace A;
    book = "C++ primer";
    B b(3,"yaowj",13);
    b.show1();
    b.show2();

    show3(b);
    show4();
    show5(b);
    return 0;
}

