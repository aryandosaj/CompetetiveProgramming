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
    ll n;
    cin >> n;
    ll arr[n];
    pair<ll,ll> brr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];brr[i].first=arr[i];brr[i].second=i;
    }
    if(n<=3){cout<<"1";return 0;}
    sort(arr, arr + n);
    sort(brr,brr+n);
    if (n == 4 || n == 5)
    {

        for (ll i = 0; i < n; i++)
        {
            vll temp;
            unordered_map<ll, ll> k;
            for (ll j = 0; j < n ; j++)
            {
                if (j == i)
                    continue;
                else
                    temp.push_back(arr[j]);
            }
            for (ll j = 0; j < temp.size() - 1; j++)
            {
                k[temp[j + 1] - temp[j]]++;
            }
            if (k.size() == 1)
            {
                cout << brr[i].second+1;
                return 0;
            }
        }
        cout << "-1";
        return 0;
    }
    map<ll, ll> mp;
    map<ll, ll> temp;
    for (ll i = 0; i < n - 1; i++)
        mp[arr[i + 1] - arr[i]]++;
    ll cd = 0;
    ll te = 0;
    for (auto i : mp)
        if (i.second > te)
            cd = i.first, te = i.second;

    ll ans=0;
    for(ll i=0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i]!=cd)
        {
            if(i==0)
            {
                if(arr[i+2]-arr[i+1]!=cd)
                    ans = i+1;
                else
                    ans = i;
                break;
            }
            else
            {
                ans = i+1;break;
            }
        }
    }
    
    vll g;
    unordered_map<ll,ll>j;
    for(ll i=0;i<n;i++)
    {
        if(i!=ans)g.push_back(arr[i]);
    }
    for(ll i=0;i<g.size()-1;i++)
        j[g[i+1]-g[i]]++;
        // cout<<j.size();
    if(j.size()==1){cout<<brr[ans].second+1;}else cout<<"-1";    
}