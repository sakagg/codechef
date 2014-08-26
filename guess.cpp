#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int t, n, m;
	long long num, den;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		if(n&1 && m&1)
		{
			num = n;
			num*=m;
			den = num;
			num=(num-1)>>1;
			printf("%lld/%lld\n",num, den); 
		}
		else
			printf("1/2\n");
	}
	return 0;
}
