
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
		int n, m, k, num;
		cin>>n>>m>>k;
		int a[110] = {0}, b[110] = {0};
		for(int i=0; i<m; i++) { SI(num); a[num] = 1;}
		for(int i=0; i<k; i++) { SI(num); b[num] = 1;}
		int a1 = 0, a2 = 0;
		for(int i=1; i<=n; i++) { if(a[i]&&b[i]) a1++; else if((a[i]||b[i])==0) a2++;}
		cout<<a1<<" "<<a2<<endl;
	}
	return 0;
}
