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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vll freq[10];
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - '0'].push_back(i);
    }
    vll odd;
    for (int i = 0; i < 10; i++)
    {
        if (freq[i].size() & 1)
            odd.push_back(i);
    }
    if (odd.size() == 0)
    {
        cout << "-1\n";
        return 0;
    }
    ll o = odd.size();
    ll f = 0;
    ll ans=MAX;
    for(int l=0;l<=100000;l++)
    {
        ll c=0;
        ll r=l;
        for(auto i:odd)
        {
            auto p = lower_bound(freq[i].begin(),freq[i].end(),l);
            if(p!=freq[i].end())
            {
                c++;
                r = max(r,(*p));
            }
            else
            {
                continue;
            }
            
        }
        if(c==o)
        ans = min(ans,r-l);
    }
    cout<<ans<<"\n";
    
}