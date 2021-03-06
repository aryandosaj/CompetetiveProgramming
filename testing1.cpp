#include <cstdio>
#include <map>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long

struct Trie
{
	map<int, Trie> m;
};
Trie r;
void insert(Trie& t, int p, LL n)
{
	if (p >= 0) insert(t.m[(n>>p)&1], p-1, n);
}
LL best(Trie& t, int p, LL n)
{
	if (p < 0) return 0;
	bool b = (n>>p)&1;
	if (t.m.count(!b)) return (1LL<<p)+best(t.m[!b], p-1, n);
	else return best(t.m[b], p-1, n);
}

#define N 100000

int n; LL vet[N];

int main()
{
	cin >> n;
	LL z, m = 0, o = 0;
	for (int i = 0; i < n; ++i)
		cin >> vet[i], m ^= vet[i];
	z = m;
	insert(r, 60, 0);
	for (int i = n-1; i >= 0; --i)
	{
		m ^= vet[i];
		o ^= vet[i];
		insert(r, 60, o);
		z = max(z, best(r, 60, m));
	}
	cout << z ;
}