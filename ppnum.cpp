#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 1000000007

using namespace std;

int digs(int num)
{
	int count;
	for(count=0; num>0; num/=10, count++);
	return count;
}

long long addmod(long long a, long long b)
{
	return ((a+b)%mod);
}

int main()
{
	int t, ldig, rdig;
	long long total, l, r, tmp;
	int min[10];
	min[0] = 1;
	for(int i=1; i<10; i++)
		min[i] = min[i-1]*10;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &l, &r);
		total = 0;
		ldig = digs(l);
		rdig = digs(r);
		if(ldig == rdig)
			total = ldig*((r-l+1)*(r+l))/2;
		else
		{
			total = ldig*((r-l+1)*(r+l))/2;
			for(int i=ldig+1; i<=rdig; i++)
			{
				tmp = (r - min[i-1] + 1)*(r+min[i-1]);
				total = addmod(total, tmp/2);
			}
		}
		printf("%lld\n", total%mod);
	}
	return 0;
}
