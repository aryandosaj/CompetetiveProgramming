#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
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
pl arr[1001][1001];
bool vis[1001][1001];
char ans[1001][1001];
set<pl> s;
ll n;
ll flag = 0;
bool chek(pl u)
{
    if (u.first <= 0 || u.first > n)
        return 0;
    if (u.second <= 0 || u.second > n)
        return 0;

    return 1;
}
void dfs(pl u, char c, pl p)
{
    // cout<<u.first<<" "<<u.second<<" "<<c<<" "<<p.first<<" "<<p.second<<"\n";

    if (arr[u.first][u.second].first == p.first && arr[u.first][u.second].second == p.second)
        ans[u.first][u.second] = c;
    else
        return;
    vis[u.first][u.second] = 1;
    pl left = {u.first, u.second - 1};
    if (chek(left))
        if (vis[left.first][left.second] == 0)
            dfs(left, 'R', p);
    pl right = {u.first, u.second + 1};
    if (chek(right))
        if (vis[right.first][right.second] == 0)
            dfs(right, 'L', p);
    pl up = {u.first - 1, u.second};
    if (chek(up))
        if (vis[up.first][up.second] == 0)
            dfs(up, 'D', p);
    pl down = {u.first + 1, u.second};
    if (chek(down))
        if (vis[down.first][down.second] == 0)
            dfs(down, 'U', p);
}

void dfs1(pl u, char c, ll f)
{

    if (arr[u.first][u.second].first == -1 && arr[u.first][u.second].second == -1)
        ans[u.first][u.second] = c;
    else
        return;
    vis[u.first][u.second] = 1;
    char next = '0';
    pl left = {u.first, u.second - 1};
    if (chek(left))
        if (vis[left.first][left.second] == 0)
            dfs1(left, 'R', 1), next = 'L';
    pl right = {u.first, u.second + 1};
    if (chek(right))
        if (vis[right.first][right.second] == 0)
            dfs1(right, 'L', 1), next = 'R';
    pl up = {u.first - 1, u.second};
    if (chek(up))
        if (vis[up.first][up.second] == 0)
            dfs1(up, 'D', 1), next = 'U';
    pl down = {u.first + 1, u.second};
    if (chek(down))
        if (vis[down.first][down.second] == 0)
            dfs1(down, 'U', 1), next = 'D';
    if (f == 0)
    {
        ans[u.first][u.second] = next;
        if (next == '0')
        {
            cout << "INVALID";
            exit(0);
        }
    }
}
set<pl> ss;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f(1, n + 1) fi(1, n + 1)
    {
        ll x, y;
        cin >> x >> y;
        arr[i][j] = {x, y};
        if (x != -1)
            s.insert({x, y});
        else
            ss.insert({i, j});
    }
    for (auto i : s)
        if (vis[i.first][i.second] == 0)
            dfs(i, 'X', i);
    for (auto i : ss)
        if (vis[i.first][i.second] == 0)
            dfs1(i, '0', 0);
    f(1, n + 1) fi(1, n + 1) if (vis[i][j] == 0)
    {
        cout << "INVALID";
        return 0;
    }
    cout << "VALID\n";
    f(1, n + 1)
    {
        fi(1, n + 1) cout << ans[i][j];
        cout << "\n";
    }
}