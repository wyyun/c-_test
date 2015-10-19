#include <iostream>
#include <vector>
using namespace std;

/*只要保证d1+ t >= a1 或者 b1 =< c1+t并且t属于[l,r]的个数*/

void input_data(int p,int q,int **data_m,int **data_g)
{
    int i,j;
    for(i = 0;i <p;i++)
        for(j = 0;j < 2;j++)
            cin >> data_m[i][j];

    for(i = 0;i <q;i++)
        for(j = 0;j < 2;j++)
            cin >> data_g[i][j];
}

int count_t(int p,int q,int **data_m,int **data_g,int l,int r)
{
    int *count = new int[r-l];
    int i,j,t;
    int result = 0;

    for(i = 0; i < r-l;i++)//初始化时间点
        count[i] = 0;

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < q; j++)
        {
            for(t = 0;t < r-l;t++)
            {
                if((data_g[j][1]+t >= data_m[i][0]) || (data_g[j][0] <= data_m[i][1]+t))
                    count[t] = 1;
            }
        }
    }

    for(i = 0; i < r-l;i++)
        if(count[i] == 1)
            result++;
    return result;
}

int main()
{
    int p,q,l,r,i;
    cin >> p >> q>> l>> r;
    int **data_m = new int*[p];
    int **data_g = new int*[q];

    for(i = 0; i < p; i++)
        data_m[i] = new int[2];
    for(i= 0; i < q; i++)
        data_g[i] = new int[2];

    input_data(p,q,data_m,data_g);//输入数组
    int count = count_t(p,q,data_m,data_g,l,r);//计数：满足条件
    cout << count << endl;
    return 0;
}

