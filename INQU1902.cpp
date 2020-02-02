#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;                   // number of nodes
vector<int> adj[400005]; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
int cutpoint[400005];
int component[400005];
int dsu[400005];
int d;
int N;
int dfs(int v, int p = -1)
{
    visited[v] = true;
    dsu[v] = d;
    tin[v] = low[v] = timer++;
    int children = 0;
    int c = 0;
    int b=0;
    
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            b = dfs(to, v);
            c += b;
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                cutpoint[v] = b;
            ++children;
        }
    }
    if (p == -1 && children > 1)
        cutpoint[v] = b;
    return c + 1;
}

void find_cutpoints()
{
    timer = 0;
    visited.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            d = i, component[i] = dfs(i);
    }
}

struct dt
{
    int x, y;
};
dt arr[400005];
vector<int> px[400005];
vector<int> py[400005];
unordered_map<int, int> visit;
int main()
{
    N = 400005;
    cin >> n;
    n = 2 * n + 1;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y, px[arr[i].x].push_back(i), py[arr[i].y].push_back(i);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " " << px[i].size() << "\n";
        int m = px[i].size()-1;
        for (int j = 0; j < m; j++)
        {
            int u = px[i][j];
            int v = px[i][j + 1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            // cout << i << " " << j << " " << u << " " << v << "\n";
            // cout<<i<<" "<<j<<" "<<px[i].size()<<"\n";
            
        }
        m++;
        if (m > 1)
            adj[px[i][m - 1]].push_back(px[i][0]),
                adj[px[i][0]].push_back(px[i][m - 1]);
        m = py[i].size();
        for (int j = 0; j < m - 1; j++)
        {
            int u = py[i][j];
            int v = py[i][j + 1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            // cout << i << " " << j << " " << u << " " << v << "\n";
        }
        if (m > 1)
            adj[py[i][m - 1]].push_back(py[i][0]),
                adj[py[i][0]].push_back(py[i][m - 1]);
    }
    find_cutpoints();

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[dsu[i]] == 0)
        {
            visit[dsu[i]] = 1;
            if (component[dsu[i]] & 1)
                flag++;
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i < n; i++)
        {
            // cout<<component[dsu[i]]<<" "<<cutpoint[i]<<"\n";
            if (component[dsu[i]] & 1)
            {
                if (cutpoint[i] == 0)
                {
                    cout << "OK\n";
                }
                else
                {
                    if (cutpoint[i] & 1)
                    {
                        cout << "NO\n";
                    }
                    else
                    {
                        cout << "OK\n";
                    }
                }
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    else
        cout << "NO\n";
}