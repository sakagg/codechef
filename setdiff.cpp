
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

const int mod = 1e9+7;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n; SI(n);
		int a[100100];
		for(int i=0; i<n; i++)
			SI(a[i]);
		sort(a, a+n);
		LL pw = 1;
		LL ans = 0;
		for(int i=0; i<n; i++)
		{
			ans = (ans + a[i]*pw)%mod;
			pw = (pw*2)%mod;
		}
		pw = 1;
		for(int i=n-1; i>=0; i--)
		{
			ans = (ans - a[i]*pw)%mod;
			pw = (pw*2)%mod;
		}
		ans = (ans+mod)%mod;
		printf("%lld\n", ans);
	}
	return 0;
}
