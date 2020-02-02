#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
void fun(int** inp)
{
    cout<<inp[0][0];
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
   int** arr;
   arr = (int**)(malloc(sizeof(int)));
   *arr = (int*)malloc(2*sizeof(int));
   **arr = 12;*(*arr+1)=13;
   cout<<**arr<<*(*arr+1);
//    arr[0][1]=2;
//    arr[1][0]=3;arr[1][1]=4;
//    cout<<arr[0][0];
//    fun(arr);
}