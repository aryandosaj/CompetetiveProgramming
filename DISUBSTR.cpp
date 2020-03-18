#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
struct trie
{
    trie *mp[260];
    bool end;
    trie() { end = false; }
};

string x;
ll cnt;
void update(trie *a, ll ind)
{
    if ((ind + 1) == ((ll)x.length()))
        return;
    ind++;
    char c = x[ind];
    if ((a->mp[c]) == NULL)
        a->mp[c] = new trie(), cnt++;
    update(a->mp[c], ind);
}
int main()  
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        trie *a;
        a = new trie();
        string s;
        cin >> s;
        x = "";
        
        f(0, s.length())
        {
            x.pb(s[i]);
            reverse(x.begin(), x.end());
            update(a, -1);
            reverse(x.begin(), x.end());
        }
        cout << cnt << "\n";
    }
}