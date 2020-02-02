#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    double n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;
    double num = n;
    double len = l;
    double tim = 0;
    if (v1 >= v2)
    {
        cout << (l / v1);
    }
    else
    {
        while ((num > 0) && (len > 0))
        {
            double t1 = len / v2;
            num -= k;
            tim+=t1;
            if(num<=0)
            break;
            double t2 = (len - t1 * v1) / (v1 + v2);
            tim+=t2;
            len = (v2 * t2);
            cout<<tim<<" ";
        }
        cout << tim;
    }
}