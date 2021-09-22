#include <iostream>

int main(){
    int* arr;
    int n=0, i=0, max1=0, max2=0;
    std::cin>>n;
    arr = new int[n];
    while(i<n){
        std::cin>>arr[i];
        if(arr[i]<0){
            std::cout<<"error\n"; break;
        }
        i++;
    }

    for(int i=0; i<n; i++){
        if(arr[i]>=max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>=max2){
            max2 = arr[i];
        }
    }
    
    std::cout<<max1*max2<<"\n";
    delete[] arr;
    return 0;
}