#include <bits/stdc++.h>
using namespace std;
double l_seg[200005];
double r_seg[200005];
double sum[200005];
int main()
{
    sum[0]=0;
    l_seg[0]=0;
    r_seg[0]=0;
    double s, a, b;
    scanf("%lf%lf%lf", &s, &a, &b);
    int n;
    scanf("%d", &n);
    double ss = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &l_seg[i], &r_seg[i]);
        ss += (r_seg[i] - l_seg[i]);    
        sum[i] = ss;
    }
    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        double x, y;
        scanf("%lf%lf", &x , &y);
        double a1 = x - y * (x - a)/ (y - s) ;
        double b1 = x - y * (x - b)/ (y - s) ;
        int ind = upper_bound(l_seg+1, l_seg+ 1 + n, a1+1e-6) - l_seg - 1;
        int ind2 = upper_bound(l_seg+1, l_seg +1+ n, b1+1e-6) - l_seg - 1;
        double ans = 0;
        ans+=ind>0?max(r_seg[ind]-a1,0.0)-sum[ind]:0;
        ans+=(ind2>0)?min(r_seg[ind2],b1)-l_seg[ind2]+sum[ind2-1]:0;
        printf("%.10f\n", (ans * (y - s) / y));
    }
}