#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <array>
//#include <math.h>
//#include <algorithm>

using namespace std;

void init_vec(vector<int> *ivec, int size)
{
    for(int i = 0; i < size; i++)
    {
        ivec->push_back(i*3 + 1);
    }
    cout << "size: " << ivec->size() << " capacity: " << ivec->capacity() << endl;
    //(*ivec).pop_back();
    //cout << "size: " << ivec->size() << " capacity: " << ivec->capacity() << endl;
   /*resize只是将size增大，capacity是系统分配，不是在原有基础上扩大对应倍数，而reserve是将capacity扩大，size不变，而且对于pop操作不对capacity产生影响
    * (*ivec).resize(ivec->size()*3);
    cout << "resize the vector's size is 3*size:" << (*ivec).size() << " reserve the vector's capacity is 3*capacity" << (*ivec).capacity() << endl;
    (*ivec).pop_back();
    cout << "pop_back a element size: " << ivec->size() << " capacity: " << ivec->capacity() << endl;
    ivec->reserve(32);
    cout << "reserve*******size: " << ivec->size() << " capacity: " << ivec->capacity() << endl;
    (*ivec).pop_back();
    cout << "pop_back a element size: " << ivec->size() << " capacity: " << ivec->capacity() << endl;
    */

}

void print(const vector<int> ivec)
{
    cout << "size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
    for(auto i:ivec)
        cout << i << " ";
    cout << endl;
}

void init_list(list<int> *ilist)
{
    int size = 4;
    for(int i = 0; i < size; i++)
        ilist->push_back(i*3);
    for(int i = size; i != -1; i--)
        ilist->push_front(i*4);
}

void print(const list<int> ilist)
{
    list<int>::const_iterator i;//正向迭代器
    for(i = ilist.begin(); i != ilist.end(); i++)
        cout << *i << "->";
    cout << "Nil" << endl;

    list<int>::const_reverse_iterator ri;//反向迭代器
    for(ri = ilist.rbegin(); ri != ilist.rend(); ri++)
        cout << *ri << "<-";
    cout << "Nil" << endl;
}

void init_string(string *s,int size, char c)
{
    for(int i = 0; i < size; i++)
        s->push_back(c+i);
}

void print(const string s)
{
    cout << s << endl;
}

/*迭代器失效，重新赋值*/
void copy_odd(vector<int> *ivec)
{
    //vector<int>::iterator &v1 = ivec->begin();
    auto v1 = ivec->begin();
    while(v1 != ivec->end())
    {
        if(*v1 % 2)
        {
            v1 = ivec->insert(v1,*v1);
            v1 += 2;
        }
        else
        {
            v1 = ivec->erase(v1);
        }
    }
}

void init_Svec(vector<string> *svec, int size)
{
    int i = 0;
    while(i++ < size)
    {
        svec->push_back("as121df");
    }
}

void print(vector<string> svec)
{
    auto i = svec.begin();
    while(i != svec.end())
    {
        cout << *i << " ";
        i++;
    }
    cout << endl;
}

/*将vector<string>中的数转换成整形，求和并输出*/
void add_Svec(vector<string> Svec)
{
    auto i = Svec.begin();
    int result = 0;
    while(i != Svec.end())
    {
        //result += stoi(Svec.substr(Svec.find_first_of(*i)));
        result += stoi((*i).substr((*i).find_first_of("+-.0123456789")));
        i++;
    }
    cout << "" << result << endl;
}
int main()
{
    vector<int> Ivec,Ivec1;
    list<int> Ilist;
    deque<int> Ideq;
    array<int,5> Iarray;

    list<int>::iterator l1,l;
    vector<int>::iterator v1,v;

    cout << endl << "*******Vector******" << endl;
    init_vec(&Ivec,5);
    //Ivec.push_front(4);不支持

    cout << "copy_odd and erase the double" << endl;
    copy_odd(&Ivec);
    print(Ivec);

    init_vec(&Ivec1,4);
    v1 = Ivec1.begin()+2;
    v = Ivec.begin()++;
    cout << "v = " << *v << ",v1 = " << *v1 << endl;
    swap(Ivec,Ivec1);
    cout << "v = " << *v << ",v1 = " << *v1 << endl;

    v1 = Ivec.end();
    cout << "before erase:v1 = "<< * (v1-2) << endl;
    Ivec.erase(Ivec.begin()+1);
    cout << "after erase:v1 = "<< *(v1-2) << endl;//迭代器失效



    cout << endl << "*******List******" << endl;
    init_list(&Ilist);
    print(Ilist);
    cout << "Sort the elements in list!" << endl;
    Ilist.sort();
    print(Ilist);
    cout << "delete the 3th element!" << endl;
    Ilist.erase((++(++Ilist.begin())));
    print(Ilist);


    cout << endl << "*******String******" << endl;
    string str,str1,str2;
    string::iterator s,s1;
    init_string(&str,5,'a');
    init_string(&str1,3,'k');
    cout << "str:" << str << endl;
    cout << "str1:" << str1 << endl;

    char *cp = "asdfgh";
    str2.assign(cp,2);
    cout << "cp: "<< cp << endl;
    cout << "str2.assign(cp,2)  " << "str2:" << str2 << endl;
    str2.insert(str2.size(),str);
    cout << "str2.insert(str2.size(),str) " << str2 << endl;
    str2.replace(3,2,"8755");
    cout << "str2.replace(3,2,\"8755\") " << str2 << endl;


    s = ++str.begin();
    s1 = str1.begin();

    cout << "s = " << *s << " s1 = " << *(s1+2) << endl;
    swap(str,str1);//swap 迭代器失效
    print(str);
    print(str1);
    cout << "s = " << *s << " s1 = " << *(s1+2) << endl;
    str1.insert(s,'p');
    str1.insert(s,str.begin(),str.begin()+2);
    print(str);
    print(str1);

    cout << "\n\n" << endl;
    auto &aut = str.back();
    cout << "aut = " << aut << ", str = " << str << endl;
    aut = 'o';
    cout << "aut = " << aut << ", str = " << str << endl;

    cout << endl;
    auto &aut1 = str;
    cout << str << ";" << aut1 << endl;
    str.insert(str.begin()+1,'m');
    cout << str << ";" << aut1 << endl;

    cout << "****vector<string>****" << endl;
    vector<string> Svec;
    init_Svec(&Svec,4);
    print(Svec);
    add_Svec(Svec);
   /* init_deq(&Ideq);
    print(Ideq);

    init_arr(&Iarray);
    print(Iarray);*/

    return 0;
}
