
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

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n; SI(n);
		vector< pair<ULL, int> > lst;
		for(int i=0; i<n; i++)
		{
			int m; SI(m);
			LL area = 0;
			LL a[2][m];
			for(int j=0; j<m; j++)
			{
				SLL(a[0][j]);
				SLL(a[1][j]);
				if(j!=0)
					area += a[0][j-1]*a[1][j] - a[0][j]*a[1][j-1];
			}
			area += a[0][m-1]*a[1][0] - a[0][0]*a[1][m-1];
			lst.pb(mp(abs(area), i));
		}
		sort(lst.begin(), lst.end());
		int ind[n];
		for(int i=0; i<n; i++)
			ind[lst[i].s] = i;
		print_array(ind, n);
	}
	return 0;
}
