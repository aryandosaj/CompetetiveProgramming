#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
ll n, m;
string s[501];
ll r1, c1, r2, c2;
ll flag = 0;
void dfs(ll ui, ll uj)
{
    
    if (s[ui][uj] == 'X')
    {
        if ((ui == r2) && (uj == c2))
        {
            flag = 1;
            return;
        }
        // if (ui + 1 < n)
        //     dfs(ui + 1, uj);
        return;
    }
    if(s[ui][uj]=='.')
    s[ui][uj]='X';
    for (ll i = -1; i < 2; i++)
    {
        for (ll j = -1; j < 2; j++)
        {
            if ((i + j) % 2 == 0)
                continue;
            if ((ui + i >= n) || (ui + i < 0))
                continue;
            if ((uj + j >= m) || (uj + j < 0))
                continue;
            ll vi = ui + i, vj = uj + j;
            dfs(vi, vj);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    s[r1][c1]='.';
    dfs(r1, c1);
    if(flag)
    cout<<"YES";
    else
    cout<<"NO";
}