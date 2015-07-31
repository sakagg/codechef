
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
		int n;
		SI(n);
		int a[100100];
		for(int i=0; i<n; i++)
			SI(a[i]);
		int done[100100] = {0};
		int cnt = 0;
		for(int i=1; i<n; i++)
			if(a[i] != a[i-1])
			{
				done[i] = 1;
				cnt++;
				if(!done[i-1])
					cnt++;
			}
		printf("%d\n", cnt);
	}
	return 0;
}
