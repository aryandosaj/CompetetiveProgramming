#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, k, s;
    cin >> n >> k >> s;
    if (((n - 1) * k < s)||(s<k))
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    
    ll p=1;
    ll cur_step=0;
    for(ll i = k-1; i >= 0; i--)
    {
        cur_step = min(s-i,n-1);
        s-=cur_step;
        if(p+cur_step<=n)
        {
            cout<<p+cur_step<<" ";
            p+=cur_step;
        }
        else
        {
            cout<<p-cur_step<<" ";
            p-=cur_step;
        }
        /* code */
    }
    
    

}