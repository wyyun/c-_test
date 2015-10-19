#include <iostream>
using namespace std;

enum num{red,blue,yellow,green};

int main()
{
    num a = blue;
    cout << a << endl;
    if(a == blue)
        cout << (a = yellow) << endl;
}
