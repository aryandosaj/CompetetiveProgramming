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
    int n, g;
    cin >> n >> g;
    pair<int, pair<int,int>> arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second.first,arr[i].second.second=i+1;
    sort(arr, arr + n);
    int x = n/g;
    int k=0;
    cout<<x<<"\n";
    vector<int>ans[x];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<g;j++,k++)
        {
            ans[i].push_back(arr[k].second.second);
        }
    }
    for(int i=k;i<n;i++)
    ans[x].push_back(arr[k].second.second);
    for(int i=0;i<x;i++)
    {
        cout<<ans[i].size()<<"\n";
        for(auto j:ans[i])
        cout<<j<<" ";
    }
}