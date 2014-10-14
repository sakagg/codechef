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
#define mod 1000000009

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
	int n, m;
	LL ways;
	scanf("%d", &T);
	while(T--)
	{
		ways = 1;
		scanf("%d%d", &n, &m);
		vector< pair<int, char> > a(m);
		for(int i=0; i<m; i++)
		{
			getchar();
			scanf("%c %d", &a[i].s, &a[i].f);
		}
		sortv(a);
		int size = a.size();
		for(int i=1; i<size; i++)
			if(a[i-1].s != a[i].s)
				ways = (ways*(a[i].f - a[i-1].f))%mod;
		printf("%lld\n", ways);
	}
	return 0;
}

