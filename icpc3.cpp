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
ll arr[500005];
bool vis[500005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            vis[i] = 0;
        }
        ll val = 0;
        ll mx = 0;
        ll ind = 0;
        ll ans=0;
        
        for (int i = 31; i >= 0; i--)
        {
            ll f = 0; mx = 0;
            for (int j = 0; j < n; j++)
            {
                if (((val&(1LL<<i))==0) && (((1LL << i) & arr[j]) != 0) && (vis[j] == 0))
                {
                    if ((val | arr[j]) > mx)
                    {
                        f = 1;
                        mx = (val | arr[j]);
                        ind = j;
                    }
                }
            }
            if (f)
            {
                v.push_back(ind);
                vis[ind] = 1;
                val = mx;
                ans+=val;
            }
        }
        ll num = n-v.size();
        ans+=num*val;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                v.push_back(i);
        }
        cout<<ans<<"\n";
        reverse(v.begin(),v.end());
        for (int i = 0; i < n; i++)
            cout << v[i] + 1 << " ";
        cout << "\n";
    }
}