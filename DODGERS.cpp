#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define NUM 1000005
vint graph[NUM];
int tim[NUM];
int L[NUM];
int R[NUM];
bool vis[NUM];
int bit[NUM][2];

void update(int i, int f, int k)
{
    for (; i < NUM; i += i & -i)
        bit[i][f] += k;
}
int query(int i, int f)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i][f];
    return sum;
}
int tt;
void dfs(int u)
{
    tim[u] = tt++;
    vis[u] = 1;
    for (auto i : graph[u])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
vector<pair<int, int>> rr[NUM],ans[NUM];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        tt = 1;
        int N, M, Q, s;
        cin >> N >> M >> Q >> s;
        for (int i = 0; i < NUM; i++)
        {
            graph[i].clear(), tim[i] = 0, L[i] = 1, R[i] = N, rr[i].clear();
            bit[i][0] = 0;
            bit[i][1] = 0;
            vis[i] = 0;
            ans[i].clear();
        }
        for (int j = 0; j < M; j++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
                dfs(i);
        }
        for (int i = 1; i <= N; i++)
        {
            for (auto j : graph[i])
            {

                if (tim[j] < tim[i])
                {
                    if (j < i)
                    {
                        L[i] = max(L[i], j + 1);
                    }
                    else
                    {
                        R[i] = min(R[i], j - 1);
                    }
                }
            }
            rr[R[i]].push_back({L[i], i});
        }
        for (int ind = 1; ind <= N; ind++)
        {
            update(L[ind], 0, 1);
            if (ind != 1)
            {
                for (auto kk : rr[ind - 1])
                {
                    update(kk.first, 0, -1);
                    update(kk.second, 1, 1);
                }
            }
            int add = sqrt(ind);
            for (int l = 1; l <= ind; l += add)
            {
                int anss = (ind - l + 1) - (query(ind, 0) - query(l, 0)) - query(ind, 1);
                if (l != 1)
                    anss += query(l - 1, 1);
                ans[ind].push_back({l,anss});
            }
        }
        int last = 0;
        for (int i = 0; i < Q; i++)
        {
            int x,y,l,r;
            cin>>x>>y;
            l = (x + s*last - 1) % N + 1;
            r = (y + s*last - 1) % N + 1;
            if(l>r)
                swap(l,r);
            int k=r,anss=1;
            int low = 0,high = ans[r].size()-1,mid;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(ans[r][mid].first >= l)
                {
                    anss = ans[r][mid].second;
                    k = ans[r][mid].first;
                    high = mid - 1;
                }
                else
                {
                    low = mid+1;
                }
            }
            for(int j = l;j<k;j++)
            {
                if(L[j] <= l && R[j] >= r)
                {
                    anss++;
                }
            }
            cout<<k<<" "<<anss<<"\n";
            last = anss;
        }
    }
}