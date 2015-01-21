
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

typedef vector< VLL > V2d;
const int mod = 1e9 + 7;

V2d operator*(const V2d &a, const V2d &b)
{
	V2d ans = V2d(a.size(), VLL(a.size()));
	
	int r = a.size();
	for(int i=0; i<r; i++)
		for(int j=0; j<r; j++)
			for(int k=0; k<r; k++)
			{
				ans[i][j] += a[i][k]*b[k][j];
				ans[i][j] %= mod;
			}

	return ans;
}

void fastPow(V2d &a, int n)
{
	V2d ans(a.size(), VLL(a.size()));
	for(int i=0; i<(int)ans.size(); i++)
		ans[i][i] = 1;

	while(n)
	{
		if(n&1)
			ans = ans*a;
		a = a*a;
		n >>= 1;
	}

	a = ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		SI(n); SI(m);
		n--;

		V2d p1(m, VLL(m));
		for(int i=1; i<m; i++)
			p1[i][i-1] = p1[i-1][i] = 1;

		V2d p2(m, VLL(m));
		p2[0][0] = 1;
		for(int i=1; i<m; i++)
			p2[i][i-1] = p2[i][i] = p2[i-1][i] = 1;

		p2 = p2*p1;

		fastPow(p2, n/2);
		
		if(n%2 != 0)
			p2 = p1*p2;

		LL ans = 0;
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				ans = (ans + p2[i][j])%mod;

		printf("%lld\n", ans);
	}
	return 0;
}
