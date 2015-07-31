
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

const int mod = 1e9;
LL C[4010][2010];
LL ans[2005][2005];

LL calc(int n, int m, int M)
{
	if(m==0)
		return 1;
	if(n==0)
		return 0;
	if(ans[n][m]!=-1)
		return ans[n][m];
	LL tot = 0;
	for(int i=0; i<=m; i++)
		tot = (tot + calc(n-1, i, M))%mod;
	tot = (tot*C[M+m-1][m])%mod;
	return ans[n][m] = tot;
}

int main()
{
	for(int i=0; i<4010; i++)
		C[i][0] = 1;
	for(int i=0; i<2010; i++)
		C[i][i] = 1;
	for(int i=2; i<4010; i++)
		for(int j=1; j<=i/2; j++)
		{
			C[i][j] =  (C[i-1][j] + C[i-1][j-1])%mod;
			if(i-j < 2010)
				C[i][i-j] = C[i][j];
		}

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m; SI(n); SI(m);
		for(int i=1; i<m; i++)
			ans[0][i] = 0;
		ans[0][0] = 1;
		for(int i=0; i<n; i++)
		{
			LL tot = 0;
			for(int j=0; j<=m; j++)
			{
				tot = (tot + ans[i][j])%mod;
				ans[i+1][j] = (tot*C[m+j-1][j])%mod;
			}
		}
		LL sum = 0;
		for(int i=0; i<=m; i++)
			sum = (sum + ans[n][i])%mod;
		cout<<sum<<endl;
	}
	return 0;
}
