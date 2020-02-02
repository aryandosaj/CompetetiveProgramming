#include <bits/stdc++.h>
using namespace std;
#define vint vector<int>
vint graph[300005];
int dsu[300005];
int len[300005];
int vis[300005];
int sz[300005];
int fd = 0, fn;
int find(int u)
{
    while (dsu[u] != u)
        u = dsu[u];
    return u;
}
void unionSets1(int x, int y)
{
    x = find(x);
    y = find(y);
    if (sz[x] > sz[y])
        swap(x, y);
    sz[y] += sz[x];
    dsu[x] = y;
}
void d(int u, int p, int dad, int l)
{
    // unionSets1(u, p); 
    if (l >= fd)
        fd = l, fn = u;
    vis[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (v != dad)
        {
            d(v, p, u, l + 1);
        }
    }
}
int nextInt()
{
    int x = 0, p = 1;
    char c;
    do
    {
        c = getchar();
    } while (c <= 32);
    if (c == '-')
    {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

int main()
{

    int n, m, q;
    n = nextInt();
    m = nextInt();
    q = nextInt();
    for (int i = 0; i < 300005; i++)
        dsu[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        u = nextInt();
        v = nextInt();
        graph[u].push_back(v);
        graph[v].push_back(u);
        unionSets1(u,v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            fd = 0;
            d(i, i, -1, 0);
            fd = 0;
            d(fn, i, -1, 0);
            len[find(i)] = fd;
        }
    }
    while (q--)
    {
        int t;
        t = nextInt();
        if (t == 1)
        {
            int x;
            x = nextInt();
            int p = find(x);
            printf("%d\n", len[p]);
        }
        else
        {
            int x, y;
            x = nextInt();
            y = nextInt();
            int fx = find(x);
            int fy = find(y);
            if (fx == fy)
                continue;
            int lx = len[fx];
            int ly = len[fy];
            int oo = (int)(ceil((lx / 2.0)) + ceil(ly / 2.0) + 1);
            if (sz[fx] > sz[fy])
                swap(fx, fy);
            sz[fy] += sz[fx];
            dsu[fx] = fy;
            len[fy] = max(lx, max(ly, oo));
        }
    }
}