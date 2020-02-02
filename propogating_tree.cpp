#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct dt
{
    ll val;
    ll lev;
};

vector<ll> store[200010];
// int lazy[200010];
int parent[200010];
int visit[200010];
ll in_time = 0;
ll discover[200010];
ll beg[200010];
ll endi[200010];
ll lev[200010];
dt a[200010];

void point_update(ll loc,ll low,ll high,ll val,ll pos,ll lev)
{
    if((loc<=high)&&(loc>=low))
    {
        if (lev == -1)
        {
            a[pos].lev = lev % 2;
            a[pos].val=val;
        }
        else
        {
            if (lev % 2 == a[pos].lev)
            {
                a[pos].val +=val;
            }
            else
            {
                a[pos].val -=val;                
            }
        }
        if(low==high)
        return;
        ll mid= (low+high)/2;
        point_update(loc,low,mid,val,2*pos,lev);
        point_update(loc,mid+1,high,val,2*pos+1,lev);

    }
}

dt rangesumquery(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    
    if ((qlow > high) || (qhigh < low))//no overlap
    {
        dt z;
        z.val=0;
        z.lev=-1;
        return z;
    }
    if((qlow<=low)&&(qhigh>=high))//complete overlap
    {
        return a[pos];
    }
    ll mid = (high+low)/2;
    dt f=rangesumquery(qlow,qhigh,low,mid,2*pos);
    dt l=rangesumquery(qlow,qhigh,mid+1,high,2*pos+1);
    if(f.lev==l.lev)
    {
        dt r;
        r.val=f.val+l.val;
        r.lev=f.lev;
        return r;
    }
    else
    {
        if((f.lev==-1))
        return l;
        if(l.lev==-1)
        return f;
        dt r;
        r.lev=f.lev;
        r.val=f.val-l.val;
        return r;
    }

}




void dfs(ll u)
{
    in_time++;
    discover[in_time] = u;
    beg[u] = in_time;
    visit[u] = 1;
    for (int i = 0; i < store[u].size(); i++)
    {
        ll v = store[u][i];
        if (visit[v] == 1)
            continue;
        parent[v] = u;
        lev[v] = lev[u] + 1;
        dfs(v);
    }
    endi[u] = in_time;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    ll n, m;
    cin >> n >> m;
    ll arr[n+1];
    for (int i = 0; i < 200010; i++)
    {

        parent[i] = 0;
        visit[i] = 0;
        lev[i] = 0;
        a[i].val = 0;
        a[i].lev = -1;
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        store[u].push_back(v);
        store[v].push_back(u);
    }
    dfs(1);
    for (int i = 0; i < m; i++)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, val;
            cin >> x >> val;
            
            point_update(beg[x],0,n,val,1,(lev[x]%2));
            cout<<"here";
            
            point_update(endi[x]+1,0,n,-val,1,(lev[x]%2));
           
        }
        else
        {
            ll x;
            cin >> x;
            dt ans=rangesumquery(1,beg[x]-1,0,n-1,1);
            ll aaa=0;
            if((lev[x]%2)==ans.lev)
            {
                aaa=arr[x]+ans.val;
            }
            else
            {
                aaa=arr[x]-ans.val;
            }
                cout<<aaa<<"\n";
            
        }
    }
}