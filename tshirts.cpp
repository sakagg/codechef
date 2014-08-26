#include<climits>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define mod 1000000007

using namespace std;

int all;
int n;
long long dp[1050][110];
int a[11][110];

long long calc(int mask, int id)
{
	if(mask==0)
		return (dp[0][id] = 1);
	if(id==0)
		return 0;
	if(dp[mask][id]!=-1)
		return dp[mask][id];
	long long ans = calc(mask, id-1);
	for(int i=0; i<n; i++)
		if(a[i][id] && (mask&(1<<i)))
			ans+=calc(mask-(1<<i), id-1);
	ans%=mod;
	return (dp[mask][id] = ans);
}

int main()
{
// Uncomment to use TestCases
	int T;
	int id, i;
	char c;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		all = (1<<n)-1;
		memset(a, 0, sizeof(a[0][0])*11*110);
		memset(dp, -1, sizeof(dp[0][0])*1050*110);
		for(i=0; i<n; i++)
			while(1)
			{
				scanf("%d%c", &id, &c);
				a[i][id] = 1;
				if(c=='\n')
					break;
			}
//		for(int i=1; i<=100; i++)
//			cout<<a[i]<<" ";
		printf("%lld\n", calc(all, 100)%mod);
	}
	return 0;
}

