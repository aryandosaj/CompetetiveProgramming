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
    int t;
    cin >> t;
    while (t--)
    {
        int z = 0, o = 0, ans = 0;
        string s;
        cin >> s;
        int n= s.length();
        int pre[n+1];
        pre[0] = s[0]-'0';
        for(int i=1;i<n;i++)pre[i] = pre[i-1]+s[i]-'0';
        for (int w = 1; w * w + w <= s.length(); w++)
        {
            z=0,o=0;
            int i = 0, j = w * w + w -1;
            while (1)
            {
                
                if(j==n)break;
                if(i==0)
                o = pre[j];
                else o = pre[j]-pre[i-1];
                z = j-i+1-o;
                // cout<<o<<" "<<z<<"\n";
                if (z == w * w && o == w)
                    ans++;
                i++;j++;
                
            }
        }
        cout<<ans<<"\n";
    }
}