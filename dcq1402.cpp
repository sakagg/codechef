#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n;
	SLL(n);
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
	{
		SLL(v[i].f);
		v[i].s = i;
	}
	LL ans;
	sortv(v);
	ans = v[n-1].f;
	if(n>=3)
		for(int i=max(0LL, n-4); i<n; i++)
			for(int j=i+1; j<n; j++)
				if(abs(v[i].s-v[j].s) != 1)
					ans = max(ans, v[i].f+v[j].f);
	printf("%lld\n", ans);
	return 0;
}
