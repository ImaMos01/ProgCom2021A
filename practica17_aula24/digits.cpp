#include <bits/stdc++.h>
using namespace std;

const int limi=1000001;

int p=2;
int arr[limi];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;

    arr[0]=0;

    double digits = 0;
    for (int i=1; i<limi; i++){
        digits += log10(i);
        arr[i]=digits;
    }

    while(cin>>n){
        if(n==-20)break;
        cout<<arr[n]+1<<"\n";
    }
    return 0;
}