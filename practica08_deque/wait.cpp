#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	deque<int> cost={4,-1,5,2,3};
    
    int Time=0;
	while(true){
	    if(cost.front()==-1 || cost.back()==-1){
	        break;
	    }
        else if(cost.front()< cost.back()){
            Time+=cost.front();
            cost.pop_front();
        }
        else{
            Time+=cost.back();
            cost.pop_back();
        }
	}
	
    cout<<Time;

    return 0;
}