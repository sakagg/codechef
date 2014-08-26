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
	char a[1000100], b[1000100], c[1000100];
	char *start;
	int n;
	scanf("%d", &n);
	scanf("%s %s", a, b);
	strcpy(c, b);
	strcat(c, b);
//	printf("%s\n", b);
	bool done = false;
	for(int i=n-1; i>-1; i--)
	{
		start = strstr(c, a);
//		printf("%s %d\n", a, start);
		if(start!=NULL)
		{
			printf("%ld\n", start-c);
			done = true;
			break;
		}
		a[i] = 0;
	}
	if(!done)
		printf("0\n");
	return 0;
}

