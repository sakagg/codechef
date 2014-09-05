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
/*
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, m, t;
	cin>>n>>m;
	t = (m+1)/2;
	int a[1000100], i;
	for(i=0; i<n; i++)
		scanf("%d", a+i);
	for(i=0; i<n ;i++)
		if(a[i]>t)
			break;
	if(i==n)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

