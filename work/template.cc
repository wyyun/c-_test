#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct a{
    const int i;
    int j;
    a(int s1,int s2):
        i(s1),j(s2) {}

    a(a& s):
        i(s.i),j(s.j) {}
};

template <typename T>
    T campare(T s1,T s2)
{
    if(s1 > s2) return s1;
    else if(s2 > s1) return s2;
    else
    {
        cout << s1 << " = " << s2 << endl;
        return s1;
    }
}
template <typename I,typename S> class Boss;
template <typename I,typename S>
    void campareclass(Boss<I,S> boss1,Boss<I,S> boss2);

template <typename I,typename S> class Boss
{
    public:
        Boss() = default;
        Boss( I a, S s):
            age(a),name(s) {}
        Boss(Boss &boss)
        {
            this->age = boss.age;
            this->name = boss.name;
         //   return *this;
        }
        void print();
        I return_age() {return this->age;}
        S return_name() {return this->name;}
       // template<typename T> friend T campare(T i1,T i2);//对所有该模板生成的实例都是友元
        friend void campareclass<I,S> (Boss<I,S> boss1,Boss<I,S> boss2);
    protected:
        I age;
        S name;
};

template <typename I,typename S>
    void campareclass(Boss<I,S> boss1,Boss<I,S> boss2)
{
    if(boss1.age > boss2.age) cout <<boss1.name << "is older: " << boss1.age << endl;
    else if(boss2.age > boss1.age) cout << boss2.name << "is older:" << boss2.age << endl;
    else
    {
        cout << boss1.name << " is equal to " << boss2.name << ": " << boss2.age << endl;
        return ;
    }
}

template<typename I,typename S>
void Boss<I,S>::print()
{
    cout << this->name << "'s age is " << this->age << endl;
}

int main()
{
    /*const 只可以利用括号直接赋值，不能拷贝赋值*/
    a aa(1,2);
    cout << aa.i  << " " << aa.j << endl;

    a aa1(aa);
    cout << aa1.i  << " " << aa1.j << endl;

    /*template*/
    cout << "\n*******function template********" << endl;
    cout  << "template int campare is " << campare(12,13) << endl;
    cout << "template string campare is " << campare("ab","ba") << endl;
    char flag = campare('a','b');
    cout << "template char campare is " << flag << endl;
    //cout << (("a" > "b")? "a":"b") << endl;
    cout << "template double campare is "<< campare(12.01,19.0001) << endl;


    cout << "\n*******class template********" << endl;
    Boss<int,string> boss(21,"Bob");
    Boss<int,string> boss1(boss);
    boss1.print();
    Boss<int,string> boss2(23,"Alice");
    int b1 = boss1.return_age();
    int b2 = boss2.return_age();
    cout << "Campare the age " << campare(b1,b2) << endl;
    campareclass(boss1,boss2);
    //cout << "Campare the age " << campare(boss1,boss2) << endl;
    //cout << "Campare the age " << campare(boss1.return_age,boss2.return_age) << endl;
    string s1 = boss1.return_name();
    string s2 = boss2.return_name();
    //cout << "Campare the name " << campare(boss1.name,boss2.name) << endl;

}
