#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

bool issolvable(int n, int m)
{
	if(n==3 && m==4)
		return true;
	if(((m*(m+1))/2 - (m/n + (m%n>0))) > (m*m)/2)
		return true;
	return false;
}
	
int done;

int spl[3][4] = {{0,2,9,10},{1,6,7,8},{3,4,5,11}};

void solve(int cards[1010][1010], int n, int m, vector<int> order)
{
	int start = 0;
	int num;
	if(n==3 && m==4)
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cards[order[(j+start)%n]][i] = done+spl[j][i];
	else
		for(int i=0; i<m; i++)
		{
			num = (i+1)*n+done;
			for(int j=0; j<n; j++)
				cards[order[(j+start)%n]][i] = --num;
			start += n-1;
			start%=n;
		}
	done += m*n;
}

int main()
{
// Uncomment to use TestCases
	int T;
	int n, m, count, start;
	int p[1010];
	int cards[1010][1010];
	bool solvable;
	vector<int> order;
	scanf("%d", &T);
	while(T--)
	{
		done = 1;
		solvable = true;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%d", p+i);
		int visited[1010] = {0};
		for(int i=0; i<n; i++)
			if(!visited[i])
			{
				order.resize(1);
				order[0] = i;
				count = 1;
				visited[i] = 1;
				start = p[i];
				while(start!=i)
				{
					order.push_back(start);
					visited[start] = 1;
					start = p[start];
					count++;
				}
				if(issolvable(count, m))
					solve(cards, count, m, order);
				else
				{
					solvable = false;
					printf("No Solution\n");
					break;
				}
			}
		if(solvable)
		{
			for(int i=0; i<n; i++)
			{
				printf("%d", cards[i][0]);
				for(int j=1; j<m; j++)
					printf(" %d", cards[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
