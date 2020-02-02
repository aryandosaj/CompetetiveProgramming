#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int visit[1000][1000];
int dist[1000][1000];
string s[1000];
int ss = 2000000000;
int r = 0, c = 0;
// int d=0;
priority_queue<pair<int, pair<int, int> > > pq;

void dfs(int i1, int j1, int d)
{
    visit[i1][j1] = 1;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((i + j) % 2 == 0)
                continue;

            int i2 = i + i1;
            int j2 = j + j1;
            if ((i2 == r) || (j2 == c) || (i2 == -1) || (j2 == -1))
                continue;
            if (visit[i2][j2])
                continue;
            else
                visit[i2][j2] = 1;

            // if (s[i2][j2] == '0')
            // {
            //     dfs(i2, j2, ++d);
            //     continue;
            // }
            if ((s[i2][j2] > 48) && ((s[i2][j2] < 58)) || (s[i2][j2] == 'S')||(s[i2][j2] == '0'))
            {
                if (dist[i2][j2] > d+1)
                {
                    dist[i2][j2] = d + 1;
                    pq.push({-1 * dist[i2][j2], {i2, j2}});
                    if (s[i2][j2] == 'S')
                        if (ss > dist[i2][j2])
                            ss = dist[i2][j2];
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    // ll r,c;
    cin >> r >> c;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dist[i][j] = 2000000000;
            visit[i][j] = 0;
        }
    }
    int is = 0;
    int js = 0;
    int flag = 0;
    for (int i = 0; i < r; i++)
    {
        cin >> s[i];
        if (flag == 0)
            for (int j = 0; j < c; j++)
            {
                if (s[i][j] == 'E')
                {
                    flag = 1;
                    is = i;
                    js = j;
                }
            }
    }

    pq.push({0, {is, js}});
    dist[is][js] = 0;
    while (!pq.empty())
    {
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        int i1 = temp.second.first;
        int j1 = temp.second.second;
        int w = -1 * temp.first;
        dfs(i1, j1, w);
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // cout<<dist[i][j]<<" ";
            if ((s[i][j] > 48) && ((s[i][j] < 58)))
            {
                if (ss >= dist[i][j])
                    ans += (s[i][j] - 48);
            }
        }
    }
    cout << ans;
}