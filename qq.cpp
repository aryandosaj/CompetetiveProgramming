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
ll rec(ll n, ll m, ll **arr)
{
    // cout << "Here";
    auto k = *arr;
    for (ll i = 0; i < n; i++)
    {
        auto p = *(arr+i);
        // cout<<p<<" "<<k<<"\n";
        for (ll j = 0; j < m; j++)
            cout << *(*(arr+i)+j) << " ";
            // cout<<*p<<" ",
            // p++,k++;
        
    }
    cout<<"\n";
    return 0;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, m;
    cin >> n >> m;

    cout<<(~0);
    ll** arr = (ll**)(malloc(n*sizeof(ll)));
    for(ll i=0;i<n;i++)
     (*(arr+i)) = (ll*)malloc(m*sizeof(ll)); 
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> *(*(arr+i)+j);
    cout<<"\n";
    //  for (ll i = 0; i < n; i++)
    //     for (ll j = 0; j < m; j++)
    //         cout<<*(*(arr+i)+j)<<" ";

    cout << rec(n , m , arr);
}