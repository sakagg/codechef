
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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n;
	SI(n);
	vector<int> a(n);
	for(int i=0; i<n; i++)
		SI(a[i]);
	vector<int> b(a);
	LL cost = 0, cost2 = 0;
	for(int i=1; i<n; i++)
	{
		if(a[i] < a[i-1])
		{
			int ele = a[i];
			cost += a[i];
			int j;
			for(j = i; j>0 && ele<a[j-1]; j--)
				a[j] = a[j-1];
			a[j] = ele;
		}
	}
	for(int i=n-2; i>=0; i--)
	{
		if(b[i] > b[i+1])
		{
			int ele = b[i];
			cost2 += b[i];
			int j;
			for(j = i; j<n-1 && ele>b[j+1]; j++)
				b[j] = b[j+1];
			b[j] = ele;
		}
	}
//	print_array_v(a);
//	print_array_v(b);
	printf("%lld\n", min(cost, cost2));
	return 0;
}
