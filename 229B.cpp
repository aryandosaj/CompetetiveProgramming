#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pint pair<int, int>
#define pb push_back
#define F first
#define S second
#define I insert
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
struct dt
{
    int b, w;
};
unordered_set<int> mp[100001];
vector<dt> graph[100001];
// bool visit[100001];
int dist[100001];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    memset(dist,0x3f,sizeof dist);
    // cout<<dist[9];
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }


    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            mp[i].insert(temp);
        }
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[0] = 0;
    dist[1] = 0;
    // while (mp[1][dist[1]] != 0)
    // {
    //     dist[1]++;
    // }
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = -1 * pq.top().first;
        pq.pop();
        // visit[u] = 1;
        if (dist[u] < d)
                    continue;
        while (mp[u].count(d) != 0)
        {
            // dist[v]++;
            d++;
        }
        if (u == n)
                    {cout << dist[n];return 0;}
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].b;
            int w = graph[u][i].w;
            
            // if (visit[v] == 1)
            //     continue;
            // else
            {
                
                if (dist[v] > d + w)
                    {dist[v] = d + w;
                

                pq.push({-1 * dist[v], v});}
            }
        }
    }

    
    cout << "-1";
    
        
}