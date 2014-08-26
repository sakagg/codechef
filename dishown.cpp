#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int owner[10010];

int getOwner(int ind)
{
	int owr = owner[ind];
	if(owr != owner[owr])
		owner[ind] = getOwner(owr);
	return owner[ind];
}

int main()
{
	int T;
	int n, q, ch, x, y, first, last;
	int score[10010];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d", score+i);
			owner[i] = i;
		}
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &ch, &x);
			if(ch==1)
				printf("%d\n", getOwner(x));
			else if(ch==0)
			{
				scanf("%d", &y);
				x = getOwner(x);
				y = getOwner(y);
				if(x==y)
					printf("Invalid query!\n");
				if(score[x] == score[y])
					continue;
				if(score[x] < score[y])
					x = x + y - (y=x);
				owner[y] = x;
			}
		}
	}
	return 0;
}

