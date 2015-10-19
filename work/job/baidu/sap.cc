#include <iostream>
#include <string>
using namespace std;

class Longest_string{
    string str;
    int locate;
    public:
        Longest_string(string s):
            str(s) {}
        string find_first();
        int get_locate() {return locate;}
};

string Longest_string::find_first()
{
    string sub;
    string result;
    int length = -1;
    for(int i = 0; i < str.size()-1; i++)
    {
        for(int j = str.size() - 1; j >= i; j--)
        {
            sub = str.substr(i,j-i);
            /* cout <<"sub:" << sub << "\t"; */
            for(int beg = i+1; beg < str.size()-1; beg++)
            {
                int end = beg+j-i;
                if(end <= str.size())
                {
                    string sub2 = str.substr(beg,j-i);
                    /* cout <<  "sb2:" << sub2 << endl; */
                    if(sub == sub2)
                    {
                        if(length < (j-i))
                        {
                            length  = j-i;
                            locate  = i;
                            result = sub2;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    string input;
    string result;
    /* while((cin >> input) != EOF) */
    while(cin >> input)
    {
        Longest_string Lstr(input);
        result = Lstr.find_first();
        cout << Lstr.get_locate();

        if(Lstr.get_locate() != -1)
            cout << " " << result << endl;
    }
    return 0;
}
