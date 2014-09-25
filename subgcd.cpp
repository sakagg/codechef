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

int gcd(int a, int b)
{
	int tmp;
	while(b)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	int T, g;
	int n, a[100100];
	scanf("%d", &T);
	while(T--)
	{
		g = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		for(int i=0; i<n; i++)
			g = gcd(a[i], g);
		if(g==1)
			cout<<n<<endl;
		else
			cout<<"-1\n";
	}
	return 0;
}

