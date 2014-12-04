#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
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

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	char s[20];
	while(scanf("%s", s) && strcmp(s, "TheEnd"))
	{
		printf("%s\n", s);
		int a[220][110];
		int n, m;
		SI(n); SI(m);
		char names[n][20];
		for(int i=0; i<n; i++)
		{
			scanf("%s", names[i]);
			for(int j=0; j<m; j++)
				SI(a[j][i]);
		}
		LL dp[220][110];
		int prs[220][110];
		for(int i=0; i<n; i++)
			dp[0][i] = a[0][i];
		for(int i=1; i<m; i++)
		{
			LL mn = INT_MAX;
			int par = -1;
			for(int j=0; j<n; j++)
				if(dp[i-1][j] - (a[i][j]-100) < mn)
				{
					mn = dp[i-1][j] - (a[i][j]-100);
					par = j;
				}
			for(int j=0; j<n; j++)
			{
				dp[i][j] = dp[i-1][j];
				prs[i][j] = j;
				if(mn + a[i][j] < dp[i][j])
				{
					dp[i][j] = mn + a[i][j];
					prs[i][j] = par;
				}
			}
		}
		int mncost=0;
		for(int i=1; i<n; i++)
			if(dp[m-1][i] < dp[m-1][mncost])
				mncost = i;
		int order[m];
		order[m-1] = mncost;
		printf("Tk %lld\n", dp[m-1][mncost]);
		for(int i=m-1; i>0; i--)
		{
			mncost = prs[i][mncost];
			order[i-1] = mncost;
		}
		int count = 1;
		for(int i=1; i<m; i++)
		{
			if(order[i] == order[i-1])
				count++;
			else
			{
				printf("%s for %d month(s)\n", names[order[i-1]], count);
				count = 1;
			}
		}
		printf("%s for %d month(s)\n\n", names[order[m-1]], count);
	}
	printf("TheEnd\n");
	return 0;
}

