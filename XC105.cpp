#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int x, y, n;
		SI(y); SI(x); SI(n);
		vector<int> v(n);
		for(int i=0; i<n; i++)
			SI(v[i]);
		sort(v.rbegin(), v.rend());
		int cnt = 0;
		y -= x;
		for(int i=0; i<n; i++)
		{
			cnt += y/v[i];
			y %= v[i];
		}
		printf("%d\n", cnt);
	}
	return 0;
}

