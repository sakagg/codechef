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
	scanf("%d", &T);
	while(T--)
	{
		int n, a, m;
		scanf("%d%d%d", &n, &a, &m);
		int ans = (m+a)%n;
		if(!ans)
			ans = n;
		printf("%d\n", ans);
	}
	return 0;
}

