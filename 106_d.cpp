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
vector<pair<char, ll>> v;
ll N[1001][1001];
ll S[1001][1001];
ll W[1001][1001];
ll E[1001][1001];
string s[1001];

void calc(ll n, ll m)
{
    for (ll i = 1; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (s[i-1][j] == '#')
                N[i][j] = 0;
            else
                N[i][j] = N[i - 1][j] + 1;
    
    for (ll i = 0; i < n; i++)
        for (ll j = 1; j < m; j++)
            if (s[i][j-1] == '#')
                W[i][j] = 0;
            else
                W[i][j] = W[i][j-1] + 1;
    
    for (ll i = 0; i < n; i++)
        for (ll j = m-2; j >=0 ; j--)
            if (s[i][j+1] == '#')
                E[i][j] = 0;
            else
                E[i][j] = E[i][j+1] + 1;
    
    for (ll i = n-2; i >=0; i--)
        for (ll j = 0; j < m; j++)
            if (s[i+1][j] == '#')
                S[i][j] = 0;
            else
                S[i][j] = S[i+1][j] + 1;

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++)
    //     {
    //         cout<<W[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    map<char, pair<ll, ll>> point;
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (('A' <= s[i][j]) && (s[i][j] <= 'Z'))
                point[s[i][j]] = {i, j};
    calc(n,m);
    ll k;
    cin >> k;
    for (ll i = 0; i < k; i++)
    {
        char d;
        ll l;
        cin >> d >> l;
        v.push_back({d, l});
    }

    string ss = "";
    ll f = 0, ff = 0;
    for (auto i : point)
    {
        ll r = i.second.first;
        ll c = i.second.second;
        f = 0;
        // cout<<i.first<<"\n";
        for (ll j = 0; j < k; j++)
        {
            // if (((r < n) && (r >= 0) && (c >= 0) && (c < m)))
            // cout<<r<<" "<<c<<"\n";
                if(v[j].first=='N'){
                    if(N[r][c]>=v[j].second)
                        r-=v[j].second;
                    else {f=1;break;}
                }
                else if(v[j].first=='S'){
                    if(S[r][c]>=v[j].second)
                        r+=v[j].second;
                    else {f=1;break;}

                }
                else if((v[j].first=='E')){
                    if(E[r][c]>=v[j].second)
                        c+=v[j].second;
                    else {f=1;break;}

                }
                else
                {
                    if(W[r][c]>=v[j].second)
                        c-=v[j].second;
                    else {f=1;break;}
                }
        }
        if (!f)
            ss.push_back(i.first), ff = 1;
    }
    if (ff)
        cout << ss;
    else
        cout << "no solution";
}