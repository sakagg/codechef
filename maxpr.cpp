#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long expo(int ax, int b)
{
	long long ans = 1, a=ax;
	while(b)
	{
		if(b&1)
			ans*=a;
		a = (a*a)%mod;
		b>>=1;
	}
	return ans;
}

void print_array(vector<long long> &a)
{
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int t, n, a[200100];
	long long tot;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		tot = n+1;
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		for(int d=-100; d<=100; d++)
		{
			vector<long long> dp(110, 0);
			for(int i=0; i<n; i++)
			{
				if(a[i]-d <= 100 && a[i]-d >=1)
					dp[a[i]] += dp[a[i]-d];
				dp[a[i]]++;
			}
			for(int i=1; i<101; i++)
				tot = (tot+dp[i])%mod;
			tot = (tot - n) % mod;
//			cout<<"------"<<tot<<"--------\n";
//			if(d==0)
//				print_array(dp);
		}
		long long ans = (expo(2, n) - tot)%mod;
		if(ans<0)
			ans+=mod;
		printf("%lld\n", ans);
	}
	return 0;
}
