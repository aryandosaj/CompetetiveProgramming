#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vint vector<int>
int power(int a, int b, int mod)
{
    int c = 1;
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
unordered_map<int,int> bit(int n)
{
    int i = 0;
    unordered_map<int,int>mp;
    while (n > 0)
    {
        mp[i++] = n % 2;
        n /= 2;
    }
    return mp;
}
int num(unordered_map<int,int> mp)
{
    int i = 0,n=0;
    for(int i=0;i<32;i++)
    {
        n+=mp[i]*pow(2,i);
    }
    return n;
}
unordered_map<int, int> add(unordered_map<int, int> a, unordered_map<int, int> b)
{
    for (int i = 0; i < 32; i++)
    {
        a[i] += b[i];
    }
    return a;
}
#define MAX 1000000007
unordered_map<int, int> arr[100005];
unordered_map<int, int> tree[400005];
int lazy[400005];
unordered_map<int, int> upd(unordered_map<int, int> a, unordered_map<int, int> b, int n)
{
    for (int i = 0; i < 32; i++)
    {
        if (b[i])
            a[i] = n - a[i];
    }
    return a;
}
void build(int low, int high, int pos)
{
    if (low > high)
        return;
    if (low == high)
    {
        tree[pos] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    tree[pos] = add(tree[2 * pos + 1], tree[2 * pos + 2]);
}
void update_lazy(int qlow, int qhigh, int low, int high, int pos, int v)
{

    if (lazy[pos] != 0)
    {
        tree[pos] = upd(tree[pos],bit(lazy[pos]) , (high - low + 1));
        if (low != high)
        {
            lazy[2 * pos + 1] ^= lazy[pos];
            lazy[2 * pos + 2] ^= lazy[pos];
        }
        lazy[pos] = 0;
    }

    if ((qlow <= low) && (qhigh >= high)) //complete overlap
    {

        tree[pos] = upd(tree[pos],bit(v) , (high - low + 1));
        if (low != high)
        {
            lazy[pos * 2 + 1] ^= v;
            lazy[pos * 2 + 2] ^= v;
        }
        return;
    }

    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return;
    }
    //partial overlap
    int mid = (high + low) / 2;
    update_lazy(qlow, qhigh, low, mid, (2 * pos + 1), v);
    update_lazy(qlow, qhigh, mid + 1, high, (2 * pos + 2), v);

    tree[pos] = add(tree[2 * pos + 1] , tree[2 * pos + 2]);
}

unordered_map<int,int> rangesumquery(int qlow,int qhigh,int low,int high,int pos)
{
    if(lazy[pos] != 0)
    {
        tree[pos] = upd(tree[pos],bit(lazy[pos]) , (high - low + 1));
        if(low!=high)
        {
            lazy[2*pos+1]^=lazy[pos];
            lazy[2*pos+2]^=lazy[pos];
        }
        lazy[pos]=0;
    }
    if ((qlow > high) || (qhigh < low))//no overlap
    {
        unordered_map<int,int>mp;
        return mp;
    }
    if((qlow<=low)&&(qhigh>=high))//complete overlap
    {
        return tree[pos];
    }
    int mid = (high+low)/2;

    return add(rangesumquery(qlow,qhigh,low,mid,2*pos+1),rangesumquery(qlow,qhigh,mid+1,high,2*pos+2));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i]=bit(x);
    }
    build(0,n-1,0);
    int m;
    cin >> m;
    while (m--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<num(rangesumquery(l-1,r-1,0,n-1,0))<<"\n";
        }
        else
        {
            int l,r,x;
            cin>>l>>r>>x;
            update_lazy(l-1,r-1,0,n-1,0,x);
        }
        
    }
}