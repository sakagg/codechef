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
	LL a[100100], sum[100100], rsum[100100];
	while(T--)
	{
		int n, k;
		SI(n);
		SI(k);
		for(int i=0; i<n; i++)
			SLL(a[i]);
		sum[0] = INT_MIN;
		LL mx = INT_MIN;
		LL tot = 0;
		for(int i=1; i<=n; i++)
		{
			mx = max(mx, a[i-1]);
			tot += a[i-1];
			sum[i] = max(sum[i-1], tot);
			if(tot<0)
				tot = 0;
		}
		rsum[n] = INT_MIN;
		mx = INT_MIN;
		tot = 0;
		for(int i=n-1; i>=0; i--)
		{
			mx = max(mx, a[i]);
			tot += a[i];
			rsum[i] = max(rsum[i+1], tot);
			if(tot<0)
				tot = 0;
		}
//		print_array(sum, n+1);
//		print_array(rsum, n+1);
		mx = INT_MIN;
		for(int i=1; i<(n-k); i++)
			mx = max(mx, sum[i] + rsum[i+k]);
		printf("%lld\n", mx);
	}
	return 0;
}

