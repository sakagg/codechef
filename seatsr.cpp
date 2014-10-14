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
#define INF 1000

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
	int T;
	char s[100100], w[100100];
	LL dp[2][100100];
	int a, b, k;
	int ind, oth;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s %s", s, w);
		scanf("%d%d%d", &a, &b, &k);
		int slen = strlen(s);
		int wlen = strlen(w);
		LL ans = abs(slen-wlen)*a;
		if(ans > k)
		{
			printf("-1\n");
			continue;
		}
		if(b==0 || a==0)
		{
			printf("%lld\n", ans);
			continue;
		}
//		int mn = min(a, b);
		for(int i=0; i<=wlen; i++)
			dp[0][i] = a*i;
//		print_array(dp[0], wlen+1);
		for(int i=1; i<=slen; i++)
		{
			ind = i%2;
			oth = !ind;
			dp[ind][0] = a*i;
			if(i > k)
				dp[ind][i-k - 1] = INF;
			int j;
			for(j=max(1, i-k); j<=min((i+k), wlen); j++)
//			for(j=1; j<=wlen; j++)
				dp[ind][j] = min(dp[oth][j-1] + b*(s[i-1]!=w[j-1]), a + min(dp[ind][j-1], dp[oth][j]));
			if(j<=wlen)
				dp[ind][j] = INF;
//			print_array(dp[ind], wlen+1);
		}
		ans = dp[slen%2][wlen];
		if(ans > k)
			ans = -1;
		printf("%lld\n", ans);
	}
	return 0;
}

