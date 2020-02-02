#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m,x,y;
   cin>>n>>m>>x>>y;
   ll ans=(x-1)*(y-1) - (min(x-1,y-1)-1) + (n-x)*(y-1) - (min(n-x,y-1)-1) + (m-y)*(x-1) - (min(m-y,x-1)-1) + (n-x)*(m-y)-(min(m-y,n-x)-1);
    if(x>1)ans++;
    if(x<n)ans++;
    if(y>1)ans++;
    if(y<m)ans++;
    cout<<ans;
}