#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	queue<char> may;
	string message="abc$d@ef$@g$";
	string final="";
	bool opc=false;
    
	for(int i=0;i<message.length();i++){
		if(message[i]=='@'){
			if(opc==false){
				opc=true;
			}
			else{ opc=false;}
		}
		else if(message[i]=='$'){
			while(!may.empty()){
				if(opc==true){
					final+=toupper(may.front());
				}
				else{ final+=tolower(may.front());}
				may.pop();
			}
		}
		else{
			may.push(message[i]);
		}
	}
	cout<<final;

    return 0;
}