#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	long long x, y, moves;
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld", &x, &y);
		if(x<0)
			x = -x;
		if(y<0)
			y = -y;
		if(x==y)
			moves = 2*x;
		else if(x<y)
		{
			moves = 2*x;
			y -= x;
			moves += 4*(y/2) + (y&1);
		}
		else
		{
			moves = 2*y;
			x -= y;
			moves += 4*(x/2) + 3*(x&1);
		}
		printf("%lld\n", moves);
	}
	return 0;
}
