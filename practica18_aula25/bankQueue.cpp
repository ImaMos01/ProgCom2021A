#include <bits/stdc++.h>
using namespace std;

int n=0,t=0,sum=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c=0,p=0;
    vector<pair<int,int>> people;    
    cin>>n>>t;
    vector<bool> place(t,false);
    for(int i=0; i<n;i++){
        cin>>c>>p;
        people.push_back(make_pair(c,p));
    }

    sort(people.begin(),people.end());

    for(int i=people.size()-1; i>=0;i--){
        for(int j=people[i].second; j>=0;j--){
            if(place[j]==false){
                place[j]=true;
                sum+=people[i].first;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}

