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
	int n, m;
	int a[100100];
	int mn, mx;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		mn = INT_MAX;
		mx = -1;
		for(int i=0; i<m; i++)
		{
			scanf("%d", a+i);
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		for(int i=0; i<n; i++)
			printf("%d ", max(abs(i-mn), abs(i-mx)));
		printf("\n");
	}
	return 0;
}

