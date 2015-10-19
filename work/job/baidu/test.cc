#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
class Test{
    public:
        int x;
};

void init(int **arr,int n)
{
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = n * i + j;
}

/* int *print(int **arr,int n)
{
    for(step = 0; step < n; step++)
    {
        for(int i = n-step-1; i >= 0; i--)
            result[k++] = arr[step][i];//j-i+step+1 = n
    }
} */

void *print(int **arr,int n,int *result)
{
    int k = 0;
    int i,j;
    for(int step = 1; step < 2*n; step++)
        if(n >= step)
            for(i = 0; i < n; i++)
            {
                /* cout <<"i:" << i; */
                printf("i:%d ",i);
                for(j = n-1; j >= i ;j--)
                {
                    if(j - i == n- step ) 
                    {
                        result[k++] = arr[i][j];
                        cout << "i = " << i << ",j = " << j << ": " << result[k-1] << " ";
                        /* result[k++] = arr[i][n+i-step]; */
                    }
                } 
            }
        else
            {
                for(i = n-step; i < n  ;i++)
                    for(j = 0; j < n;j++)
                        if(i-j == n-step) 
                        {
                            result[k++] = arr[i][j];
                            cout << "i = " << i << ",j = " << j << ": " << result[k-1] << " ";
                            /* result[k++] = arr[i][i - n + step]; */
                        }
            }

}

int main()
{
    Test test;
    test.x = 'A';
    cout <<test.x << endl;

    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
    init(arr,n);
    int *result = new int[2*n];
    print(arr,n,result);
    for(int i = 0; i < 2*n;i++)
        cout <<result[i] << " ";
    cout << endl;
}
