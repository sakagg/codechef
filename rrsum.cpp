#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
// Uncomment to use TestCases
/*	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	long long n, m, q, ans;
	scanf("%lld%lld", &n, &m);
	while(m--)
	{
		scanf("%lld", &q);
		q-=n;
		if(q<2 || q>(3*n))
			ans = 0;
		else if(q<=n+1)
			ans = q-1;
		else
			ans = (2*n+1)-q;
		printf("%lld\n", ans);
	}
	return 0;
}

