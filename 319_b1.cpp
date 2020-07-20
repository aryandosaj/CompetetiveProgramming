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
// ll ans[100005];
ll val[100005];
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> arr[i + 1];
    ll m = arr[0];
    stack<ll> st;
    st.push(0);
    ll a = 0;
    val[0] = MAX;
    arr[0]=0;
    for (ll i = 1; i <= n; i++)
    {
        val[i] = 1;
        while ((!st.empty()) && (arr[i] > arr[st.top()]))
        {
            val[i] = max(val[i], val[st.top()] + 1);
            st.pop();
        }
        st.push(i);
        if (val[i] < MAX)
            a = max(a, val[i]);
    }
    cout << a;
}