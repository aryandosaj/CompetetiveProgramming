#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int arr[51][51];
int vis0[51][51];
int vis1[2505];
int comp[51][51];
int n, m;
int c;
set<ll> graph[2505];
void dfs(int ux, int uy)
{
    
    if (vis0[ux][uy])
    {
        return;
    }
    int cmp=comp[ux][uy];
    vis0[ux][uy] = 1;
    if (ux + 1 < n)
        dfs(ux + 1, uy),graph[cmp].insert(comp[ux+1][uy]),graph[comp[ux+1][uy]].insert(cmp);
    if (ux - 1 >= 0)
        dfs(ux - 1, uy),graph[cmp].insert(comp[ux-1][uy]),graph[comp[ux-1][uy]].insert(cmp);
    if (uy + 1 < m)
        dfs(ux, uy + 1),graph[cmp].insert(comp[ux][uy+1]),graph[comp[ux][uy+1]].insert(cmp);
    if (uy - 1 >= 0)
        dfs(ux, uy - 1),graph[cmp].insert(comp[ux][uy-1]),graph[comp[ux][uy-1]].insert(cmp);
   
}

void dfs1(int ux, int uy, int f, int cmp)
{
    if (vis0[ux][uy])
       return;
    vis0[ux][uy] = 1;
    comp[ux][uy] = cmp;
    if (ux + 1 < n && arr[ux + 1][uy] == f)
        dfs1(ux + 1, uy, f, cmp);
    if (ux - 1 >= 0 && arr[ux - 1][uy] == f)
        dfs1(ux - 1, uy, f, cmp);
    if (uy + 1 < m && arr[ux][uy + 1] == f)
        dfs1(ux, uy + 1, f, cmp);
    if (uy - 1 >= 0 && arr[ux][uy - 1] == f)
        dfs1(ux, uy - 1, f, cmp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < 2505; i++)
            graph[i].clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis0[i][j] = 0;
                comp[i][j] = 0;
                cin >> arr[i][j];
            }
        }
        c = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(vis0[i][j]==0)
                {
                    dfs1(i,j,arr[i][j],c++);
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis0[i][j]=0;
        dfs(0,0);
        c--;
        // for (int i = 1; i <= c; i++)
        // {
        //     for (auto j : graph[i])
        //         cout << j << " ";
        //     cout << "\n";
        // }
        int ans = MAX;
        for (int i = 1; i <= c; i++)
        {
            for (int j = 1; j <= c; j++)
                vis1[j] = 0;
            queue<int> q;
            q.push(i);
            vis1[i] = 1;
            int mx = 1;
            while (!q.empty())
            {
                ll u = q.front();
                q.pop();
                for (auto k : graph[u])
                {
                    if (vis1[k] == 0)
                    {
                        vis1[k] = vis1[u] + 1;
                        q.push(k);
                        mx = max(mx, vis1[k]);
                    }
                }
            }
            ans = min(ans, mx - 1);
        }
        cout << ans << "\n";
    }
}