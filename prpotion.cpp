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
	int r, g, b, m;
	int mn, num;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &r, &g, &b, &m);
		int rmax = 0, gmax = 0, bmax = 0;
		for(int i=0; i<r; i++)
		{
			scanf("%d", &num);
			rmax = max(rmax, num);
		}
		for(int i=0; i<g; i++)
		{
			scanf("%d", &num);
			gmax = max(gmax, num);
		}
		for(int i=0; i<b; i++)
		{
			scanf("%d", &num);
			bmax = max(bmax, num);
		}
		int a[] = {rmax, gmax, bmax};
		sort(a, a+3);
		mn = a[2];
		for(int i=0; i<m; i++)
		{
			a[2] /= 2;
			a[0] += 1;
			a[1] += 1;
			sort(a, a+3);
			mn = min(mn, a[2]);
		}
		printf("%d\n", mn);
	}
	return 0;
}

