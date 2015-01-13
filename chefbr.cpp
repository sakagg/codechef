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
#define mod 1000000007

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

int a[110];
vector< vector<LL> > memo(110, vector<LL>(110, -1));

LL getans(int start, int end)
{
	if(end <= start)
		return 1;
	if(memo[start][end] != -1)
		return memo[start][end];
	LL ans = getans(start+1, end);
	if(a[start] < 0)
		for(int i=start+1; i<=end; i++)
			if(a[i] == -a[start])
			{
				ans += (getans(start+1, i-1)*getans(i+1, end))%mod;
				ans %= mod;
			}
	memo[start][end] = ans;
//	printf("%d %d %lld\n", start, end, ans);
	return ans;
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
	int n;
	SI(n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	printf("%lld\n", getans(0, n-1));
//	for(int i=0; i<n; i++)
//		print_array_v(memo[i]);
	return 0;
}

