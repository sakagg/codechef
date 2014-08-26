#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	int n;
	long long vals[5], ans;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		vals[0] = n;
		vals[1] = n;
		vals[2] = vals[1] * (n-1);
		vals[3] = vals[2] * (n-2);
		vals[4] = vals[3] * (n-3);
//		for(int i=0; i<5; i++)
//			cout<<vals[i]<<" ";
		ans = 2*vals[2] + 5*vals[3] + 2*vals[4];
		printf("%lld\n", ans);
	}
	return 0;
}
