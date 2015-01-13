
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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, m;
	SI(n); SI(m);
	int a[50][50];
	LL sum[50] = {0};
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			SI(a[i][j]);
			sum[j] += a[i][j];
		}
	LL ans = 1;
	const int mod = 1e7 + 7;
	for(int i=0; i<m; i++)
	{
		if(sum[i] < 0)
			sum[i] += mod;
		ans = (ans*sum[i])%mod;
	}
	printf("%lld\n", ans);
	return 0;
}
