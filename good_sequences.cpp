#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll dp[100001];
ll d[100001];
vector<ll> pf[100001];

ll prime_factor(ll n)
{
    ll num = n;
    if (n % 2 == 0)
    {
        pf[num].push_back(2);
        while (n % 2 == 0)
            n = n / 2;
    }
    for (ll i = 3; i<=sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            pf[num].push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if(n>2)
    pf[num].push_back(n);
}


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll arr[n];

    for (ll i = 0; i < 100001; i++)
    {
        dp[i] = 0;
        d[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prime_factor(arr[i]);
    }
    
    ll max_len=1;
    dp[arr[0]] = 1;
    ll m = 1;
    for (ll i = 0; i < pf[arr[0]].size(); i++)
    {
        d[pf[arr[0]][i]] = 1;
    }

    for (ll i = 1; i < n; i++)
    {
        // dp[arr[i]] = m+1;
        m=0;
        for (ll j = 0; j < pf[arr[i]].size(); j++)
        {
            d[pf[arr[i]][j]]+=1;
            m=max(m,d[pf[arr[i]][j]]);
        }
        dp[arr[i]]=m;
        max_len = max(max_len,dp[arr[i]]);
        for (ll j = 0; j < pf[arr[i]].size(); j++)
        {
            d[pf[arr[i]][j]]=m ;
           
        }
    }
    cout<<max_len;
}