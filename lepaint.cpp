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
	int n, c, k, l ,r, ind, oth, col;
	long double a[2][60][100];
	long double ans;
	cin>>T;
	while(T--)
	{
		scanf("%d%d%d", &n, &c, &k);
		for(int i=1; i<=n; i++)
		{
			a[1][i][0] = 0;
			a[1][i][1] = 1;
			for(int j=2; j<c; j++)
				a[1][i][j] = 0;
		}
		for(int i=0; i<k; i++)
		{
			ind = i&1;
			oth = !ind;
			scanf("%d%d", &l, &r);
			for(int j=1; j<l; j++)
				for(int k=0; k<c; k++)
					a[ind][j][k] = a[oth][j][k];
			for(int j=l; j<=r; j++)			//Index of block under consideration
			{
				for(int k=0; k<c; k++)
					a[ind][j][k] = 0;
				for(int k=1; k<c; k++)		//Old Colour
				{
					a[ind][j][k] += a[oth][j][k]/2;
					for(int l=1; l<c; l++)	//New Paint
					{
						col = (k*l)%c;
						a[ind][j][col] += a[oth][j][k]/(2*c);
					}
				}
			}
			for(int j=r+1; j<=n; j++)
				for(int k=0; k<c; k++)
					a[ind][j][k] = a[oth][j][k];
/*			for(int j=1; j<=n; j++)
			{
				for(int k=0; k<c; k++)
					cout<<a[ind][j][k]<<" ";
				cout<<endl;
			}
*/		}
		ans = 0;
		for(int i=1; i<=n; i++)
			for(int j=0; j<c; j++)
				ans+=(j*a[ind][i][j]);
		printf("%.9Lf\n", ans);
	}	

	return 0;
}

