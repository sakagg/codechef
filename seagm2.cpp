
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

const double eps = 1e-307;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		SI(n); SI(m);
		pair< int, pair<double, int> > v[20];
		double d;
		for(int i=0; i<n; i++)
		{
			v[i].f = 1;
			v[i].s.f = 1;
			v[i].s.s = 0;
			for(int j=0; j<m; j++)
			{
				scanf("%lf", &d);
				if(!v[i].f)
					continue;
				if(d < eps)
				{
					v[i].f = 0;
					continue;
				}
				v[i].s.f *= d;
				while(v[i].s.f < 1)
				{
					v[i].s.s++;
					v[i].s.f *= 10;
				}
			}
		}
		if(v[0].f == 0)
		{
			printf("0.000000\n");
			continue;
		}
		vector< pair<double, int> > a;
		for(int i=0; i<n; i++)
			if(v[i].f)
				a.pb(mp(v[i].s.f, v[i].s.s - v[0].s.s));
		int ans0 = 0;
		EACH(it, a)
		{
			if(it->s <= -10)
			{
				ans0 = 1;
				break;
			}
		}
		if(ans0)
		{
			printf("0.000000\n");
			continue;
		}
		double sum = 0;
		EACH(it, a)
			sum += it->f * pow(10, -it->s);
		printf("%.6lf\n", a[0].f/sum);

	}
	return 0;
}
