#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll visit[50][50];
// ll ocean[50][50];
string s[50];
ll n, m;
struct dt
{
    ll i;
    ll j;
};
vector<dt> v;
ll flag = 0;
void dfs(ll i1, ll j1)
{
    visit[i1][j1] = 1;
    dt temp;
    temp.i = i1;
    temp.j = j1;
    v.push_back(temp);
    if ((i1 == n - 1) || (j1 == m - 1) || (i1 == 0) || (j1 == 0))
        flag = 1;
    
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if((i+j)%2==0)
            continue;
            ll i2 = i1 + i;
            ll j2 = j1 + j;

            if ((i2 >= n) || (j2 >= m) || (i2 <= -1) || (j2 <= -1))
                continue;
            if (visit[i2][j2] == 1)
                continue;
            if (s[i2][j2] == '.')
            {
                if ((i2 == n - 1) || (j2 == m - 1) || (i2 == 0) || (j2 == 0))
                    flag = 1;
                // cout<<i2<<" "<<j2<<"\n";
                
                dfs(i2, j2);
            }
        }
    }
}
bool comp(vector<dt> a, vector<dt> b)
{
    return a.size() < b.size();
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            visit[i][j]=0;
        }
        
    }
    
    ll k;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<dt> > lakes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if ((visit[i][j] == 0)&&(s[i][j]=='.'))
            {
                flag = 0;
                v.clear();
                

                dfs(i, j);
                
                if (flag == 0)
                    lakes.push_back(v);
                    // cout<<i<<" "<<j<<"-\n";
            }
        }
    }
    ll ans = 0;
    ll cur_lakes = lakes.size();
    // cout << cur_lakes << " ==";
    sort(lakes.begin(), lakes.end(), comp);
    for (int i = 0; i < lakes.size(); i++)
    {
        // cout<<lakes[i].size()<<" ";
        if (cur_lakes > k)
        {
            cur_lakes--;
            
            ans += lakes[i].size();
            for (int j = 0; j < lakes[i].size(); j++)
            {
                s[lakes[i][j].i][lakes[i][j].j] = '*';
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << "\n";
    }
}