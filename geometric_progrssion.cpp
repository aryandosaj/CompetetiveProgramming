#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
map<ll, ll> coun;
struct my
{
    ll ind;
    ll val;
};
my arr[100001];

ll binser(ll low, ll high, ll x)
{
    if (low > high)
        return -1;
    ll mid = (low + high) / 2;
    if (arr[mid].val == x)
    {
        if (arr[mid - 1].val != x)
            return mid;
        else
            return binser(low, mid - 1, x);
    }
    if (arr[mid].val > x)
    {
        high = mid - 1;
        return binser(low, high, x);
    }
    if (arr[mid].val < x)
    {
        low = mid + 1;
        return binser(low, high, x);
    }
}
bool comp(my a, my b)
{
    return a.val < b.val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
        coun[arr[i].val]++;
        arr[i].ind = i;
    }
    sort(arr, arr + n, comp);
    ll c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((binser(i, n - 1, arr[i].val * k) != -1) && (binser(i, n - 1, arr[i].val * k * k) != -1))
        {
            if ((binser(i, n - 1, arr[i].val * k)) < (binser(i, n - 1, arr[i].val * k * k)))
            {
                c += (coun[arr[i] * k] * coun[arr[i] * k * k]);
            }
        }
    }
    cout << c;
}