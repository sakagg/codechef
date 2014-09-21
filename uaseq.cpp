#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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
	int n, K, count;
	LL a[100100], amin = INT_MAX, dmin = INT_MAX, d;
	scanf("%d%d", &n, &K);
	for(int i=0; i<n; i++)
		scanf("%lld", a+i);
	for(int i=0; i<K+2; i++)
		for(int j=i+1; j<K+2; j++)
		{
			count = 0;
			d = a[j] - a[i];
			if(d%(j-i) != 0)
				continue;
			d /= (j-i);
			for(int k=0; k<n; k++)
				if(a[k] != a[i]+(k-i)*d)
				{
					count++;
					if(count > K)
						break;
				}
//			printf("----%lld %lld %d-----\n", amin, dmin, count);
			if(count<=K)
			{
				if(a[i]-i*d < amin)
				{
					amin = a[i]-i*d;
					dmin = d;
				}
				else if(a[i]-i*d == amin && d < dmin)
					dmin = d;
			}
		}
	for(int i=0; i<n; i++)
	{
		printf("%lld ", amin);
		amin += dmin;
	}
	printf("\n");
	return 0;
}

