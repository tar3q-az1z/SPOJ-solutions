#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int val;
	while(true){
		cin>>val;
		if(val==42){
			cout<<42<<"\n";
			fflush(stdout);
			break;
		}
		cout<<val<<"\n";
		fflush(stdout);
	}
	return 0;
}
