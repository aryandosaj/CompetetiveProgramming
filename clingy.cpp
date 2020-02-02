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
bool check(char c)
{
    if ((c == 'A') || (c == 'E') || (c == 'O') || (c == 'I') || (c == 'U'))
        return true;
    else
        return false;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        s = s + s;
        // cout<<s<<" \n";
        //    map<char,ll>st;
        ll c = 0;
        for (ll i = 0; i < n ; i++)
        {
            // if (s[i] != s[i + 1])
                if ((check(s[i]) )&& (check(s[i + 1])))
                {
                    c=1;
                    break;
                }
        }
        //    if(check(s[0])&&(check(s[n-1])))
        //    c++;
        if ((c == 1)&&(n!=1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}