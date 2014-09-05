#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[200100][110];

int main()
{
	int t, n, a[200100];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
	}
	return 0;
}
