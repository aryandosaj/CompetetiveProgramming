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
    //    ios_base::sync_with_stdio(0);
    //    cin.tie(0);
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll c = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < s.length(); i++)
    {
        /* code */
        mp[s[i]] = 1;
    }
    ll sum = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (mp[i] == 1)
        {
            c++;
            // cout<<(i - 96)<<" ";
            sum += (i - 96);
            i++;

        }
        if (c == k)
            break;
    }
    if(c==k)
    cout << sum ;
    else
    cout<<"-1";
}