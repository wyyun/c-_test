#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string a("hiihh hh kkk   jhgsfgh  ");

    cout << a << endl;
    int i = 0;
    string b="";
    while(i < a.size())
    {
        while(a[i] != ' ' && i < a.size())
            b += a[i++];
        while(a[i] == ' ' && i < a.size())
        {
            b += "%20";
            i++;
        }
    }
    cout << b << endl;

    vector<int> Ivec = {12,3,4};
    return 0;
}
