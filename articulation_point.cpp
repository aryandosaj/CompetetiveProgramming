#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> list[100];
int start;
int dfs_num[100];
int dfs_low[100];
int iter=0;
void dfs(int u,vector<int>list[100],int visit[100]);

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> list[100];
    int visit[100];
    stack<int> stack1;
    for (int i = 0; i <= n; i++) {
        visit[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);

    }

    cin >> start;

    stack1.push(start);
    visit[start] = 1;


    dfs(start,list,visit);
}
void dfs(int u,vector <int>list[100],int visit[100])
{

    dfs_num[u]=iter++;
    dfs_low[u] = dfs_num[u];

    if(list[u].empty())
            dfs_low[u]=dfs_num[u];
    int flag=0;
        for (int i = 0; i < list[u].size(); i++)
        {
            int v = list[u][i];

            if (visit[v] == 0) {


                visit[v] = 1;
                dfs(v, list, visit);

            }
                if (dfs_num[u] > dfs_num[v])
                    dfs_low[u] = dfs_num[v];


            if(dfs_low[u]>dfs_low[v])
                dfs_low[u]=dfs_low[v];

            if(dfs_low[v]>=dfs_num[u])
                flag=1;

        }
    //cout<<u<<" "<<dfs_num[u]<<" "<<dfs_low[u]<<endl;
        if((flag==1)&&(u!=start))
            cout<<u<<endl;
        if((u==start)&&(flag==1)&&(list[u].size()>1))
            cout<<u<<endl;

}