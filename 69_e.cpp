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
#define MAX 100000000007
ll arr[100005];
set<ll> s;
void update(ll val)
{
    s.insert(val);
}

unordered_map<ll, ll> mp1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 0; i < k - 1; i++)
        mp1[arr[i]]++;
    for (ll i = 0; i < k - 1; i++)
        if (mp1[arr[i]] == 1)
            update(arr[i]);
    for (ll i = 0; i + k - 1 < n; i++)
    {

        if (mp1[arr[i + k - 1]] == 1)
            s.erase(arr[i+k-1]);
        mp1[arr[i + k - 1]]++;
        if (mp1[arr[i + k - 1]] == 1)
            update( arr[i + k - 1]);
        if(s.size())
            cout<<(*(--s.end()))<<"\n";
        else cout<<"Nothing\n";
        if (mp1[arr[i]] == 1)
            s.erase(arr[i]);
        mp1[arr[i]]--;
        if (mp1[arr[i]] == 1)
            update(arr[i]);
    }
}