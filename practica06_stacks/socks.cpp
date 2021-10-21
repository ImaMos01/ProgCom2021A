#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	stack<int> sock;
	int n=0,x=0;
	cin>>n;
	for(int i=0;i<n*2;i++){
		cin>>x;
		if(sock.empty()|| sock.top()!=x){
			sock.push(x);
		}
		else{
			sock.pop();
		}
	}
	if(sock.empty()){
		cout<<n*2<<"\n";
	}		
	else{
	cout<<"impossible";
	}

    return 0;
}