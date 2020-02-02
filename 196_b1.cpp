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
pair<ll, ll> vis[1501][1501];
string s[1501];
int n, m;
int z;
vector<pair<int, int>> v;
void dfs(int x, int y)
{
    // cout<<x<<" "<<y<<"\n";
    int xx = ((x%n)+n)%n;
    int yy = ((y%m)+m)%m;
    if (s[xx][yy] == '#')
        return;
    vis[xx][yy] = {x, y};
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
                if (vis[vxx][vyy].first == -1 && vis[vxx][vyy].second == -1)
                    dfs(vx, vy);
                else if (vis[vxx][vyy].first != vx || vis[vxx][vyy].second != vy)
                {
                    // cout<<vxx<<" "<<vyy<<" "<<vx<<" "<<vy<<"\n";
                    cout << "Yes";
                    exit(0);
                }
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
    for (int i = 0; i < 1501; i++)
        for (int j = 0; j < 1501; j++)
        {
            vis[i][j] = {-1, -1};
        }
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

    cout << "No";
}