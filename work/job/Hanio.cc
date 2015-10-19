#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hanoi{
    public:
        vector<string> getSolution(int n);
        void move(int num,string left,string mid,string right,vector<string> &strvec);
        void moveone(int num,string left,string right,vector<string> &strvec);
};

vector<string> Hanoi::getSolution(int n)
{
    vector<string> strvec;
    move(n,"left","mid","right",strvec);
    return strvec;
}

void Hanoi::move(int num,string left,string mid,string right,vector<string> &strvec)
{
    if(num == 1)
        moveone(1,left,right,strvec);
    else
    {
        move(num-1,left,right,mid,strvec);
        moveone(num,left,right,strvec);
        move(num-1,mid,left,right,strvec);
    }
}

void Hanoi::moveone(int num,string left,string right,vector<string> &strvec)
{
    strvec.push_back("move from "+left+" to "+ right);
}

void print(vector<string> str)
{
    for(auto i:str)
        cout << i << endl;
}

int main()
{
    vector<string> strvec;
    Hanoi hanoi;
    strvec = hanoi.getSolution(3);
    print(strvec);
    return 0;
}


