#include <bits/stdc++.h>
<<<<<<< HEAD
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll a,b;
    cin>>a>>b;
    ll m=0;
    for(ll i=a;i<=b;i++)
    {
        for(int j = i+1; j <=b; j++)
        {
            m=max(m,i^j);
        }
        
    }
    cout<<m;
=======
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"1000\n";
    for(int i=1;i<=1000;i++)
    cout<<"1 "<<i<<"\n";
>>>>>>> after a long time
}