#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, h;
    cin >> n >> h;
    ll arr[n];
    ll brr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i],brr[i]=arr[i];
    sort(arr, arr + n);
    if(n==2){cout<<"0\n1 1";return 0;}
    ll mm = min_element(brr,brr+n)-brr;
    ll x1 = arr[n-1]+arr[n-2]-arr[0]-arr[1];
    ll x2 = max(arr[n-1]+arr[0]+h,arr[n-1]+arr[n-2])-min(arr[0]+arr[1]+h,arr[1]+arr[2]);
    if(x2>=x1)mm=n;
    cout<<min(x1,x2)<<"\n";
    for(ll i=0;i<n;i++)
    cout<<(i==mm)+1<<" ";

    
}