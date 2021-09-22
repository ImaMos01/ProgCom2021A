//ejercicio 1
#include <iostream>
#include <string>
#include <algorithm>

int main() {
  int cont=0, i=0;
  std::string palabra;
  getline(std::cin,palabra);

  std::string palabra2;
  getline(std::cin,palabra2);

  palabra.erase(std::remove(palabra.begin(), palabra.end(), ' '), palabra.end());
  palabra2.erase(std::remove(palabra2.begin(), palabra2.end(), ' '), palabra2.end());
  bool rep[palabra2.size()];
  for(int j=0; j<palabra.size();j++){
    i=0;
    while(i<palabra2.size()){
      if(palabra[j]==palabra2[i]){
        if(rep[i]==false){
          rep[i]=true;
          cont++;
          break;
        }
      }
      i++;
    }
  }
  if(cont==palabra.size()){std::cout<<"es un anagrama";}
  else std::cout<<"no es un anagrama";
 return 0;
}