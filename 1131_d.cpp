#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vint vector<int>
int power(int a, int b, int mod)
{
    int c = 1;
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
vint graph[2001];
vint w[2001];
int m;
bool vis[2001];
bool v[2001];
int lev[2001];

void dfs(int u)
{
    v[u] = 1;
    vis[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        int ww = w[u][i];
        if (lev[v] < lev[u] + ww)
        {
            lev[v] = lev[u] + ww, m = max(m, lev[v]);
            if (!vis[v])
                dfs(v);
            else
            {
                cout << "No";
                exit(0);
            }
        }
    }
    vis[u] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    string s[r];
    for (int i = 0; i < r; i++)
        cin >> s[i];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int u = (i);
            int v = (r + j);
            if (s[i][j] == '<')
                graph[u].push_back(v), w[u].push_back(1);
            else if (s[i][j] == '>')
                graph[v].push_back(u), w[v].push_back(1);
            else
                graph[u].push_back(v), graph[v].push_back(u), w[v].push_back(0), w[u].push_back(0);
        }
    }
    for (int i = 0; i < r + c; i++)
        if (!v[i])
            dfs(i);
    cout << "Yes\n";
    for (int i = 0; i < r; i++)
        cout << lev[i] + 1 << " ";
    cout << "\n";
    for (int i = 0; i < c; i++)
        cout << lev[r + i] + 1 << " ";
}