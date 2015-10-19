#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
    public:
    string name;
    string address;

    void init(string s1,string s2)
    {
        name =  s1;
        address = s2;
    }
    void print() ;
};

void Person::print()
{
    cout << name << ": " << address <<endl;
}

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.name << ":" << person.address << endl;
    return os;
}


class Person1{
    private:
        string name;
        string address;
        int age;

    public:
    /*构造函数*/
        Person1() = default;
        Person1(int a):age(a) {}
        Person1(const string n,const string add) : name(n),address(add) {}
        Person1(const string n,const string add, int a) : name(n),address(add),age(a) {}

    /*成员函数*/
        string get_name()
        {
            return (*this).name;
        }

        int get_age()
        {
            return (*this).age;
        }
    void add_age();
    void print();

    friend Person1 add_name(Person1,Person1);
    friend void add_person(Person1 p1,Person1 p2);
};

void Person1::print()
{
    cout << name << ": " << address << " " << age << endl;
}

void add_person(Person1 p1,Person1 p2)
{
    cout << "friend void add_person:" << endl;
    cout << p1.get_name() << ": " << p1.get_age() << endl;
    cout << p2.get_name() << ": " << p2.get_age() << endl;

    p1.age = p1.age + p2.age;
    //cout << "the sum of age: " << p1.get_age()+p2.get_age() << endl;
    cout << "the sum of age: " << p1.age << endl;
    //return *this;

}

void Person1::add_age()
{
    cout << (*this).name << ":" << age << endl;
    (*this).age += 10;
    cout << "after add age 10 " << (*this).name << ":" << age << endl;
}

Person1 add_name(Person1 p1,Person1 p2)
{
    p1.age = p1.age + p2.age;
    cout << p1.name << ":" << p1.age << endl;
    return p1;
}

int main()
{
    Person person;
    person.init("wyy","HeFei");
    person.print();
    Person &person1 = person;

    /*输入姓名地址，并输出*/
    /*
    if(read(cin,person1))
        if (print(cout,person1))
    */

    Person1 person2("name2","address2");
    Person1 person3("name3","address3",20);
    Person1 person4("name4","address4",21);
    Person1 person5(23);

    add_person(person3,person4);
    person3.add_age();

    person3 = add_name(person3,person4);
    person3.print();



    return 0;
}
