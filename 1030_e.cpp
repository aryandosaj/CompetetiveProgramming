#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAX 100000007
ll bit_sum(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 2;
        n /= 2;
    }
    return sum;
}
ll bit[300005];
ll tree[3000000];
void make_tree(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree[pos] = bit[low];
        return;
    }
    ll mid = (low + high) / 2;
    make_tree(low, mid, 2 * pos + 1);
    make_tree(mid + 1, high, 2 * pos + 2);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}
ll max_query(ll low, ll high, ll qlow, ll qhigh, ll pos)
{
    if ((qhigh < low) || (qlow > high))
        return 0;
    else if ((low >= qlow) && (high <= qhigh))
    {
        return tree[pos];
    }
    else
    {
        ll mid = (low + high) / 2;
        return max(max_query(low, mid, qlow, qhigh, 2 * pos + 1), max_query(mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n];
    ll pre_sum[n];
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        bit[i] = bit_sum(arr[i]);
        sum += bit[i];
        pre_sum[i] = sum;
    }
    for(ll i = 0; i < n; i++)
    {
        cout<<bit[i]<<" ";
    }
    cout<<"\n";
    ll post_even[n+1];
    ll post_odd[n+1];
    post_even[n-1]=0;
    post_odd[n-1]=0;

    
    for(ll i = 1; i < n; i++)
    {
        post_even[n-1-i] = post_even[n-i]+(!((bit[n-i])&1));
        post_odd[n-1-i] = post_odd[n-i]+((bit[n-i]&1));
    }
    for(ll i = 0; i < n; i++)
    {
        cout<<pre_sum[i]<<" ";
    }
    cout<<"\n";
    for(ll i = 0; i < n; i++)
    {
        cout<<post_even[i]<<" ";
    }
    cout<<"\n";
     for(ll i = 0; i < n; i++)
    {
        cout<<post_odd[i]<<" ";
    }
    ll ans_m=post_even[0] - !(bit[0]&1);
    for(ll i = 0; i < n-1; i++)
    {
        ans_m+=pre_sum[i]&1?post_odd[i+1]:post_even[i+1];
    }
    make_tree(0, n - 1, 0);
    ll c = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j < 62; j++)
        {
            if ((i + j )>= n)
                break;
            ll temp = i != 0 ? pre_sum[j + i] - pre_sum[i - 1] : pre_sum[i+j];
            ll mmm = max_query(0, n - 1, i, i + j, 0);
            // cout<<i<<" "<<j<<" s = "<<temp<<"m = "<<mmm<<"\n";
            
            if((mmm>(temp/2))&&(!(temp&1)))
                c++;
        }
    }
    ll ans =  ans_m-c;
    cout << ans<<" "<<c;
}