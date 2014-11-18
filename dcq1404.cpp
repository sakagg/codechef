#include<bits/stdc++.h>

typedef long long LL;

#define SI(x) scanf("%lld", &x)
#define pb push_back

using namespace std;

int main()
{
	LL n;
	LL e, t, v;
	LL a[300300];
	vector<LL> dp;
	vector<LL>::iterator it;
	scanf("%lld", &n);
	for(LL i=0; i<n; i++)
		scanf("%lld", a+i);
	for(LL i=0; i<n; i++)
	{
		it = lower_bound(dp.begin(), dp.end(), a[i]);
		if(it==dp.end())
			dp.pb(a[i]);
		else
			*it = a[i];
	}
	SI(e);
	while(e--)
	{
		SI(t);
		SI(v);
		if(t==1)
			printf("%lld\n", dp.size());
		else
		{
			it = lower_bound(dp.begin(), dp.end(), v);
			if(it==dp.end())
				dp.pb(v);
			else
				*it = v;
		}
	}
	return 0;
}
