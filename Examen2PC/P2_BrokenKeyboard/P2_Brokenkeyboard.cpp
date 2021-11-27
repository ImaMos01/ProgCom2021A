#include <bits/stdc++.h>

using namespace std;


int main(){
    int maxSt=0,m=0,cs=0,ce=0,acsize=0,keys=0,cont=0;
    char line[1000001];
    while(true){
        cin>>m;
        if(m==0)break;
        maxSt=0;
    
        getchar();
        
        if(fgets(line, 1000001, stdin)!=NULL){
            vector<int> keyboard(128,0);
            cs=0;ce=m-1;acsize=strlen(line);keys=0;cont=0;

            for(int i=0; i<m;i++){
                if(keyboard[line[i]]==0){
                    keys++;
                }
                keyboard[line[i]]++;
            }

            while(ce<acsize-2){
                while(keys<=m && (ce<acsize-2)){
                    ce++;
                    if(keyboard[line[ce]]==0){
                        keys++;
                    }
                    keyboard[line[ce]]++;
                }
                if(keys>m){
                    cs++;
                }
                if((ce-cs+1)>maxSt){
                    maxSt = ce-cs+1;
                }
                if(keyboard[line[cs-1]]>0){
                    keyboard[line[cs-1]]--;
                    cont=keyboard[line[cs-1]];
                    if(cont==0){
                        keys--;
                    } 
                }
            }
        }
        cout<<maxSt<<"\n";
    }

    return 0;
}
