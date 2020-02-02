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
ll a;
ll color_of_wall;
ll rec(ll num,ll f)
{
    if(f)
    {
        for(ll i=1;i<=num/2;i++)
        {
            if(num%i==0)
            {
                a = a- power(color_of_wall,i)
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, c;
    cin >> n >> m >> c;
    map<ll,ll>mp;
    ll color_of_wall = power(c, n*n, MAX);
    ll a = power(color_of_wall, m, MAX);
    for (int i = m-1; i > 0; i--)
    {
        if (m % i == 0)
        {
            
            a = (a + (m / i - 1) * power(color_of_wall, i, MAX) ) % MAX;
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0&&mp[j]==0)
                {
                    // cout<<"here";
                    a = (a - (m / i -1) * power(color_of_wall, j, MAX) + m*MAX) % MAX;    
                    for(int k=1;k<=j/2;k++)
                    {
                        if(j%k==0)mp[k]=1;
                    }
                }
            }
            cout<<a<<"\n";
        }
    }
    cout<<(a*power(m,MAX-2,MAX))%MAX;
}