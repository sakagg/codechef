
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

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, q;
		SI(n); SI(q);
		int a[100100], pre[100100], pst[100100];
		for(int i=0; i<n; i++)
			SI(a[i]);
		pre[0] = pst[n] = 0;
		for(int i=1; i<=n; i++)
			pre[i] = __gcd(pre[i-1], a[i-1]);
		for(int i=n-1; i>=0; i--)
			pst[i] = __gcd(pst[i+1], a[i]);
		int l, r;
		while(q--)
		{
			SI(l); SI(r);
			printf("%d\n", __gcd(pre[l-1], pst[r]));
		}
	}
	return 0;
}
