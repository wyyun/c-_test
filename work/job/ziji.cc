#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<vector<int>> vec)
{
    for(auto i:vec)
    {
        cout << "[";
        for(auto j:i)
            cout  << " "<< j;
        cout << "]" << endl;

    }
}

class Ziji{
    public:
        vector<vector<int>> vec_int;
        vector<vector<int>> combine(int n,int k)
        {
            vector<int> vec(k);
            /* vec.clear(); */
            for(int i = 1; i <= n-k+1; i++)
            {
                vec[0] = i;
                add(vec,i,1,n-k+2+1,k);
            }
            return vec_int;
        }
        void add(vector<int> &v,int ii,int begin,int end,int k)
        {
            if(begin == k)
            {
                vec_int.push_back(v);
                return;
            }
            for(int i = ii+1; i < end; i++)
            {
                v[begin] = i;
                add(v,i,begin+1,end+1,k);
            }
        }
};


void reverse(vector<int> &stack,int top,int end)
{
    if(top < stack.size()/2)
        return;
    auto temp = stack[top];
    stack[top] = stack[end];
    stack[end] = temp;
    reverse(stack,--top,++end);
}

vector<int> reverseStack(vector<int> stack,int top)
{
    reverse(stack,top,0);
    return stack;
}
void print(vector<int> vec)
{
    for(auto i:vec)
        cout << i << " ";
    cout << endl;
}

vector<int> buildMaxTree(vector<int> mvec,int len)
{
    vector<int> vec(len);
    int i = len-1;
    vec[i--] = -1;
    int root = len-1;
    for( ; i >= 0;i--)
    {
        if(mvec[i] < mvec[i+1])
            vec[i] = i+1;
        else if(vec[i+1] != -1 && mvec[i] < mvec[vec[i+1]] && mvec[i] < mvec[root])
        {
            vec[i] = vec[i+1];
            vec[i+1] = i;
        }
        else if(vec[i+1] == -1 && mvec[i] > mvec[root])
        {
            vec[i+1] = i;
            vec[i] = -1;
            root = i;
        }
        else if(mvec[i] > mvec[root])
        {
            vec[i] = -1;
            mvec[root] = i;
        }

    }
    return vec;
}

int main()
{
    Ziji ziji;
    vector<vector<int>> Ivec;
    Ivec = ziji.combine(4,2);
    print(Ivec);
    cout << "\n\n" ;
    /* Ivec.clear(); */
    Ivec = ziji.combine(6,3);
    print(Ivec);

    vector<int> vec_int1 = {1,2,3,4,5};
    /* int top = vec_int1.size()-1; */
    print(vec_int1);
    vec_int1 = reverseStack(vec_int1,vec_int1.size()-1);
    print(vec_int1);

    cout << "\n\n";
    /* vector<int> maxTree = {3,1,4,2}; */
    vector<int> maxTree = {340,1387,2101,847,1660,733,36,528};
    maxTree = buildMaxTree(maxTree,maxTree.size());
    print(maxTree);
    return 0;
}
