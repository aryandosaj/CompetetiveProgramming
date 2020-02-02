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

string arr[1001];
bool dp[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=0;
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(arr[i][j]=='.')dp[i][j]=1;
                else break;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(arr[j][i]=='#')break;
                if(dp[j][i]==1)ans++;
            }
        }
        cout<<ans<<"\n";
    }
}