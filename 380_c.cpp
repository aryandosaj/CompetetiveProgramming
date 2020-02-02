#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
string s;
struct node
{
    ll a, b, c;
};
node tree[4000005];
void merge(ll pos)
{
    ll t = min(tree[2 * pos + 1].b, tree[2 * pos + 2].c);
    tree[pos].a = (tree[2 * pos + 1].a + tree[2 * pos + 2].a) + t;
    tree[pos].b = tree[2 * pos + 1].b + tree[2 * pos + 2].b - t;
    tree[pos].c = tree[2 * pos + 1].c + tree[2 * pos + 2].c - t;
}
void make_tree(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree[pos].a = 0;
        tree[pos].b = (s[low] == '(') ? 1 : 0;
        tree[pos].c = (s[low] == ')') ? 1 : 0;
        return;
    }
    ll mid = (low + high) / 2;
    make_tree(low, mid, 2 * pos + 1);
    make_tree(mid + 1, high, 2 * pos + 2);
    merge(pos);
    return;
}

node rangeminquery(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    if((qlow<=low)&&(qhigh>=high))//comleteOverlap
    {
        return tree[pos];
    }
    if((qlow>high)||(qhigh<low))//no overlap
    {
        
        return {0,0,0};
    }
    ll mid = (high+low)/2;
    node t1 = rangeminquery(qlow,qhigh,low,mid,2*pos+1);
    node t2 = rangeminquery(qlow,qhigh,mid+1,high,2*pos+2);
    node t3;
    ll t = min(t1.b,t2.c);
    t3.a = t1.a+t2.a+t;
    t3.b = t1.b+t2.b-t;
    t3.c = t1.c+t2.c-t;
    return t3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll size = s.length()-1;
    make_tree(0,size,0);
    ll q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        node t = rangeminquery(l,r,0,size,0);
        cout<<2*t.a<<"\n";
    }
}