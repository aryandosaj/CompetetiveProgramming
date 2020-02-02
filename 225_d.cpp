#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vint vector<int>
string s[16];
int vis[16][16];
int lev[16][16];
int n, m, k;
struct dt
{
    vint i, j;
};
dt upd(dt u, int vi, int vj)
{
    u.i.pop_back();
    u.j.pop_back();
    u.i.emplace(u.i.begin(), vi);
    u.j.emplace(u.j.begin(), vj);  
    return u;
}
vint pi;
vint pj;
void dfs(int ui, int uj, int x)
{
    pi.push_back(ui);
    pj.push_back(uj);
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 || j == 0)
            {
                int vi = ui + i, vj = uj + j;
                if ((vi < 0 || vi >= n) || (vj < 0 || vj >= m))
                    continue;
                if (s[vi][vj] - '0' == x)
                    dfs(vi, vj, x + 1);
            }
        }
    }
}
bool chk(dt u, int vi, int vj)
{
    for (int i = 0; i < u.i.size() - 1; i++)
    {
        if (vi == u.i[i] && vj == u.j[i])
            return 0;
    }
    return 1;
}
ll largest_cycle(ll ui,ll uj)
{
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int si, sj;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if ((0 < s[i][j] - '0') && (10 > s[i][j] - '0'))
                k = max(k, (int)(s[i][j] - '0'));
            if (s[i][j] == '1')
            {
                si = i;
                sj = j;
            }
        }
    }
    queue<dt> q;
    dfs(si, sj, 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] > '0' && s[i][j] <= '9')
                s[i][j] = '.';
        }
    }
    q.push({pi, pj});
    while (!q.empty())
    {
        // cout<<q.size()<<"\n";
        dt u = q.front();
        int ui = u.i[0];
        int uj = u.j[0];
        // cout << ui << " " << uj << "\n";
        q.pop();
        if (s[ui][uj] == '@')
        {
            cout << lev[ui][uj];
            return 0;
        }
        
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if ((i == 0 || j == 0)&&((i+j)!=0))
                {
                    int vi = ui + i, vj = uj + j;
                    if ((vi < 0 || vi >= n) || (vj < 0 || vj >= m))
                        continue;
                    if (vis[vi][vj] == 0)
                    {
                        if ((s[vi][vj] == '.' || s[vi][vj] == '@') && (chk(u, vi, vj)))
                        {
                            vis[vi][vj]++;
                            q.push(upd(u, vi, vj));
                            lev[vi][vj] = lev[ui][uj] + 1;
                        }
                    }
                }
            }
        }
    }

    cout << "-1";
}