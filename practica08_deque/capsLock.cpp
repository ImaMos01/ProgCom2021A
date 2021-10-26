#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	queue<int> may;
	string message;
    
	for(int i=0;i<message.length();i++){
		if(message[i]=='@'){

		}
		else if(message[i]=='$'){

		}
		else{
			may.push(message[i]);
		}
	}
	

    return 0;
}