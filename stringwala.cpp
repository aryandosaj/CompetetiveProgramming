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
    char c;
    ll n;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        ll k;
        cin >> s >> k;
        stack<dt> st;
        for (ll i = 0; i < s.length(); i++)
        {

            if (st.empty())
            {
                dt temp;
                temp.c = s[i];
                temp.n = 1;
                st.push(temp);
            }
            else
            {
                dt r = st.top();
                if (r.c == s[i])
                {
                    r.n++;
                    st.push(r);
                }
                else
                {
                    dt temp;
                    temp.c = s[i];
                    temp.n = 1;
                    st.push(temp);
                }
            }
            dt r;
            r = st.top();
            if (r.n == k)
            {
                for (ll j = 0; j < k; j++)
                {
                    st.pop();
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            dt temp;
            temp = st.top();
            ans += temp.c;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}