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
	int n, count = 0, start;
	char a[2010][2010];
	int con[2010][70] = {0};
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s", a[i]);
		for(int j=0; j<n; j++)
			if(a[i][j]=='1')
				con[i][j/30] |= (1<<(j%30));
	}
	start = n/30;
	for(int i=0; i<n; i++)
	{
//		cout<<con[i][0]<<endl;
		for(int j=i+1; j<n; j++)
			if(a[i][j]=='0')
				for(int k=start; k>-1; k--)
					if(con[i][k]&con[j][k])
					{
						count+=2;
						break;
					}
	}
	printf("%d\n", count);
	return 0;
}

