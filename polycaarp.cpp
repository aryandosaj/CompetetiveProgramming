#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;

struct polycaarp
{
    ll v, i;
};
bool comp(polycaarp a, polycaarp b)
{
    return a.v > b.v;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k;
    cin >> n >> k;
    polycaarp arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].v;
        arr[i].i = i;
    }
    sort(arr, arr + n, comp);
    vector<ll> s;
    s.push_back(0);
    ll ans = 0;
    for (ll i = 0; i < k; i++)
    {
        s.push_back(arr[i].i+1);
        ans += arr[i].v;
    }
    sort(s.begin(), s.end());
    cout << ans << "\n";

    for (ll i = 1; i < s.size()-1; i++)
    {
        cout << s[i] - s[i - 1] << " ";
    }
    cout<<(n-s[s.size()-2]);
}