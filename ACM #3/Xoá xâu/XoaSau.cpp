#include <bits/stdc++.h>
using namespace std;
int n,r = 0;
string s;
int memo[1005][1005];
int dp(int l, int r){ // dp suoi 0 -> i
	if(l == r) return 1;
	if(l > r) return 0;
	if(memo[l][r] != -1) return memo[l][r];
	int x = 1000;
	if(s[l] == s[r]){
		x = min (x, 1+ dp(l+1,r-1));
		for(int i=l+1;i<r;i++)
			if(s[l] == s[i]) x = min(x,dp(l,i)+dp(i,r)-1);
	}else{
		x = min(x, 1 + dp(l+1,r));
		for(int i=l+1;i<r;i++){
			if(s[i] == s[l]) x = min(x,dp(l,i)+dp(i+1,r));
			if(s[i] == s[r]) x = min(x,dp(l,i-1)+dp(i,r));
		}
	}
	//cout<<l<<" "<<r<<" "<<x<<endl;
	return  memo[l][r] = x;
}
void pre(){ // tien xu ly
	string ss;
	for(int i=0;i<n;i++)
		if(i == 0) ss+= s[i];
		else if(s[i] != s[i-1]) ss+= s[i];
	s = ss;
	n = s.size();
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	memset(memo,-1,sizeof memo);
	cin>>n>>s;
	pre();
	cout<<dp(0,n-1)<<endl;
	//for(int i=0;i<n;i++) cout<<i;
	//cout<<endl;
	//cout<<s<<endl;
	return 0;
}