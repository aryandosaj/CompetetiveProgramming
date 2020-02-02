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
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll b = 0;
        if(n==0){
            cout<<"0\n";
            continue;
        }
        ll num = n;
        while (num > 0)
        {
            b++;
            num /= 2;
        }
        ll a1 = b;
        ll a2 = b - 1;
        if (n == (((1ll << (b))) - 1))
        {
            a2 = b + 1;
        }
        else
        {
            ll mm = (1ll << (b - 1)) + (1ll << (b - 2)) - 1;
            if (n >= mm)
                a2 = b;
        }
        cout <<n<<" "<< a1 + a2 - 2 << "\n";
    }
}
