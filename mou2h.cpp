#include<bits/stdc++.h>
#define mod 1000000009

using namespace std;

int a[1000100];
long long dp[1000100];
long long sum[1000100];
int lst[8000800];
int *last;

template<class T> void printarray(T a[], int size)
{
	for(int i=1; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
// Uncomment to use TestCases
	int T, n;
	last = lst + 4000400;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		scanf("%d", a+1);
		for(int i=2; i<=n; i++)
		{
			scanf("%d", a+i);
			a[i-1] = a[i] - a[i-1];
		}
		printarray(a, n);
		memset(lst, 0, sizeof(lst));
		dp[0] = 0;
		sum[0] = 1;
		sum[-1] = 0;
		for(int i=1; i<n; i++)
		{
			dp[i] = (mod + sum[i-1] - sum[last[a[i]]-1])%mod;
			sum[i] = (sum[i-1] + dp[i])%mod;
			last[a[i]] = i;
		}
		printarray(dp, n);
		printarray(sum, n);
		printf("%lld\n", sum[n-1]-1);
	}
	return 0;
}

