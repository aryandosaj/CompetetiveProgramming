#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

ll n, vert;
vector<pair<ll, ll> > graph[100];

void solve(){
    cin >> n;
    vert = n + 2;
    for(ll i=1;i<vert;i++){
        graph[i-1].push_back({i, 0});
        graph[i].push_back({i-1, 0});
    }
    ll s = 0, e = vert - 1;
    while(e > (s + 1)){
        graph[s].push_back()
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}