
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

LL memo[2000][330][10];

const LL mod = 1e9 + 7;

LL solve(int r, int b, int l)
{
	if(l < 0)
		return 0;
	if(r == 0 && b==0)
		return 1;
	if(r < 0 || b <= 0 || r > 6*b)
		return 0;
	if(memo[r][b][l] != -1)
		return memo[r][b][l];
	LL ans = 0;
	if(l > 0)
		ans += solve(r, b-1, l-1);
	ans += solve(r, b-1, l);
	ans += solve(r-4, b-1, l);
	ans += solve(r-6, b-1, l);
	ans %= mod;
	memo[r][b][l] = ans;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	memset(memo, -1, sizeof(memo));
	while(T--)
	{
		int r, b, l;
		SI(r); SI(b); SI(l);
		if(r > b*6)
		{
			printf("0\n");
			continue;
		}
		else
			printf("%lld\n", solve(r, b, l));
	}
	return 0;
}
