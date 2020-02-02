#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pdouble pair<double, double>
#define pb push_back
#define F first
#define S second
#define I insert
#define vdouble vector<double>
// double power(double a, double b, double mod){ double c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
double arr[1000005];
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    double t;
    scanf("%lf", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        map<double, int> mp;

        vdouble v;

        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &arr[i]);
            mp[arr[i]]++;
            if(mp[arr[i]]==2)
            {v.push_back(arr[i]);mp[arr[i]]=0;}
        }
        double dif = MAX;
        sort(v.begin(), v.end());
        int a1, a2;
        for (int i = v.size() - 2; i >= 0; i--)
        {
            double temp = (v[i + 1] / v[i] + v[i] / v[i + 1]);
            if (temp < dif)
            {
                dif = temp;
                a1 = (int)v[i];
                a2 = (int)v[i + 1];
                if (dif == 0)
                    break;
            }
        }
        printf("%d %d %d %d\n",a1,a1,a2,a2);
    }
}