#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
#define pii pair<long long, long long>
#define F first
#define S second
vector<pii> factors[MAX];
bool isPrime[MAX];
struct dt
{
    long long f, s;
};
dt pre[MAX];
bool comp(dt a, dt b)
{
    if (a.f != b.f)
        return a.f < b.f;
    else
        return a.s < b.s;
}
bool comp2(dt a, long long b)
{
    return a.f < b;
}
void sieveOfEratothenese()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i < MAX; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i; j < MAX; j += i)
            {
                long long k, l;
                isPrime[j] = false;
                for (k = j, l = 0; k % i == 0; l++, k /= i)
                    ;
                factors[j].push_back(make_pair(i, l));
            }
        }
    }
}

long long sumOfProperDivisors(long long num)
{
    long long mul = 1, x = 1;
    for (long long i = 0; i < factors[num].size(); i++)
        mul *= ((pow(factors[num][i].F,
                     factors[num][i].S + 1) -
                 1) /
                (factors[num][i].F - 1)),
            x *= (1 + factors[num][i].S);

    return mul + num - x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieveOfEratothenese();
    for (long long i = 1; i < MAX; i++)
    {
        pre[i].f = sumOfProperDivisors(i);
        pre[i].s = i;
    }
    sort(pre, pre + MAX, comp);
    long long t;
    cin >> t;
    while (t--)
    {
        long long s;
        cin >> s;
        cout << (*lower_bound(pre, pre + MAX, s, comp2)).s << "\n";
    }

    return 0;
}
