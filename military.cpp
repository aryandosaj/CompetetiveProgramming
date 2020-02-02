#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
vector<int> v[200010];
bool visit[200010];

struct dt
{
    int start,end;
};
vector<int> ans;
int current_index=0;
dt ind[200010];
void dfs(int u )
{
    ind[u].start = current_index;
    visit[u] = 1;
    ans.push_back(u);
    for (int i = 0; i < v[u].size(); i++)
    {
        int vv = v[u][i];
        if (visit[vv] == 1)
            continue;
        else
        {
            // ans.push_back(vv);
            current_index++;
            dfs(vv);
        }
    }
    ind[u].end=current_index;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    for(int i = 0; i < 200010; i++)
    {
        visit[i]=0;
    }
    
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        v[a].push_back(i);
    }
    dfs(1);
    // for(int i = 1; i <=n; i++)
    // {
    //     cout<<ind[i].start<<" "<<ind[i].end<<"\n";
    // }
    
    // cout<<"here"; 
    for(int i = 1; i <= q; i++)
    {
        ll k,ui;
        cin>>ui>>k;
        if((ind[ui].end-ind[ui].start+1)<k)
        cout<<"-1\n";
        else
        cout<<ans[ind[ui].start+k-1]<<"\n";
        // for(int j = 0; j < ans[i].size(); j++)
        // {
        //     cout<<ans[i][j]<<" ";
        // }
        // cout<<"\n";
        
    }
    
}