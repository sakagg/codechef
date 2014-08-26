#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n, num, localc=0, count=0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &num);
		if(num == 0)
		{
			if(localc > count)
				count = localc;
			localc = 0;
		}
		else
			localc++;
	}
	if(localc > count)
		count = localc;
	printf("%d\n", count);
	return 0;
}
