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
int c[100005];
int pre[100005];
map<int, int> mp;
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
        int n;
        cin >> n;
        mp.clear();
        pre[0] = 0;
        int l = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            c[i] = 1 << x;
            pre[i] = pre[i - 1] ^ c[i];
            if (mp[pre[i]] == 0)
                mp[pre[i]] = i;
            for (int j = 0; j < 31; j++)
            {
                int y = pre[i] ^ (1<<j);
                if(y==0)
                {
                    l = max(i, l);
                    break;
                }
                auto p = mp.find(y); 
                if (p != mp.end())
                {
                    l = max(i - (*p).second, l);
                }
            }
        }
        cout << (l - 1) / 2 << "\n";
    }
}