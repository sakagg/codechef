
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanint(x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define max(a, b) ((a)>=(b)?(a):(b))

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int a[17][131072];	//17x2^17
int lgs[131072];
int pws[20];

#define gc getchar_unlocked

inline void scanint(int &x)
{
    int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
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
	for(int i=1; i<100100; i++)
		lgs[i] = log2(i);
	for(int i=0; i<20; i++)
		pws[i] = 1<<i;
	int n;
	SI(n);
	for(int i=0; i<n; i++)
		SI(a[0][i]);
	for(int i=1; pws[i]<=n; i++)
		for(int j=0; j+pws[i]<=n; j++)
			a[i][j] = max(a[i-1][j], a[i-1][j+pws[i-1]]);
	LL ans = 0;
	int lg;
	int m, x, y;
	SI(m); SI(x); SI(y);
	int N = n-1;
	for(int i=0; i<m; i++)
	{
		if(x <= y)
		{
			lg = lgs[y-x+1];
			ans += max(a[lg][x], a[lg][y-pws[lg]+1]);
		}
		else
		{
			lg = lgs[x-y+1];
			ans += max(a[lg][y], a[lg][x-pws[lg]+1]);
		}
		x += 7;
		while(x >= N) x-=N;
		y += 11;
		while(y >= n) y-=n;
	}
	printf("%lld\n", ans);
	return 0;
}
