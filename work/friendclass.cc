#include <iostream>
#include <string>
using namespace std;

class Base{
    private:
        string person;
    public:
        Base(string s):
            person(s) {}
        void show();
        /* 友元函数或者友元类：可以访问该类中包括非公有成员（private / protected） */
        friend class friendperson;
        friend void wyy(Base &);
        /*cannot be overload
         * void show_data(const int);
         * void show_data(int); */
        void show_data(const int*);
        void show_data(int *);
        void show1() const;
        virtual ~Base() = default;
};

void wyy(Base &b)
{
    cout << "friend function wyy:" << b.person << endl;
}

void Base::show()
{
    cout << "Base: " << person << endl;
}

void Base::show_data(const int *i)
{
    cout << "show_data(const int)" << endl;
    show1();
}
void Base::show_data(int *i)
{
    cout << "show_data(int)" << endl;
    show1();
}
void Base::show1()const
{
    cout << "Base: " << person << endl;
}

class friendperson{
    private:
        int age;
        string hobby;
    public:
        friendperson(int a,string s):
            age(a),hobby(s) {}
        void show(Base &b,string );
};
void friendperson::show(Base &b,string s)
{
    b.show();
    b.person = s;
    cout << "friendperson:" << b.person <<" age = " << age << " hobby is " << hobby << endl;
}

int main()
{
    const int i = 0;
    Base base("wangyy");
    base.show_data(&i);
    friendperson fperson(24,"sing");
    fperson.show(base,"yaowj");
    wyy(base);
}
