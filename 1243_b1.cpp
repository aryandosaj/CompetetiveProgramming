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
    ll k;
    cin >> k;
    while (k--)
    {
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int c = 0;
        vector<int>v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
                c++,v.push_back(i);
        }
        if (c == 0)
        {
            cout << "Yes\n";
            continue;
        }
        if(c!=2){
            cout << "No\n";
            continue;
        }
        int ii = v[0],jj=v[1];
        swap(s[ii],t[jj]);
        if(s.compare(t)==0)
        {
            cout<<"Yes\n";continue;
        }
        swap(s[ii],t[jj]);
        swap(s[jj],t[ii]);
        if(s.compare(t)==0)
        {
            cout<<"Yes\n";continue;
        }
        cout<<"No\n";


    }
}