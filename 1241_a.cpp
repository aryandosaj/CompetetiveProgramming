#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> q;
    while (q--)
    {

        cin >> n;
        if(n==1)
        {
            cout<<"3\n";
        }
        else if(n==2)
        cout<<"2\n";
        else if(n==3)cout<<"1\n";
        else if(n&1)cout<<"1\n";
        else cout<<"0\n";
    }
}