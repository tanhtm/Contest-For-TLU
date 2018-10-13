#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
struct KhacHang{
	int viTri;
	long kienHang;
};
bool compare(const KhacHang &a, const KhacHang &b){
	return a.viTri< b.viTri;
}
int n;
long long k;
long long timee=0;
vector< KhacHang > listKhacHang;
int vt;
void nhapDuLieu(){
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		KhacHang kh;
		kh.viTri= x;
		kh.kienHang= y;
		listKhacHang.push_back(kh);
	}
	sort(listKhacHang.begin(),listKhacHang.end(),compare);
	for(int i=0;i<n;i++){
		if(listKhacHang[i].viTri> 0){
			vt= i;
			break;
		}
	}
}
void XuatDuLieu(){
	for(int i=0;i<n;i++){
		cout<< listKhacHang[i].viTri<<endl;
	}
}
void xuLy(){
	// Xu li ben trai
	for(int i=0;i< vt;i++){
		long long x= listKhacHang[i].kienHang;
		if(x% k!= 0){
			long long thieu= k- x%k;
			for(int j=i+1; j< vt ; j++){
				//cout<<thieu<<endl;
				if(thieu==0)
					break;
				if(thieu<= listKhacHang[j].kienHang){
					listKhacHang[j].kienHang-= thieu;
					listKhacHang[i].kienHang+= thieu;
					thieu= 0;
					break;
				}else{
					thieu-= listKhacHang[j].kienHang;
					listKhacHang[i].kienHang+= listKhacHang[j].kienHang;
					listKhacHang[j].kienHang=0;
				}
			}
		}
		if(listKhacHang[i].kienHang%k==0)
			timee+= listKhacHang[i].kienHang/k*abs(listKhacHang[i].viTri)*2;
		else
			timee+= (listKhacHang[i].kienHang/k+1)*abs(listKhacHang[i].viTri)*2;
	}
	/// Xu li ben phai
	for(int i=n-1;i>= vt;i--){
		long long x= listKhacHang[i].kienHang;
		if(x% k!= 0){
			long long thieu= k- x%k;
			for(int j=i-1; j>= vt ; j--){
				//cout<<thieu<<endl;
				if(thieu==0)
					break;
				if(thieu<= listKhacHang[j].kienHang){
					listKhacHang[j].kienHang-= thieu;
					listKhacHang[i].kienHang+= thieu;
					thieu= 0;
					break;
				}else{
					thieu-= listKhacHang[j].kienHang;
					listKhacHang[i].kienHang+= listKhacHang[j].kienHang;
					listKhacHang[j].kienHang=0;
				}
			}
		}
		if(listKhacHang[i].kienHang%k==0)
			timee+= listKhacHang[i].kienHang/k*abs(listKhacHang[i].viTri)*2;
		else
			timee+= (listKhacHang[i].kienHang/k+1)*abs(listKhacHang[i].viTri)*2;
	}
}
int main(){
	nhapDuLieu();
	//XuatDuLieu();
	xuLy();
	cout<<timee;
	return 0;
}