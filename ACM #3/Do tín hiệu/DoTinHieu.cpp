#include <iostream>
using namespace std;
const int MAXN = 200002;
int n,b;
int a[MAXN], L[MAXN], R[MAXN];
/*
L[i]:= max(a[1]...a[i]);
R[i]:= max(a[i]...a[n]);
*/
int main()
{
	// Input
	cin>>n>>b;
	for(int i= 1; i<= n; i++) cin>>a[i];
	// L[i]
	L[1] = a[1]; // base
	for(int i= 2; i<= n; i++){
		L[i] = a[i];
		L[i] = max(L[i],L[i-1]);
	}
	// R[i]
	R[n] = a[n];
	for(int i= n-1;i>= 1; i--){
		R[i] = a[i];
		R[i] = max(R[i],R[i+1]);
	}
	// solve
	int res = -1; 
	for(int i= 2;i<= n-1; i++){
		// cut at i
		int l = L[i-1] - a[i];
		int r = R[i-1] - a[i];
		if(l < b || r < b) continue;
		res = max(res,l+ r);
	}
	cout<<res<<endl;
	return 0;
}