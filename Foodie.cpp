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
struct dt
{
    double p, f;
    double d;
};
bool comp(dt a, dt b) { return a.d > b.d; }
dt arr[100005];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double c;
    cin >> n >> c;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].p >> arr[i].f;
        arr[i].d = arr[i].f / arr[i].p;
        // cout<<arr[i].d<<"\n";
    }
    double f = 0.0;
    sort(arr, arr + n, comp);
    for (int i = 0; i < n; i++)
    {
        // cout<<i<<"\n";
        if (arr[i].p <= c)
        {
            // cout<<arr[i].f<<"\n";
            f += arr[i].f;
            c -= arr[i].p;
        }
        else
        {
            // cout<<(arr[i].d * c)<<"\n";
            f += (arr[i].d * c);
            break;
        }
    }
    // cout<<f<<"\n";
    cout << (ll)ceil(f);
}