#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll c = 1;
    ll a2[2];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        ll num = arr[i];
        ll mul = 1;
        ll m=20000000100;
        while (mul < m)
        {
            
            int l, r;
            l = binary_search(arr, arr + n, num - mul);
            r = binary_search(arr, arr + n, num + mul);
            // cout<<"l="<<l<<"r="<<r<<"\n";
            if ((l == 1) && (r == 1))
            {
                cout << "3\n";
                cout << (num - mul) << " " << num << " " << (num + mul);
                return 0;
            }
            if (c != 2)
                if ((l == 1) || (r == 1))
                {
                    c = 2;
                    a2[1] = num;
                    if (l == 1)
                    {
                        a2[0] = num - mul;
                    }
                    else
                        a2[0] = num + mul;
                }
            mul *= 2;
        }
    }
    cout << c << "\n";
    if (c == 1)
        cout << arr[0];
    else
        cout << a2[0] << " " << a2[1];
}