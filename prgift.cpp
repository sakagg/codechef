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
	int n, k, count, num;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		count = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &num);
			if(!(num&1))
				count++;
		}
		if(count<k || (k==0 && n==count))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

