#include <bits/stdc++.h>
using namespace std;

//ordenados
void three_integers(vector<int>& nums,int k){
    int tam = nums.size()-1;
    int pos[3]={0,0,0};
    int mayor=0, temmayor=0,final=0, p=0;
    
    while(tam>=0 || final==k){
        if(nums[tam]<k){
            if(nums[tam]>mayor){
                mayor=nums[tam];
                pos[2]=tam;
                tam--;   
            }
            if(mayor+nums[tam]<k){
                temmayor=mayor+nums[tam];
                p=tam-1;
                for(int i=p;i>=0;i--){
                    if(temmayor+nums[i]==k){
                        pos[0]=i;
                        pos[1]=tam;
                    }
                }
            }
        }
        tam--;
    }
    
    std::cout<<"["<<pos[0]<<", "<<pos[1]<<", "<<pos[2]<<"] positions\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums {1,2,4,5,12};
    three_integers(nums,19);
    return 0;
}