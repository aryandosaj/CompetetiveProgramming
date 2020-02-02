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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, a, b, t;
    string s;
    cin >> n >> a >> b >> t >> s;
    //right
    ll ans1 = 0;
    ll t1 = 1, t2;
    if (s[0] == 'w')
        t1 += b;
    t2 = t1;
    ll t3 = t1;
    ll t4 = t1;
    ll m_t = t1;
    ll time1[n];
    time1[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'w')
            m_t += a + b + 1;
        else
            m_t += a + 1;
        time1[i] = m_t-t1;
    }
    ll v = 0;
    ll time2[n];
    ll tt = 0;
    time2[0] = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'w')
            tt += a + b + 1;
        else
            tt += a + 1;
        time2[n - i] = tt;
        // cout<<time2[n-i]<<" ";
    }
    // cout<<"\n";
    if (m_t <= t)
    {
        cout << n;
        return 0;
    }

    while (t1 <= t)
    {
        ans1++;
        if (s[ans1] == 'w')
        {
            t1 += a + b + 1;
        }
        else
            t1 += a + 1;
    }

    ll ans2 = 0;
    while (t2 <= t)
    {
        ans2++;

        if (s[n - ans2] == 'w')
            t2 += a + b + 1;
        else
            t2 += a + 1;
    }
    ll a3=0;
    ll ans3 = 1;

    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'w')
            t3 += a + b + 1;
        else
            t3 += a + 1;
        if (t3 <= t)
        {
            ans3++;
            a3=max(a3,ans3+(ll)(upper_bound(time2, time2 + n,t-t3-(ans3-1)*a )-time2-1));
            // cout<<(t-t3-(ans3-1)*a )<<" ";
        }
        else
            break;
    }
    ll ans4=1,a4=0;
    for (ll i = n-1; i > 0; i--)
    {
        if (s[i] == 'w')
            t4 += a + b + 1;
        else
            t4 += a + 1;
        if (t4 <= t)
        {
            ans4++;
            a4=max(a4,(ans4+(ll)(upper_bound(time1, time1 + n,t-t4-(ans4-1)*a )-time1)-1));
        }
        else break;
    }

    // cout<<ans1<<" "<<ans2<<" "<<a3<<" "<<a4<<" ";
    cout << max(ans1, max(ans2, max(a3, a4)));
}