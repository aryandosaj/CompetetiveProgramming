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
int vis[1501][1501];
string s[1501];
int n, m;
int z;
vector<pair<int, int>> v;
void dfs(int x, int y)
{
    if (s[x][y] == '#')
        return;
    // cout<<x<<" "<<y<<"\n";
    if (vis[x][y] == z)
        return;
    vis[x][y] = z;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (((i == 0) || (j == 0)) && (i != j))
            {
                int vx = x + i;
                int vy = y + j;
                int vxx = ((vx % n) + n) % n;
                int vyy = ((vy % m) + m) % m;
                if ((vx >= n) || (vx < 0) || (vy >= m) || (vy < 0))
                {

                    if (vis[vxx][vyy] == 0)
                        v.push_back({vxx, vyy});
                    else if (vis[vxx][vyy] != z - 1)
                    {
                        cout << "Yes";
                        exit(0);
                    }
                }
                else if (!vis[vx][vy])
                    dfs(vx, vy);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    z = 1;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'S')
            {
                dfs(i, j);
                f = 1;
                break;
            }
        if (f)
            break;
    }
    vector<pair<int, int>> vv;
    while (v.size() > 0)
    {
        for (auto i : v)
            vv.push_back(i);
        v.clear();
        z++;
        // cout<<"\n";
        for (auto i : vv)
        {
            // cout<<i.first<<" "<<i.second<<"\n";
            dfs(i.first, i.second);
        }
        vv.clear();
    }
    cout << "No";
}