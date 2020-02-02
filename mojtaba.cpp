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
ll bit[500005];
void upd(ll i, ll x)
{
	for (i++; i < 500005; i += i & -i)
		bit[i] = min(bit[i], x);
}
ll query(ll i)
{
	ll ret = MAX;
	for (i++; i > 0; i -= i & -i)
		ret = min(ret, bit[i]);
	return ret;
}
ll arr[500005];
ll r[500005];
vll v[500005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k, q;
	cin >> n >> k >> q;

	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	for (ll i = 0; i < q; i++)
	{
		ll p;
		cin >> p >> r[i];
		r[i]--;
		p--;
		v[p].push_back(i);
	}
	for (ll i = 0; i < 500005; i++)
		bit[i] = MAX;
	ll l = 19;
	ll sp[l][n + 1];
	for (ll i = 0; i < n; i++)
		sp[0][i] = arr[i] % k;
	for (ll i = 1; i < l; i++)
	{
		for (ll j = 0; j + (1 << i) <= n; j++)
		{
				sp[i][j] = (sp[i - 1][j] * sp[i - 1][j + (1 << (i - 1))]) % k;
		}
	}
	ll ans[n];
	for (ll i = n - 1; i >= 0; i--)
	{
		ll j = i;
		ll c = 1;
		for (ll p = l; p >= 0; p--)
		{
			if (j + (1 << p) < n && (c * sp[p][j] % k))
			{
				c = (c * sp[p][j]) % k;
				j += (1 << p);
			}
		}
		if (c * sp[0][j] % k == 0)
			upd(j, j - i + 1);
		for (auto o : v[i])
			ans[o] = query(r[o]);
	}
	for (ll i = 0; i < q; i++)
	{
		if (ans[i] < MAX)
			cout << ans[i] << " ";
		else
			cout << "-1 ";
	}
}