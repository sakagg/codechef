#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
// Uncomment to use TestCases
	int T, mx, x, y, a, b, c, d, num;
	unsigned long long ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &num);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d", &x, &y);
		ans = num;
		mx = max(x, y);
		while((mx&(-mx))!=mx)
			mx += mx&(-mx);
		mx >>= 1;
//		cout<<mx<<endl;
		while(mx)
		{
			if(y>mx)
			{
				y-=mx;
				if(x>mx)
				{
					x-=mx;
					ans *= d;
				}
				else
					ans *= b;
			}
			else
			{
				if(x>mx)
				{
					x-=mx;
					ans *= c;
				}
				else
					ans*=a;
			}
			mx /= 2;
		}
		printf("%llu\n", ans);
	}
	return 0;
}

