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
ll A[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ll start = 0;
    ll end = n - 1;

    for (ll i = 0; i < n; i++)
    {
        ll element = A[i];
        ll p = i + 1;
        ll a = 0;
        start = 0;
        end = n - 1;
        while (start <= end)
        {
            a++;
            int mid = (start + end) / 2;
            if (A[mid] == element)
                break;
            else if (A[mid] < element)
                start = mid + 1;
            else
                end = mid - 1;
        }
    cout<<(p-a)<<" ";

    }
}