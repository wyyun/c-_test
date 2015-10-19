#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class Base{
    private:
        shared_ptr<string> sptr;
        auto_ptr<string> aptr;
        string str;
        int size;
        vector<string> strvec;
        allocator<string> allo_vec;
    public:
        Base() = default;
        Base(string s1,string s2):
            str(s1+s2),sptr(make_shared<string>(s1)),aptr(new string(s2)),size(s1.size()) {}
        auto_ptr<string> return_aptr() {return aptr;}
        shared_ptr<string> return_sptr() {return sptr;}

        Base(allocator<string> a):
            allo_vec(a) {}

        Base(vector<string> s):
            strvec(s) {}

        int return_size() const {return size;}
        string return_str() const {return str;}
        void print() const;

        pair<string*,string*> alloc_n_copy(const string *a,const string *b);


    /*operator overload*/
        Base &operator=(initializer_list<string> ls);
};

pair<string*,string*> Base::alloc_n_copy(const string *a, const string *b)
{
    auto data = allo_vec.allocate(b-a);
    return {data,uninitialize(a,b,data)};

}

Base &Base::operator=(initializer_list<string> ls)
{
    auto data = alloc_n_copy(ls.begin(),ls.end());
    free();
    strvec = data;
    return *this;
}

void Base::print() const
{
    if(sptr.get())
        cout << "In class:shared_ptr  " << *sptr << " ";
    if(aptr.get())
        cout << "In class:auto_ptr  " << *aptr << endl;
    auto i = strvec.begin();
    cout << "the vector<string> in the Base class is : "
    for(i : strvec)
        cout << i << " ";
    cout << endl;
}

/*operator overload——nonmember*/

ostream &operator <<(ostream &os, const Base &base)
{
    os << "size and str:" << base.return_size() << " " << base.return_str() << endl;
}

void print(auto_ptr<string> a)
{
    if(a.get())
        cout << "outer class: auto_ptr  " << *a << endl;
}

void print(shared_ptr<string> s)
{
    if(s.get())
        cout << "outer class:shared_ptr " << *s << endl;
}

void release_aptr(auto_ptr<string> a)
{
    if(a.get())
        /*release只是释放auto_ptr的所有权而不是释放对象，会导致内存泄漏（例如指向类，而不会调用希构函数delete类），
         * reser会释放所有权，同事释放对象*/
        //a.release();
        a.reset();
}

void release_sptr(shared_ptr<string> s)
{
    if(s.get())
        s.reset();
}

void init_svec(vector<string> *s,int size)
{
    for(int i = 0; i < size; i++)
        s->push_back("KITSCC"+ "ABCDEFG"+i);
}

void init_allo(allocator<string> *a)
{
    chk
}

int main()
{
    Base base("C++","primer");
    base.print();

    /*将auto_ptr赋值或者作为形参传给函数之后，则实参会失去对原对象的所有权，也即class Base内部的auto_ptr指针为空了*
     * print(base.return_aptr());*/
    cout << "1 ";
    auto_ptr<string> aptr1 = base.return_aptr();
    /*print(aptr1);
    cout << "2 ";
    print(aptr1);//已经释放了aptr1的所有权*/
    release_aptr(aptr1);
    print(aptr1);
    aptr1.reset(new string("SHE"));
    print(aptr1);

    shared_ptr<string> sptr1 = base.return_sptr();
   /* cout << "4";
    print(sptr1);
    release_sptr(sptr1);
    cout << "4";
    print(sptr1);
    release_sptr(sptr1);
    cout << "4";*/
    print(sptr1);

    operator<<(cout,base);

    vector<string> svec;
    allocator<string> avec;
    init_svec(&svec,4);
    init_allo(&avec,4)

    Base base1(avec);
    base = base1.operator=(avec);
    base.print();
    return 0;
}
