
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
		LL n, k;
		SLL(n); SLL(k);
		LL a[k];
		for(int i=0; i<k; i++)
			SLL(a[i]);
		sort(a, a+k);
		LL tot = 0;
		LL last = 0;
		int i;
		for(i=0; i<k; i++)
		{
			last += a[i];
			tot = (a[i]*(a[i]+1))/2 - last;
//			cout<<tot<<endl;
			if(tot < a[i])
				break;
		}
		if(i==k)
			tot = (n*(n+1))/2 - last;
//		cout<<tot<<endl;
		if(tot%2 == 0)
			printf("Chef\n");
		else
			printf("Mom\n");
	}
	return 0;
}
