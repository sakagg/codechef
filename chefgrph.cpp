
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

const LL mod = (1e9) + 7;

LL fastPow(LL a, LL b)
{
	LL ans = 1;
	while(b)
	{
		if(b&1LL)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return ans;
}
		
int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	LL n, m, k;
	SLL(n); SLL(m); SLL(k);
	map<pair<LL, LL>, LL> points;
	map<LL, LL> lines;
	vector<pair< pair<LL, LL>, pair<LL, LL> > > a;
	vector<pair<LL, LL> > b;
	for(int i=0; i<k; i++)
	{
		LL p, q, r, s;
		SLL(p); SLL(q); SLL(r); SLL(s);
		a.pb(mp(mp(p, q), mp(0, 0)));
		a.pb(mp(mp(r, s), mp(1, i)));
		b.pb(mp(p, q));
	}
	sort(a.begin(), a.end());
	LL last = 0;
	lines[0] = 1;
	points[mp(0, 0)] = 1;
	EACH(it, a)
	{
		if(last < it->f.f-1)
		{
			lines[it->f.f - 1] = (lines[last] * fastPow(m, it->f.f - last - 1))%mod;
			last = it->f.f - 1;

//			printf("Lines set for %lld: %lld\n", last, lines[last]);
		}
		
		if(points.find(it->f) == points.end())
			points[it->f] = lines[it->f.f - 1];
		
		if(it->s.f == 1)
		{
			if(last < it->f.f)
			{
				if(it->f.f <= n)
					lines[it->f.f] = (lines[it->f.f - 1]*m)%mod;
				else
					lines[it->f.f] = lines[it->f.f - 1];

				last = it->f.f;
//				printf("Lines set for %lld: %lld\n", last, lines[last]);
			}
			LL tmp = points[b[it->s.s]];
			points[it->f] += tmp;
			points[it->f] %= mod;
			lines[it->f.f] += tmp;
			lines[it->f.f] %= mod;
		}
//		printf("Point set for (%lld, %lld): %lld\n", it->f.f, it->f.s, points[it->f]);
	}
	LL ans;
	if(last < n)
		lines[n] = (lines[last] * fastPow(m, n - last))%mod;
	ans = points[mp(n+1, 0)];
	if(ans == 0)
		ans = lines[n];

	printf("%lld\n", ans);

	return 0;
}
