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
	int n, num, count;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		count = 0;
		int done[100100] = {0};
		while(n--)
		{
			scanf("%d", &num);
			if(!done[num])
			{
				done[num] = 1;
				count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}

