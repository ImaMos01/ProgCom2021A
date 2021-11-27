#include <bits/stdc++.h>

using namespace std;

int main(){
    int t=0,cont=0;
    string content;
    cin>>t;
    cin.ignore();
    for(int i=0; i<t;i++){
        cont=0;
        getline(cin,content);
        
        stack<char> disp;
        map<char,int> repet;

        repet[content[0]]=1;
        disp.push(content[0]);
        cont+=2;
        
        for(int j=1; j<content.length();j++){
            if(repet[content[j]]==1){
                while(disp.top() != content[j]){
                    repet.erase(disp.top());
                    disp.pop();
                    cont++;
                }
                cont++;
            }
            else{
                disp.push(content[j]);
                repet[content[j]]=1;
                cont+=2;
            }
        }
        while(!disp.empty()){
            disp.pop();
            cont++;
        }
        
        cout<<cont<<"\n";
        cin.clear();
    }
    return 0;
}