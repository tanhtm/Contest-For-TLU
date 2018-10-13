#include <iostream>
using namespace std;
long buaTiec(long n,long k){
	if(k<0)
 		return 0;
	if(k==0)
		return 1;
	if(n % 2 == 0)
	{
		if (k >= n/2)
			return n/2;
		if (k % 2 == 0)
			return k+1;
		return (k/2 + 1)*2;
	}
	else
	{
		if (k < n)
			return k+1;
		return n;
	}
}
int main()
{
	long n,k;
	cin>>n>>k;
	cout<<buaTiec(n,k)<<endl;
	return 0;
}