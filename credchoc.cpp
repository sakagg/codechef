#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int ispos[10100];
int a[10100];
int size;

int isSolvable(int num)
{
	if(ispos[num]==-1)
	{
		ispos[num] = 0;
		for(int i=0; i<size; i++)
			if(num-a[i] < 0)
				break;
			else
			{
				if(isSolvable(num-a[i]))
				{
					ispos[num] = 1;
					break;
				}
			}	
	}
	return ispos[num];
}

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
	int n, x, y;
	int done[10100] = {0};
	memset(ispos, -1, sizeof(ispos));
	ispos[0] = 1;
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	int i, j=0;
	for(i=0; i<n; i++)
	{
		scanf("%d", a+j);
		if(a[j]>10010 || done[a[j]])
			continue;
		done[a[j]] = 1;
		a[j]--;
		j++;
	}
	size = j;
	sort(a, a+j);
	if(isSolvable(y-x))
		printf("POSSIBLE\n");
	else
		printf("IMPOSSIBLE\n");
	return 0;
}

