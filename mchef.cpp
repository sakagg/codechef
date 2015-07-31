
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

vector<int> start[100100];
vector<int> end[100100];

vector<LL> v[2];

LL ans(int a[], int cost[], int n, int k)
{
	int ind = 0;
	int oth = 1;
	for(int i=0; i<n; i++)
	{
		if(a[i] >= 0)
			continue;
		v[ind][0] = 0;
		for(int j=1; j<=k; j++)
			if(cost[i] <= j)
				v[ind][j] = max(v[oth][j], v[oth][j-cost[i]] - a[i]);
			else
				v[ind][j] = v[oth][j];
		ind = !ind;
		oth = !oth;
	}
	return v[oth][k];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k, m; SI(n); SI(k); SI(m);
		LL tot = 0;
		int a[n];
		int cost[n];
		for(int i=0; i<n; i++)
		{
			SI(a[i]);
			tot += a[i];
		}
		int l, r, c;
		for(int i=0; i<=n; i++)
		{
			start[i].clear();
			end[i].clear();
		}
		for(int i=0; i<m; i++)
		{
			SI(l); SI(r); SI(c);
			start[l-1].pb(c);
			end[r].pb(c);
		}
		multiset<int> ms;
		for(int i=0; i<=n; i++)
		{
			EACH(it, start[i])
				ms.insert(*it);
			EACH(it, end[i])
				ms.erase(ms.find(*it));
			cost[i] = ms.empty() ? INT_MAX : *ms.begin();
		}
		for(int i=0; i<2; i++)
			v[i] = vector<LL>(k+1, 0);
		LL diff = ans(a, cost, n, k);
		if(diff<0)
			diff = 0;
		cout<<tot + diff<<endl;
	}
	return 0;
}
