#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL mod;

LL sum4(LL n)
{
	n %= mod;
	LL ans = n;
	ans *= (2*n + 1);
	ans %= mod;
	ans *= n+1;
	ans	%= mod;
	ans *= (3*n*(n+1) -1)%mod;
	ans %= mod;
	ans /= 30;
	ans %= (mod/30);
	return ans;
}

int main()
{
// Uncomment to use TestCases
	LL n, mod, ans, cur, nxt, div;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld", &n, &mod);
		::mod = mod*30;
		nxt = 1;
		while(nxt<=n)
		{
			cur = nxt;
			div = n/cur;
			nxt = n/div;
			ans += (div*(sum4(nxt)-sum4(cur-1))) % mod;
//			cout<<ans<<"------\n";
			ans %= mod;
			nxt++;
		}
		if(ans<0)
			ans+=mod;
		printf("%lld\n", ans);
	}
	return 0;
}

