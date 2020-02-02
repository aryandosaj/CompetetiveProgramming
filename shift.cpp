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
#define MOD 1000000007
ll pp[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    ll p = 53;
    ll MAX = 1e9+7;
    ll chk = 0;
    pp[0] = 1;
    ll n = a.length();
    for (int i = 1; i < 100005; i++)
    {
        pp[i] = (pp[i-1] * p) % MAX;
    }
    ll gen = 0;
    for (int i = 0; i < a.length(); i++)
    {
        chk = (chk + a[i] * pp[i]) % MAX;
        gen = (gen + b[i] * pp[i]) % MAX;
    }
    if(chk==gen)
    {
        cout<<"0";
        return 0;
    }
    ll inv = power(p,MAX-2,MAX);
    for(ll i=0;i<n;i++)
    {
        gen = (gen - ((b[i]))%MAX + (pp[n]*b[i])%MAX + MAX)%MAX;
        gen = (gen*inv)%MAX;
        if(chk==gen)
        {
            cout<<min(i+1,n-i-1);
            return 0;
        }
    }
    cout<<"-1";
}