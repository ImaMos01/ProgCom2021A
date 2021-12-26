#include <bits/stdc++.h>

using namespace std;

long long int comp(long long int temp){
    if(temp%2==0){
        temp/=2;
    }
    else{
        temp = (temp*3)+1;
    }
    return temp;
}

void findcollatz(map<long long int,long long int>& numbers,long long int a){
    long long int cos=1, temp=a;
    numbers[temp]=cos;
    while(temp!=1){
        
        temp=comp(temp);
        cos++;
        numbers[temp]=cos;
    }
}

void meetcollatz(map<long long int,long long int>& sa,map<long long int,long long int>& sb,long long int b,long long int a){
    long long int cos=1,temp=b;
    bool ex=false;
    sb[temp]=cos;
    while(temp!=1){
        if(sa[temp]!=0){
            cout<<a<<" needs "<<sa[temp]-1<<" steps, "<<b<<" needs "<<sb[temp]-1<<" steps, they meet at "<<temp<<"\n";
            ex=true;
            break;
        }
        sa.erase(temp);
        temp=comp(temp);
        cos++;
        sb[temp]=cos;
    }
    if(ex==false){
        cout<<a<<" needs "<<sa[1]-1<<" steps, "<<b<<" needs "<<sb[1]-1<<" steps, they meet at "<<1<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a=0,b=0;
    while(cin>>a>>b){
        if(a==b && b==0) break;
        map<long long int,long long int> sa;
        map<long long int,long long int> sb;
        findcollatz(sa,a);
        meetcollatz(sa,sb,b,a);
    }
    return 0;
}