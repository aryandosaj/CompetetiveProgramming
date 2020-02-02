#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, temp;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = n, j = n - 1;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        if (a[i] * 2 <= a[j])
        {
            ans--;
            j--;
        }
    }
    cout << ans;
}