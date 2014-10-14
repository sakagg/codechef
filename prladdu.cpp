#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int T;
	int n, num;
	scanf("%d", &T);
	while(T--)
	{
		vector< pair<int, int> > p, d;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &num);
			if(num>0)
				p.pb(mp(num, i));
			else if(num<0)
				d.pb(mp(-num, i));
		}
		LL cost = 0;
		int psize = p.size(), dsize = d.size();
		int i=0, j=0;
		while(i<psize || j<dsize)
		{
			if(p[i].f < d[j].f)
			{
				cost += p[i].f*abs(p[i].s - d[j].s);
				d[j].f -= p[i].f;
				i++;
			}
			else if(p[i].f == d[j].f)
			{
				cost += p[i].f*abs(p[i].s - d[j].s);
				i++;
				j++;
			}
			else
			{
				cost += d[j].f*abs(p[i].s - d[j].s);
				p[i].f -= d[j].f;
				j++;
			}
		}
		printf("%lld\n", cost);
	}	
	return 0;
}

