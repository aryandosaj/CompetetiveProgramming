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
ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; 
    a = a % mod; 
    while (b > 0) 
    { 
        if (b &1) 
            res = (res + a) % mod; 
 
        a = (a<<1) % mod; 
        b>>=1; 
    } 

    return res % mod; 
} 
ll   p, m;
int c,a,j,i,b,u,t,d;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        u = b;
        a--;
        c--;
        p = 0;
        m = 0;
        for (; b > 0; b--)
        {
            d = b * b;
            m+= min(b, a)*min(c,b);
            for (i = 1; i <= b; i++)
            {
                j = d / i;
                p +=(a >= i)? (j<c)?j:c:0;
                p +=(c >= i)? (a<j)?a:j:0;      
            }

        }
        cout << ((mulmod(mulmod(a , c , MAX) , u,MAX) - p + m + (MAX * 1000ll)) % MAX) << "\n";
    }
}