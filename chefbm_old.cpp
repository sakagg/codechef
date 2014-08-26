#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

void print_array(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int n, m, p, size, tmp;
	cin>>n>>m>>p;
	vector<int> a[n];
	int i, j;
	while(p--)
	{
		cin>>i>>j;
		a[i-1].push_back(j-1);
	}
	for(i=0; i<n; i++)
	{
		tmp = 0;
		size = a[i].size();
		int arr[100000]={0};
//		for(j=0; j<m; j++)
//			arr[j] = j+1;
		for(j=0; j<size; j++)
			arr[a[i][j]]++;
//		print_array(arr, m);
		tmp = arr[m-1] - arr[0]+m-1;
		for(j=m-1; j>0; j--)
			if(arr[j-1]-arr[j] > 1)
			{
				tmp = -1;
				break;
			}
		cout<<tmp<<endl;
	}
	return 0;
}
