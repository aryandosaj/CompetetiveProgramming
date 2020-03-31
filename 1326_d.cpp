#include <bits/stdc++.h>
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define show(x) cout << (#x) << " : " << x << endl;
#define ll long long
#define ld long double

#define mp make_pair
#define ff first
#define ss second
#define pii pair<ll, ll>
#define sq(x) ((x) * (x))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MOD1 = 998244353;
using namespace std;

ll power(unsigned ll x, unsigned ll y)
{
    unsigned ll res = 1;

    while (y > 0)
    {

        if (y & 1)
            res = (unsigned long long)(res * x);

        y = y >> 1;

        if (x <= 100000000)
            x = (unsigned long long)(x * x);

        //cout<<x<<'\n';
    }
    return res;
}

ll isPalindrome(string P)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = P.length() - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (P[l++] != P[h--])
        {

            return -1;
        }
    }

    return 0;
}

vector<ll> prefix_function(string s, ll p)
{
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastio();

    ll T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;

        ll x = isPalindrome(S);

        ll i = 0;
        ll j = S.length() - 1;

        string A;
        string B;

        while (S[i] == S[j])
        {
            A.pb(S[i]);
            B.pb(S[j]);

            i++;
            j--;
        }

        if (j < i)
        {
            cout << S << endl;
        }
        else
        {
            string C = S.substr(i, j - i + 1);
            string K = C;

            ll p = C.length();

            reverse(C.begin(), C.end());
            string D = C;

            string E1 = K + '*' + D;

            vector<ll> pal1 = prefix_function(E1, p);

            string E2 = D + '*' + K;
            vector<ll> pal2 = prefix_function(E2, p);

            //cout<<E1<<' '<<E2;

            string P1 = S.substr(i, pal1[pal1.size() - 1]);
            string P2 = S.substr(j - pal2[pal2.size() - 1] + 1, pal2[pal2.size() - 1]);

            reverse(B.begin(), B.end());

            if (P1.length() > P2.length())
                A = A + P1 + B;
            else
                A = A + P2 + B;

            cout << A << '\n';
        }
    }
    return 0;
}