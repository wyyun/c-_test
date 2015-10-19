#include <iostream>
#include <string>
using namespace std;

void init(int *arr,int n)
{
    int i;
    for(i = 0; i < n; i++)
        cin >> arr[i];
}

int find_least_most(int *arr,int n)
{
    int *store = new int[n-1];
    int *least = new int[n-2];
    int i,j,most;
    for(i = 0; i < n-1;i++)
        store[i] = arr[i+1] - arr[i];

    most = store[0]+store[1];
    for(i = 1;i < n-1;i++)
    {
        store[i] = store[i]+store[i-1];
        for(j = i; j < n;j++)
        if(store[j] > most)
            most = store[j];
        least[i-1] = most;
    }
    most = least[0];
    for(i = 1;i < n-2; i++)
        if(most > least[i])
            most = least[i];
    return most;
}

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];
    init(array,n);
    int result;
    result = find_least_most(array,n);
    cout << result << endl;
}
