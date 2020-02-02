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
unordered_map<ll, ll> fav;
unordered_map<ll, ll> fre_f;
unordered_map<ll, ll> fre_b;

vll actor;
struct mov
{
    ll f, z, b;
};
vector<mov> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll m, k;
    cin >> m >> k;
    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        fav[x] = 1;
    }
    ll n;
    cin >> n;
    ll mm = 0;
    ll mm2 = 0;

    for (ll i = 0; i < n; i++)
    {
        mov x;
        string s;
        cin >> s;
        x.f = 0;
        x.z = 0;
        ll t;
        cin >> t;
        for (ll j = 0; j < t; j++)
        {
            ll kk;
            cin >> kk;
            if (fav[kk])
                x.f++;
            if (kk == 0)
                x.z++;
        }
        ll left_act_not_fav = m - k - (t - x.f - x.z);
        ll left_pos = x.z;
        ll left_fav = k - x.f;

        if (left_pos > left_fav)
        {
            x.b = x.f + left_fav;
        }
        else
        {
            x.b = x.f + left_pos;
        }
        if (left_act_not_fav >= left_pos)
        {
            // v.push_back(x);
        }
        else
        {
            x.f += (left_pos - left_act_not_fav);
        }
        v.push_back(x);

        // if(t==m)

        mm = max(mm, x.b);
        mm2 = max(mm2, x.f);
        fre_f[x.f]++;
        fre_b[x.b]++;
    }
    // cout <<"mm = "<< mm<<"\n";
    for (ll i = 0; i < n; i++)
    {
        mov u = v[i];

        if ((u.f == mm))
            cout << "0\n";
        else if (u.b < mm2)
            cout << "1\n";
        else if (u.b >= mm2)
        {
            bool flg1 = true, flg2 = false;
            for (int j = 0; j < n; j++)
                if (i != j)
                {
                    //if (r[i]<l[j]) flg2=true;
                    if (v[i].b < v[j].f)
                        flg2 = true;
                    if (v[i].f < v[j].b)
                        flg1 = false;
                }
            if (flg2)
                cout << 1 << endl;
            else if (flg1)
                cout << 0 << endl;
            else
                cout << 2 << endl;
        }
        // cout << v[i].f << " " << v[i].b << "-------------\n";
    }
}
