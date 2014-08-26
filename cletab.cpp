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

void printarray(int a[], int sz)
{
	for(int i=0; i<sz; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
	
int main()
{
// Uncomment to use TestCases
	int T;
	int n, m, ind, ans;
	int a[440], t[220];
	int e[440], count[440];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		memset(e, -1, sizeof(int)*440);
		memset(t, 0, sizeof(int)*220);
		memset(count, 0, sizeof(int)*440);
		ans = 0;
		for(int i=1; i<=m; i++)
		{
			scanf("%d", a+i);
			count[a[i]]++;
		}
		for(int i=1; i<=m; i++)
		{
			ind = a[i];
			count[ind]--;
			if(e[ind]==-1)
			{
				ans++;
				int j;
				for(j=0; j<n; j++)
					if(count[t[j]] == 0)
					{
						e[t[j]] = -1;
						t[j] = ind;
						e[ind] = j;
//						cout<<"Change from 1: ";
						break;
					}
				if(j==n)
				{
					int k;
					int found[440] = {0};
					for(j=i+1; j<=m; j++)
						if(e[a[j]]!=-1 && !found[a[j]])
						{
							k = j;
							found[a[j]] = 1;
						}
					e[ind] = e[a[k]];
					t[e[a[k]]] = ind;
					e[a[k]] = -1;
//					cout<<"Change from 2: ";
				}
			}
//			printarray(t, n);
		}
		printf("%d\n", ans);
	}
	return 0;
}
