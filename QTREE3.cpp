#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vector<int> parent, depth, heavy, head, pos,rpos;
set<int>s;
int cur_pos;
int n;
vll adj[100005];
int dfs(int v) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h) {
    head[v] = h, rpos[cur_pos]=v,pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c);
    }
}

void init() {
    parent = vector<int>(n+1);
    depth = vector<int>(n+1);
    heavy = vector<int>(n+1, -1);
    head = vector<int>(n+1);
    pos = vector<int>(n+1);
    rpos = vector<int>(n+1);
    cur_pos = 0;

    dfs(1);
    decompose(1, 1);
}
int qu(int ql,int qh)
{
    
    auto p = (s.lower_bound(ql));
    if(p==s.end())return MAX;
    // cout<<"QU : "<<rpos[(*p)]<<"\n";
    if((*p)<=qh)return rpos[(*p)];
    return MAX;
}
int query(int a, int b) {
    int res = MAX;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = qu(pos[head[b]], pos[b]);
        res = min(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = qu(pos[a], pos[b]);
    res = min(res, last_heavy_path_max);
    return res;
}

void update(int u)
{
    if(s.find(u)!=s.end())s.erase(u);
    else s.insert(u);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();
    while(q--)
    {
        int t,u;
        cin>>t>>u;
        if(t)
        {
            int ans = query(1,u);
            if(ans!=MAX)
            cout<<ans<<"\n";
            else cout<<"-1\n";
        }
        else
        {
            update(pos[u]);
        }
        
    }



}