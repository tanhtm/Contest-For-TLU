#include <iostream>
#include <vector>
using namespace std;

int n,b,minn,maxx=0,idMax=0;
int tempMax;
vector<int> array;
void nhapDuLieu(){
	cin>>n>>b;
	maxx=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(i==0)
			minn= x;
		if(x< minn)
			minn=x;
		if(x>maxx){
			maxx= x;
			idMax=i;
		}
		array.push_back(x);
	}
}
void soSanhMax(int any){
	if(tempMax==-1)
		tempMax= any;
	else if(tempMax< any) tempMax= any;
}
int main()
{
	nhapDuLieu();
	//xuatDuLieu();
	int min,idMin;
	int doMax=-1;
	if(maxx-minn<b){
		cout<<doMax;
		return 0;
	}
	tempMax= array[0];
	
	/// duyet ve trai
	for(int i=2;i<idMax;i++){
		min= array[i];
		soSanhMax(array[i-1]);
		if(tempMax- b>= min){
			int x= tempMax+ maxx -2*min;
			if(x> doMax)
				doMax= x;
			//cout<<tempMax<<" "<<maxx<<" "<<min<<" "<<doMax<<endl;
		}
	}
	tempMax= array[n-1];
	for(int i=n-2;i>idMax;i--){
		min= array[i];
		soSanhMax(array[i+1]);
		if(tempMax- b>= min){
			int x= tempMax+ maxx -2*min;
			if(x> doMax)
				doMax= x;
			//cout<<tempMax<<" "<<maxx<<" "<<min<<" "<<doMax<<endl;
		}
	}
	cout<<doMax;
	return 0;
	/*
	10 5
	3 5 4 7 2 5 4 6 9 8
	*/
}