#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define x first
#define y second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

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
	scanf("%d", &n);
	vector< pair<double, double> > p(n);
	pair<double, double> cp, hd, p1, p2;		//Center Point, Half Diagonal, Point1, Point2
	for(int i=0; i<n; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);
	sortv(p);
	int ans = 2;
	if(n==0)
		ans = 4;
	else if(n==1)
		ans = 3;
	else
	{
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				cp.x = (p[i].x + p[j].x)/2;    cp.y = (p[i].y + p[j].y)/2;
				hd.x = (p[i].x - p[j].x)/2;    hd.y = (p[i].y - p[j].y)/2;
				p1.x = cp.x - hd.y;            p1.y = cp.y + hd.x;
				p2.x = cp.x + hd.y;            p2.y = cp.y - hd.x;
				
				ans = min(ans, 2 - binary_search(p.begin(), p.end(), p1) - binary_search(p.begin(), p.end(), p2));
				if(ans == 0)
					break;
			}
			if(ans == 0)
				break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

