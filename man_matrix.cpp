#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int n, m, sx, sy, Q;
        cin >> n;
        cin >> m;
        bool visited[n + 1][m + 1];
        int number[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                number[i][j] = 0, visited[i][j] = 0;
        vector<vector<int>> A(n, vector<int>(m));
        for (int i_A = 0; i_A < n; i_A++)
            for (int j_A = 0; j_A < m; j_A++)
                cin >> A[i_A][j_A];
        cin >> sx;
        cin >> sy;
        cin >> Q;
        sx--;
        sy--;
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visited[sx][sy] = 1;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            int ux = u.first;
            int uy = u.second;
            int k = A[ux][uy];
            if (k == 0)
                continue;
            for (int i = 0; i <= k; i++)
            {
                int vx = ux - i, vy = uy + k - i;
                if (vx < 0 || vx >= n || vy < 0 || vy >= m)
                    continue;
                if (!visited[vx][vy])
                {
                    q.push({vx, vy});
                    visited[vx][vy] = 1;
                    number[vx][vy] = number[ux][uy] + 1;
                }
            }

            for (int i = 0; i <= k; i++)
            {
                int vx = ux - i, vy = uy - (k - i);
                if (vx < 0 || vx >= n || vy < 0 || vy >= m)
                    continue;
                if (!visited[vx][vy])
                {
                    q.push({vx, vy});
                    visited[vx][vy] = 1;
                    number[vx][vy] = number[ux][uy] + 1;
                }
            }
            for (int i = 0; i <= k; i++)
            {
                int vx = ux + i, vy = uy + k - i;
                if (vx < 0 || vx >= n || vy < 0 || vy >= m)
                    continue;
                if (!visited[vx][vy])
                {
                    q.push({vx, vy});
                    visited[vx][vy] = 1;
                    number[vx][vy] = number[ux][uy] + 1;
                }
            }
            for (int i = 0; i <= k; i++)
            {
                int vx = ux + i, vy = uy - (k - i);
                if (vx < 0 || vx >= n || vy < 0 || vy >= m)
                    continue;
                if (!visited[vx][vy])
                {
                    q.push({vx, vy});
                    visited[vx][vy] = 1;
                    number[vx][vy] = number[ux][uy] + 1;
                }
            }
        }

        for (int i = 0; i < Q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if ((x == sx) && (y == sy))
                cout << "0\n";
            else if (number[x][y] == 0)
                cout << "-1\n";
            else
                cout << number[x][y] << "\n";

        }
    }
}