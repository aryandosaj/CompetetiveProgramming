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
#define MAX 1000000007
int arr[1000001];

struct circle
{
    double x, y, r;
};
bool isInteger(double x)
{
    if (x == floor(x))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    circle xy[1001];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> xy[i].x >> xy[i].y >> xy[i].r;
    }

    for (int i = 0; i < 1000001; i++)
    {
        arr[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double d = sqrt((xy[i].x - xy[j].x) * (xy[i].x - xy[j].x) + (xy[i].y - xy[j].y) * (xy[i].y - xy[j].y));
            if (d <= abs(xy[i].r - xy[j].r))
            {
                if (isInteger((abs(xy[i].r - xy[j].r) - d)))
                    arr[(int)(abs(xy[i].r - xy[j].r) - d)]++;
                else
                    arr[(int)(abs(xy[i].r - xy[j].r) - d + 1)]++;

                arr[(int)(d + xy[i].r + xy[j].r + 1)]--;
            }
            else if (d <= (xy[i].r + xy[j].r))
            {
                arr[0]++;
                arr[(int)(d + xy[i].r + xy[j].r + 1)]--;
            }
            else
            {
                if (isInteger((d - xy[i].r - xy[j].r)))
                    arr[(int)(d - xy[i].r - xy[j].r)]++;
                else
                    arr[(int)(d - xy[i].r - xy[j].r + 1)]++;
                // arr[(int)(d - xy[i].r - xy[j].r)]++;
                arr[(int)(d + xy[i].r + xy[j].r + 1)]--;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 1000001; i++)
    {
        sum += arr[i];
        arr[i] = sum;
    }
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        cout << arr[k] << "\n";
    }
}