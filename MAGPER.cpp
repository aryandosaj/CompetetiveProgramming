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
struct dt{
    int p,n;
};
int a[100005];
int b[100005];
int arr[100005];
int brr[100005];
dt tree[400005];
void build(int l,int h,int pos)
{
    if(l==h)
    {
        int l2 = b[arr[l]];
        tree[pos].p = 0;
        tree[pos].n = 0;
        if(l<l2)tree[pos].n = l-l2;
        else tree[pos].p = l-l2;   
        return;    
    }
    int m = (l+h)/2;
    build(l,m,2*pos+1);
    build(m+1,h,2*pos+2);
    tree[pos].p = tree[2*pos+1].p + tree[2*pos+2].p;
    tree[pos].n = tree[2*pos+1].n + tree[2*pos+2].n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin>>n>>q;
        for(int i=0;i<n;i++){ll x;cin>>x;a[x]=i+1;arr[i+1]=x;}
        for(int i=0;i<n;i++){ll x;cin>>x;b[x]=i+1;brr[i+1]=x;}

    }
}