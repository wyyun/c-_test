#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Shared{
    private:
        vector<int> A;
        vector<int> B;
        vector<int> C;
    public:
        Shared(vector<int> a,vector<int> b):
            A(a),B(b) {}
        /* void initical(vector<int>,vector<int>); */
        void Shared_int();
        friend void print(vector<int>);
};

void print(vector<int> c)
{
    for(auto i:c)
        cout << i <<" ";
    cout << endl;
}

void Shared::Shared_int()
{
    print(A);
    print(B);
    sort(A.begin(),A.end(),[] (int a,int b) {return a < b;});
    sort(B.begin(),B.end(),[] (int a,int b) {return a < b;});
    print(A);
    print(B);

    auto j = B.begin();
    auto i = A.begin();
    /* vector<int>::iterator flag1,flag2; */

    while(i!=A.end() && j != B.end())
    {
        while((*i < *j) && (i!=A.end()))
            i++;
        while((*i > *j) && (j!= B.end()))
            j++;
        if(i == A.end() || j == B.end())
            break;
        if(*i == *j)
        {
            C.push_back(*i);
            i++;
            j++;
        }
    }
    print(C);
}

int main()
{
    vector<int> a = {13,8,12,10,9,3,34};
    vector<int> b = {35,2,8,12,11,1};
    Shared share(a,b);
    share.Shared_int();
    return 0;
}
