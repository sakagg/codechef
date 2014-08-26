#include<climits>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct org
{
	int s;
	int e;
};

bool cmp(org a, org b)
{
	return a.e<b.e;
}

int main()
{
// Uncomment to use TestCases
/*	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, s, t;
	org a[100100];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d", &a[i].s, &t);
		a[i].e = a[i].s+t;
	}
	sort(a, a+n, cmp);
	int ans = 0, last = -1;;
	for(int i=0; i<n; i++)
	{
		if(a[i].s > last)
		{
			last = a[i].e;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
