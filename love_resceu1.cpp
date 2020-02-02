#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
vector<ll> graph[200];
ll visit[200];
void dfs(ll u)
{
    visit[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (visit[v] == 1)
            continue;
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 200; i++)
    {
        visit[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        
        graph[s1[i]].push_back(s2[i]);
        graph[s2[i]].push_back(s1[i]);
    }
    ll k = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[s1[i]] == 0)
        {
            k++;
            dfs(s1[i]);
        }
    }
    
    cout<<n-k;
}