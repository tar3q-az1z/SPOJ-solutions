// Author : Mars_Coder


#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define PI          3.141592653589793238462643383279502884L
#define ln          "\n" // no flush, oppos of endl
#define _flush      endl
#define stop_sync   ios::sync_with_stdio(false) // not to use c-stye io
#define untie_ios   cin.tie(nullptr) // no flush
#define sz(x)       ((x).size())
#define pb          push_back
#define ppb 	    pop_back
#define lli         long long int
#define FIXED(x)    cout << fixed << setprecision(x)

vector<lli> a;
lli n {0}, c {0};
lli ans (0); // fed up by this global variable with -1 init.
bool max_dis(lli diff){
	lli cow = 1, temp_min = 1e15;
	for(int i = 0, j = i + 1; j < n; ){
		lli d = a[j] - a[i];
		if(d >= diff){
			++cow;
			temp_min = min(temp_min, d);
			if(cow == c){
				ans = max(ans, temp_min);
				return true;
			}
			i = j;
			++j;
		}else{
			++j;
		}
	}
	return false;
}
int main(void){
	
	int t (0);
	cin >> t;
	while(t--){
		cin >> n >> c;
		a.resize(n);
		ans = -1;
		for(auto i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		lli l = 1, r = a[n - 1], mid;
		while(l <= r){
			mid = r - (r - l) / 2;
			if(max_dis(mid)){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		cout << ans << ln;
	}
	
	return 0;
}

