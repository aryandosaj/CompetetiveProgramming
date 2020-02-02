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
int dp[32];
int fun(int i)
{
    if(i==1)return i+1;
    if(i==2)return 5;
    if(dp[i]!=-1) return dp[i];
    int ans;
    ans = i+1 +fun(i/2) + fun((i-1)/2);
    return dp[i]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<=31;i++)
    dp[i]=-1;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mm = fun(n);
        int kk = ((n)*(n+3))/2; 
        // cout<<mm<<" "<<kk<<" "<<" ";
        if(m<mm)cout<<"-1\n";
        else if(m>kk) cout<<m-kk<<"\n";
        else cout<<"0\n";
    }
    // for(int i=1;i<=3;i++)
    // {
    //     for(int j=0;j<10;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
}