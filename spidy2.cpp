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
#define INF 1e16

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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n;
	int a[200200];
	LL dp[200200];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	dp[0] = 0;
	for(int i=1; i<n; i++)
	{
		dp[i] = INF;
		for(int j=1; j<=i; j<<=1)
			dp[i] = min(dp[i], dp[i-j] + abs(a[i]-a[i-j]));
	}
	printf("%lld\n", dp[n-1]);
	return 0;
}

