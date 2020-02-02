#include<bits/stdc++.h>
#define ll long long int
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
ll MAX = 20,n,q,y,tim = 0;
ll bitCount[100001], BIT[100001], in[100001], out[100001],parent[100001][20], lev[100001];
ll val[100001],res = 0,MOD = 1000000000000+39;
vector<ll> adj[100001];
void update(ll index,ll val)
    {
        for(ll i=index;i<=n;i+=i&-i)
            BIT[i]+=val;
    }
    ll query(ll index)
    {
        ll sum = 0;
        for(ll i=index;i>0;i-=i&-i)
            sum+=BIT[i];
        return sum;
    }
    ll query(ll l, ll r) {
        return query(r) - query(l-1);
    }
ll calc(ll v) {             //calculates the number of le nodes in the path from v to root
        if(query(in[1], out[1])<=y) {
            return 0;
        }
        ll curr = v;
        if(query(in[v], out[v])>y) {
            return lev[v]+1;
        }
        for(ll i=MAX-1;i>=0;--i) {
             if(parent[curr][i]!=0) {
                 ll papa = parent[curr][i];
                 if(query(in[papa], out[papa])<=y) {
                     curr = papa;
                 }
             }
        }
        //pl("curr : "+curr);
        return lev[curr];
    }
    void dfs(ll v, ll par) {
        in[v] = ++tim;
        lev[v] = lev[par]+1;
        parent[v][0] = par;
        for(ll i=1;i<MAX;++i) {
            if(parent[v][i-1]!=0) {
                parent[v][i] = parent[parent[v][i-1]][i-1];
            }
            else {
                parent[v][i] = 0;
            }
        }
        update(in[v], bitCount[v]);
        for(ll i=0;i<adj[v].size();i++) {
            if(adj[v][i]!=par) {
                dfs(adj[v][i], v);
            }
        }
        out[v] = tim;
    }
 
    ll multiply_(ll x,ll y,ll mod)
    {
        res = 0;
        while(y>0)
        {
            if((y&1)==1)
                res+=x;
            if(res>=mod) {
                res-=mod;
            }
            y>>=1;
            x+=x;
            if(x>=mod) {
                x-=mod;
            }
        }
        return res;
    }
    ll cnt(ll n) {
 
        ll r = 0;
        while(n>0) {
            n = (n&(n-1));
            ++r;
        }
        return r;
    }
int main() {
   FAST;
   //cout<<"Hello world!\n";
   //cout<<MOD;
     cin>>n>>y;
       ll u,v;
        for(ll i=1;i<n;++i) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(ll i=1;i<=n;++i) {
            cin>>val[i];
            bitCount[i] = cnt(val[i]);
        }
        lev[0] = -1;
        dfs(1,0);
        //pa("in", in);
        //pa("out", out);
        ll leNode = 0;
        for(ll i=1;i<=n;++i) {
           // pl("node: "+i+"sum : "+query(in[i], out[i]));
            if(query(in[i], out[i])>y) {
                ++leNode;
            }
        }
        //pl("lenode : "+leNode);
 ll a,b;
        cin>>q;
        while(q-->0) {
            cin>>a>>b;
            ll prev = calc(a);
            //pl("prev : "+prev);
            val[a] = multiply_(val[a], b, MOD);
            ll change = cnt(val[a]) - bitCount[a];
            //pl("change : "+change);
            bitCount[a] = cnt(val[a]);
            update(in[a], change);
           // for(int i=1;i<=n;++i) {
             //   pl("node "+i+" sum : "+query(in[i], out[i]));
            //}
            ll now = calc(a);
            //pl("now : "+now);
            leNode+=(now-prev);
            cout<<leNode<<"\n";
        }
   return 0;
}