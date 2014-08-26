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
/*	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n;
	int a[300100], max = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if((a[i]&a[j]) > max)
				max = a[i]&a[j];
	printf("%d\n", max);
	return 0;
}

