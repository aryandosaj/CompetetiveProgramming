#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
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
string s[16];
bool vis[16][16];
ll lev[16][16];
ll n, m, k;
struct dt{
    
    char s[16][16];
};
dt upd(dt u,ll vi,ll vj)
{
    string temp[n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(s[i][j]>'0'&&s[i][j]<='9')
                temp[i][j]='.';
            else
                temp[i][j]=s[i][j];
        }
    }
    // for(ll i=0;i<u.i.size();i++)
    // {
    //     temp[u.i[i]][u.j[i]]='1'+i;
    // }
    
}
// void dfs(ll  )
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll si, sj;
    char ss[16][16];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i]; 
        for(ll j=0;j<m;j++)
            ss[i][j]=s[i][j];
    }
    
    queue<dt> q;
    q.push();
    while (!q.empty())
    {
        dt u = q.front();
        ll ui = q.front().i[0];
        ll uj = q.front().j[0];
        // cout<<ui<<" "<<uj<<"\n";

        q.pop();
        if(s[ui][uj]=='@'){cout<<lev[ui][uj];return 0;}
        vis[ui][uj] = 1;
        for (ll i = -1; i < 2; i++)
        {
            for (ll j = -1; j < 2; j++)
            {
                if (i == 0 || j == 0)
                {
                    ll vi = ui + i, vj = uj + j;
                    if ((vi < 0 || vi >= n) || (vj < 0 || vj >= m))
                        continue;
                    if (vis[vi][vj] == 0)
                        if (s[vi][vj] == '.' || ((s[vi][vj] - '0') == k)||s[vi][vj] == '@')
                        {
                            upd(u,vi,vj);
                            q.push({vi, vj});
                            lev[vi][vj] = lev[ui][uj]+1;
                        }
                }
            }
        }
    }
    cout<<"-1";
}