#include <iostream>
using namespace std;

int main(){
    int n;
    long long arr[91];
    arr[0]=0, arr[1]=1;
    cin >> n;
    for(int i=2; i<=n; i++)
        arr[i]=arr[i-2]+arr[i-1];
    cout << arr[n];
}