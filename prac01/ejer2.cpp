#include <iostream>
#include <vector>

int main(){
    int j = 0, k=0,ac=0;
    bool opc=false;
    std::vector<int> secuencia;
    std::vector<int> bucle1;
    std::vector<int> bucle2;
    while(true){ //escribir un numero negativo para salir del bucle
        std::cin>>j;
        if(j <= -1) break;
        secuencia.push_back(j);
    }

    std::vector<int> contador(secuencia.size(),-1);
    for(int i=0;i<(secuencia.size());i++ ){
        contador[secuencia[i]-1]++;
    }

    for(int i=0; i<contador.size(); i++){
        opc=false;
        k=0;
        if(contador[i]>=1){
            while(k<secuencia.size()){
                if((i+1)==secuencia[k]){
                    ac=secuencia[k];
                    opc=true;
                    break;
                }
                k++;
            }
        }
        if(opc==true){
            bucle1.push_back(ac);
        }
        else{
            if(bucle1.size()>=bucle2.size()){
                bucle2=bucle1;
            }
            bucle1.clear();
        }
    }

    return 0;
}