#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 255

void get_next(string T, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    cout << "next:" << next[1] << " ";

    while(i < T.size())
    {
        if(j == 0 || T[i-1]==T[j-1])
        {
            j++;
            i++;
            next[i] = j;
            cout << j << " ";
        }
        else
            j = next[j];
    }
    cout << endl;
}

void get_nextval(string T, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    cout << "next:" << next[1] << " ";
    while(i < T.size())
    {
        if(j == 0 || T[i-1] == T[j-1])
        {
            j++;
            i++;

            /*改进的模式匹配：修改的计算next数组算法*/
            if(T[i-1] != T[j-1])
                next[i] = j;
            else
                next[i] = next[j];
            cout << next[i] << " ";
        }
        else
            j = next[j];
    }
    cout << endl;
}

int Index_KMP(string S, string T, int pos)
{
    int i = pos;
    int j = 0;
    int next[MAXSIZE];
    //get_next(T,next);/*原版的KMP模式匹配*/
    get_nextval(T,next);/*改进的模式匹配*/

    while(i < S.size() && j < T.size())
    {
        if(j == 0 || S[i] == T[j])
        {
            j++;
            i++;
        }
        else
            j = next[j];
    }
    if(j == T.size())
        return i-T[0];
    else
        return MAXSIZE;
}

void print(string T, string S, int flag)
{
    if (flag == MAXSIZE)
        cout << T << " is not subset of " << S ;
    else
        cout << T << " is subset of " << S ;
    cout << endl;
}

int main()
{
    string T = "abcabx";
    string T1 = "abcab";
    string S = "abcabcabc";

    int flag = Index_KMP(S,T,0);
    print(T,S,flag);

    flag = Index_KMP(S,T1,2);
    print(T1,S,flag);

   // flag = Index_KMP(S,T,0);
    return 0;
}
