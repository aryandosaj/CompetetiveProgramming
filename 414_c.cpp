#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vint vector<int>
#define MAX 1000000007
struct dt
{
    ll d1, d2;
};
int arr[1050000];
vint brr;
unordered_map<int, int> mp;
int bit[1050000];
ll d1[30];
ll d2[30];
void update(int i, int v)
{
    for (i; i < 1050000; i += (i & (-i)))
        bit[i] += v;
}
int query(int i)
{
    if (i == 0)
        return 0;
    int ans = 0;
    for (i; i > 0; i -= (i & (-i)))
        ans += bit[i];
    return ans;
}
dt mer(int l, int h)
{
    dt ans;
    unordered_map<int, int> temp;
    ans.d1 = 0;
    ans.d2 = 0;
    int c, y = h;
    int m = (l + h) / 2;
    
    for (int i=l; i <= m; i++)
    {
        ans.d1+=lower_bound(arr+m+1,arr+h+1,arr[i])-(arr+m+1);
		ans.d2+=h-m-(upper_bound(arr+m+1,arr+h+1,arr[i])-(arr+m+1));
    }
    sort(arr+l,arr+h+1);
    return ans;
}
void build(int low, int high, int d)
{
    if (low == high)
    {
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        build(low, mid, d + 1);
        build(mid + 1, high, d + 1);
        dt temp;
        temp = mer(low, high);
        d1[d] += temp.d1;
        d2[d] += temp.d2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> arr[i];
        brr.push_back(arr[i]);
    }
    sort(brr.begin(), brr.end());
    mp[brr[0]] = 1;
    for (int i = 1; i < (1 << n); i++)
    {
        if (brr[i] > brr[i - 1])
            mp[brr[i]] = mp[brr[i - 1]] + 1;
    }
    for (int i = 0; i < (1 << n); i++)
        arr[i] = mp[arr[i]];
    build(0, (1 << n) - 1,  0);
    int m;
    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        q = n - q;
        for(q;q<=n;q++)
        swap(d1[q], d2[q]);
        ll a = 0;
        for (int i = 0; i <= n; i++)
            a += d1[i];
        cout << a << "\n";
    }
}