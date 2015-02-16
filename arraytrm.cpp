
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
		int n, k;
		SI(n); SI(k);
		int a[n];
		for(int i=0; i<n; i++)
			SI(a[i]);
		vector<int> v;
		int done = 0;
		for(int i=0; i<n; i++)
		{
			v.clear();
			for(int j=0; j<n; j++)
				if(i!=j)
					v.pb(a[j]);
			int j;
			for(j=1; j<(int)v.size(); j++)
				if((v[j]-v[j-1])%(k+1) != 0)
					break;
			if(j==v.size())
			{
				done = 1;
				break;
			}
		}
		if(done)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
