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
ll a[2];
ll dp[300005][2];
string s;
ll mex(set<ll> ss)
{
    int Mex = 0;

    while (ss.find(Mex) != ss.end())
        Mex++;

    return (Mex);
}
ll grundy(ll num, ll f)
{
    
    if (dp[num][f] != -1)
        return dp[num][f];
    if (num < a[f])
        return 0;
    set<ll> ss;
    for (int i = 0; i + a[f] <= num; i++)
    {
        ll p = grundy(i, 1 - f) ^ grundy(num - (i + a[f]), 1 - f);
        ss.insert(p);
    }
    ll m = mex(ss);
    // cout<<num<<" "<<f<<" "<<m<<"\n";
    return dp[num][f] = m;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> a[0] >> a[1] >> s;
        vll v;
        ll f = 0, c = 0;
        ll n = s.length();
        for (int i = 0; i <= n; i++)
            dp[i][0] = -1, dp[i][1] = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'X')
            {
                if (f == 1)
                {
                    f = 0;
                    v.push_back(c);
                    c = 0;
                }
            }
            else
            {
                if (f == 1)
                {
                    c++;
                }
                else
                {
                    f = 1;
                    c++;
                }
            }
        }
        v.push_back(c);
        ll ans = 0;
        f=0;
        for (auto i : v)
        {
            // cout<<i<<" "<<grundy(i,0)<<"\n";

            if(a[1]<=i&&i<a[0])
            {
                f=1;break;
            }
            ans ^= grundy(i, 0);
        }
        if(f)
        {cout<<"NO\n";continue;}
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}