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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, d, k;
    cin >> n >> d >> k;
    pair<ll, string> arr[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        ll c;
        cin >> s >> c;
        arr[i] = {c, s};
    }
    sort(arr, arr + n, greater<pair<ll, string>>());
    vector<string> v;

    ll save = 0;
    for (int i = 0; i < min(n, k); i++)
    {
        if (save < d)
        {
            save += arr[i].first;
            v.push_back(arr[i].second);
        }
        else
            break;
    }
    if (save < d)
    {
        cout << "impossible\n";
        return 0;
    }
    cout << v.size() << "\n";
    string s = ", YOU ARE FIRED!";
    for (auto i : v)
    {
        cout << (i + s) << "\n";
    }
}