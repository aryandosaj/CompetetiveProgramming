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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll arr[n][m];
    ll brr[n][m];
    unordered_map<ll,ll>r;
    for (ll i = 0; i < n; i++)
    {
        set<ll> v;
        unordered_map<ll,ll>mp;
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            v.insert(arr[i][j]);
        }
        ll c=1;
        for(auto i:v)
            mp[i]=c++;
        for (ll j = 0; j < m; j++)
            brr[i][j] = mp[arr[i][j]];
    }
    // for (ll i = 0; i < m; i++)
    // {
    //     set<ll> v;
    //     unordered_map<ll,ll>mp;
    //     for (ll j = 0; j < n; j++)
    //     {
    //         v.insert(arr[j][i]);
    //     }
    //     ll c=1;
    //     for(auto i:v)
    //         mp[i]=c++;
    //     for (ll j = 0; j < n; j++)
    //     {
    //          if(mp[arr[j][i]]>brr[j][i]){
    //              r[j]+=mp[arr[j][i]]-brr[j][i];
    //          };
    //     }
    // }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout<<brr[i][j]+<<" ";
    //     }
    //     cout<<"\n";
    // }

}