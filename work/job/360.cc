#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int Banzhuan(int day)
{
    int num =0;
    for(int i = day; i > 0;i--)
    {

    }
}

char Find_first(char *ch)
{
    bitset<26> b;
    for(int i = 0;i < 26;i++)
    {
        if(b.test('z'-ch[i]))
            return ch[i];
        else
            b.set('z' -ch[i]);
    }
}

int main()
{
    /*搬砖问题*/
    int day = 10;
    int num = Banzhuan(day);

    /*第一个出现一次的字符*/
    char *c = "asdfghkjdhf";
    char first = Find_first(c);
    cout << "The first duplicate char in **" << c << "** is " << first<< endl;

    return 0;
}
