#include<iostream>
using namespace std;
#define ln "\n"

int binpow(int b, int p){
	int ans = 1;
	while(p){
		if(p % 2) ans = (ans * b) % 10;
		b = (b * b) % 10;
		p /= 2;
	}
	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t, a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << binpow(a, b) << ln;
	}

	return 0;
}