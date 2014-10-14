#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int dp[3][3][3][3][3][3];

int ans(int a, int b, int c, int d, int e, int f)
{
	int x[] = {a, b, c, d, e, f};
	int y[6];
	if(dp[a][b][c][d][e][f] == -1)
	{
		int status = 0;
		for(int i=0; i<6; i++)
		{
			for(int start=0; start<=3; start++)
			{
				for(int j=0; j<6; j++)
					y[j] = x[(i+j)%6];
				for(int j=y[start]; j>-1; j--)
				{
					y[start] = j;
					for(int k=y[start+1]; k>-1; k--)
					{
						y[start+1] = k;
						for(int l=y[start+2]; l>-1; l--)
						{
							y[start+2] = l;
							if(j==x[(i+start)%6] && k==x[(i+1+start)%6] && l==x[(i+2+start)%6])
								continue;
							if(ans(y[0], y[1], y[2], y[3], y[4], y[5])==0)
							{
								status = 1;
								break;
							}
						}
						if(status)
							break;
					}
					if(status)
						break;
				}
				if(status)
					break;
			}
			if(status)
				break;
		}
		dp[a][b][c][d][e][f] = status;
	}
	return dp[a][b][c][d][e][f];
}

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	memset(dp, -1, sizeof(dp));
	
	dp[0][0][0][0][0][0] = 0;

	int a[6];
	for(int i=0; i<6; i++)
	{
		scanf("%d", a+i);
		if(a[i]>2)
			a[i] = 2;
	}
	int status = 0;
	status = ans(a[0], a[1], a[2], a[3], a[4], a[5]);
	if(status)
		printf("Winning\n");
	else
		printf("Losing\n");
	return 0;
}

