
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

LL facts[10000100];

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, m;
	SI(n); SI(m);
	facts[0] = 1;
	for(int i=1; i<m; i++)
		facts[i] = (facts[i-1]*i)%m;
	for(int i=0; i<m; i++)
		facts[i] = (i*facts[i])%m;
	for(int i=1; i<m; i++)
		facts[i] = (facts[i-1]+facts[i])%m;
	LL p;
	LL ans = 0;
	for(int i=0; i<n; i++)
	{
		SLL(p);
		ans = (ans + facts[min(p, (LL)m-1)])%m;
		LL tmp;
		if(p%2==0)
			tmp = (((p/2)%m) * ((p+1)%m))%m;
		else
			tmp = ((p%m)*(((p+1)/2)%m))%m;
		ans = (ans + (p%m)*tmp)%m;
	}
	cout<<ans<<endl;	
	return 0;
}
