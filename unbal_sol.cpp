#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define mp make_pair
#define pii pair<ll, ll>
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define y1 fdfbvfds
typedef long double f80;
#define all(x) x.begin(), x.end()
#define ll long long
#define endl '\n'

int n, k;
int t;
string ans, x;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k == n || k <= 4)
        {
            cout << -1 << endl;
            continue;
        }

        x = "", ans = "";

        for (int i = 1; i <= (k - 2) / 2; i++)
            ans.pb('(');

        for (int i = 1; i <= (k - 2) / 2; i++)
            ans.pb(')');

        ans += "(())";

        int rem = n - (int)ans.length();
        for (int i = 1; i <= rem / 2; i++)
            cout << "(";
        cout << ans;
        for (int i = 1; i <= rem / 2; i++)
            cout << ")";
        cout << endl;
    }
    return 0;
}