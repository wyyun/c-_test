#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Joker
{
    private:
        string input;
        vector<string> campare1,campare2;
    public:
        Joker(string str):
            input(str) {}
        ~Joker() = default;
        void slice_joker();
        void campare();
        friend void print(vector<string>);
};

void print(vector<string> Svec)
{
    for(auto i: Svec)
        cout << i << " " ;
    cout << endl;
}

void Joker::slice_joker()
{
    int i = 0;
    string s,s1;
    while(input[i]!= '-')
    {
        s = input[i];
        while(input[++i] && input[i] != ' ' && input[i] != '-')
        {
            s += input[i];
        }
        campare1.push_back(s);
        /* i++; */
    }
    i++;
    while(i <= input.size()-1)
    {
        s1 = input[i];
        while(input[++i] && input[i]!= ' ')
        {
            s1 += input[i];
        }
        campare2.push_back(s1);
        /* i++; */
    }
}

void Joker::campare()
{
    if(!campare1.size() || !campare2.size())
    {
        cout << "error!" << endl;
        return;
    }
    if((campare1[0]=="joker" && campare1[1] == "JOKER")||(campare1[0] == "JOKER" && campare1[1] == "joker"))
    {
        print(campare1);
        return;
    }

    if((campare2[0]=="joker" && campare2[1] == "JOKER")||(campare2[0] == "JOKER" && campare2[1] == "joker"))
    {
        print(campare2);
        return;
    }
    if(campare1.size() == 4)
    {
        if(campare2.size() == 4)
        {
            if(campare1[0] < campare2[0])
            {
                print(campare2);
                return;
            }
            else
            {
                print(campare1);
                return;
            }
        }
    }

    if(campare2.size() == 4)
    {
        print(campare2);
        return;
    }

    if(campare1.size() == campare2.size())
    {
        if(campare1.size() == 1)
        {
            if(campare1[0] == "joker" || campare1[0] == "JOKER")
            {
                print(campare1);
                return;
            }
            else if(campare2[0] == "joker"||campare2[0] == "JOKER")
            {
                print(campare2);
                return;
            }
        }
        if()
        if(campare1[0] < campare2[0])
            print(campare2);
        else
            print(campare1);
        return;
    }
    else
    {
        cout<< "Error!" << endl;
        return;
    }
}


int main()
{
    string strinput;
    cout <<"请输入要比较的两手牌，同一手牌之间以空格断开，两手牌之间以-相连"<< endl;
    cin >> strinput;

    Joker joker(strinput);
    joker.slice_joker();
    joker.campare();
    return 0;
}
