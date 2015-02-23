
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

double dist(double a, double b, double c, double d)
{
	return sqrt(pow(a-c, 2) + pow(b-d, 2));
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		double r, x, y, x0, y0, v;
		scanf("%lf%lf%lf%lf%lf%lf", &r, &x, &y, &x0, &y0, &v);
		double d = dist(x, y, x0, y0);
		if(d < r)
			printf("%.6lf\n", (r-d)/v);
		else
			printf("0.000000\n");
	}
	return 0;
}
