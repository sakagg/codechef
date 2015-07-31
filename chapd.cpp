
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
#define gcd __gcd

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int check(LL a, LL b)
{
	if(b==1)
		return 1;
	if(a==1)
		return 0;
	LL tmp = gcd(a, b);
	return check(tmp, b/tmp);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL a, b;
		SLL(a); SLL(b);
		if(check(a, b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
