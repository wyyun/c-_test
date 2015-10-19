#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class PBase{
    public:
        PBase() = default;
        PBase(double p, string b):
            price(p),bookNo(b)
        {
            cout << "******构造函数*****" << endl;
        }

        string isbn() const {return bookNo;}
        virtual double net_price(size_t n) const;
        ~PBase() = default;

        /*当类中没有定义任何拷贝构造函数，拷贝赋值运算符，析构函数时，类才会合成移动构造函数
         * 否则必须自定义移动构造函数*/
        PBase(PBase &&p):
            price(p.price),bookNo(p.bookNo)
        {
            cout << "******移动构造函数******" << endl;
        }
        
        PBase (PBase &p):
            price(p.price),bookNo(p.bookNo)
        {
            cout << "******拷贝构造函数******" << endl;
        }

    protected:
        double price = 0;
    private:
        string bookNo;
};

double PBase::net_price(size_t n) const
{
    return n*price;
}

class Virtual_base{
    public:
        /*纯虚函数,不需要定义，只需声明即可，含有纯虚函数的类为抽象基类*/
        virtual discount_price() = 0;
    private:
        int number;
};
class Pub_Base: public PBase{
    public:
        Pub_Base() = default;
        Pub_Base(double p,string b,double d,size_t m,vector<string> svec):
            PBase(p,b),discount(d),min_qty(m),data(make_shared<vector<string>>(svec)) {}
        double net_price(size_t n) const override;
        void push_vector(string s) {data->push_back(s);}
        void print() const;
        int size() {return data->size();}
        ~Pub_Base() = default;
    private:
        //vector<string> str;
        shared_ptr<vector<string>> data;
        double discount = 0;
        int min_qty = 0;
};

double Pub_Base::net_price(size_t n) const
{
    if(n >= min_qty)
        return (1-discount)*n*price;
    else
        return n*price;
}

class Prot_Base: protected PBase{
    public:
};

class Priv_Base: private PBase{
    public:
};

void init_svector(vector<string> &s)
{
    for(auto i = 1; i < 4; i++)
        s.push_back("runtimebing"+i);
}

void Pub_Base::print() const
{
    for(auto i : *(data))
        cout << i << " ";
    cout << endl;
}

int main()
{
    //shared_ptr
    vector<string> svec;
    vector<string> &ssvec = svec;
    svec.push_back("C++ Primer");
    init_svector(ssvec);
    PBase base(10,svec[0]);
    cout << "The price of " << svec[0]<< " is " ;
    cout << base.net_price(112) << endl;

    Pub_Base pub_base(10,svec[0],0.1,100,svec);
    cout << "After discount,the price of " << svec[0] << " is " ;
    cout << pub_base.net_price(112) << endl;

    cout << "\nsize = " << pub_base.size() << endl;
    pub_base.push_vector("SHE");
    pub_base.print();

    PBase pbase = base;
    cout << "Before copy: " << base.net_price(112) << endl;
    cout <<"After copy: " << pbase.net_price(112) << endl;

    cout << "\nBefore move:base " << base.net_price(112) << endl;
    //PBase pbase1 = (move(pbase));
    PBase pbase1(move(base));
    cout <<"After move:base " << base.isbn() << " " <<  base.net_price(112) << endl;
    cout <<"After move:pbase1 " << pbase1.isbn() << " " << pbase1.net_price(112) << endl;


   // Pub_Base pub_base1();
    return 0;
}
