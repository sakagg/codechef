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

int main()
{
// Uncomment to use TestCases
	int T;
	int x, y, a, b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &x, &y);
		a = x;
		b = y;
		if(x>=0 && ((x&1) && (y<=(x+1)) && (y>=(1-x))))
			printf("YES\n");
		else if(x<=0 && ((a=-a)||1) && ((!(a&1)) && y<=a && y>=-a))
			printf("YES\n");
		else if(y>=0 && ((!(y&1)) && x<=(y-1) && x>=(-y)))
			printf("YES\n");
		else if(y<=0 && ((b=-b)||1) && (!(b&1)) && (x>=(-b)) && x<=(b+1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

