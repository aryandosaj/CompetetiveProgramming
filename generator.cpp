#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll lrand()
{
    double r;
    r = ((double) rand() / (RAND_MAX*1.0));
    return (ll)(r*1000000)+1;
}
int main()
{   
    
    freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout<<100000<<"\n";
   cout<<"1 3\n2 3\n";
   for(int i=3;i<100000;i++)
   cout<<i<<" "<<i+1<<"\n";
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<10000<<"\n";
    for(int i=0;i<10000;i++)
    cout<<i<<"\n";

}