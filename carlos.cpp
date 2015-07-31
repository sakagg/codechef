
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

class mset
{
	int par[210];
	int size[210];
	public:
	mset()
	{
		for(int i=0; i<205; i++)
		{
			par[i] = i;
			size[i] = 1;
		}
	}

	int getParent(int i)
	{
		if(par[i]!=i)
			par[i] = getParent(par[i]);
		return par[i];
	}

	void join(int i, int j)
	{
		int p1 = getParent(i);
		int p2 = getParent(j);
		if(size[p1] < size[p2])
			swap(p1, p2);
		par[p2] = p1;
		size[p1] += size[p2];
	}
};

const int INF = 1e9;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, k, n;
		cin>>m>>k>>n;
		int x, y;
		mset ms;
		for(int i=0; i<k; i++)
		{
			SI(x); SI(y);
			ms.join(x, y);
		}
		int ps[210][210];
		for(int i=1; i<=m; i++)
			for(int j=1; j<=m; j++)
				ps[i][j] = ms.getParent(i) == ms.getParent(j);
		int b[200100];
		for(int i=0; i<n; i++)
			SI(b[i]);
		int a[2][210];
		for(int i=1; i<=m; i++)
			a[0][i] = 0;
		for(int i=0; i<n; i++)
		{
			int ind = (i+1)%2;
			int oth = !ind;
			a[ind][0] = INF;
			for(int j=1; j<=m; j++)
				if(ps[b[i]][j] == 1)
					a[ind][j] = min(a[ind][j-1], a[oth][j] + (b[i]!=j));
				else
					a[ind][j] = a[ind][j-1];
		}
		int ind = n%2;
		if(a[ind][m] >= INF)
			printf("-1\n");
		else
			printf("%d\n", a[ind][m]);
	}
	return 0;
}
