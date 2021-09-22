#include <iostream>
#include <vector>

class nodo{
  int valor;
  nodo* siguiente;
  public:
    nodo(int val){
      valor=val;
      siguiente = NULL;
    }
  friend class lista;
};

class lista{
  int tam=0;
  nodo* head;
  public:
    void insertar(int a){ 
      nodo* nuevo = new nodo(a); //nuevo valor a insertar
      if(head == NULL){
        head = nuevo; 
      }
      else{
        nuevo->siguiente = head;
        head = nuevo;
      }
      tam++; 
    }
    void eliminar(int a){
        if(head==NULL);
        else{
            nodo* aux = head; //para recorrer la lista
            nodo* aux2 = NULL;
            while(aux != NULL){
                if(aux->valor==a)
    				break;
    			else{
    				aux2=aux;
    				aux=aux->siguiente;
    			}
            }
            if(aux == NULL);
            else{
                if(head==aux)head=head->siguiente;
                else aux2->siguiente = aux->siguiente;
                delete aux;
                tam--;
            }
        }
    }
    
    //eliminar los elementos duplicados en la lista
    void duplicados(){
        std::vector<int> dupl;
        bool d=false;
        nodo* aux = head; 
        nodo* aux2 = NULL;
        while(aux!=NULL){
            if(dupl.empty()) dupl.push_back(aux->valor);
            else{
                d=false;
                for(int i : dupl){
                    if(i == aux->valor){
                        d=true;
                        eliminar(aux->valor);
                    }
                }
                if(d==false){
                    dupl.push_back(aux->valor);
                }
            }
            aux2 = aux;
            aux = aux->siguiente;
        }
        nodo* au = head; //para recorrer la lista
        nodo* au2 = NULL;
        while(au!=NULL){
            std::cout<<au->valor<<" ";
            au2 = au;
            au = au->siguiente;
        }
    }
};

int main(){
	/* 
	caso 1
	entrada: 20,10,5,50,5,10
	salida: 50, 5, 10, 20	
	*/
	lista c1;
	std::vector<int> caso1{20,10,5,50,5,10};
	for(int i:caso1){
		c1.insertar(i);
	}
	c1.duplicados();
	/* 
	caso 2
	entrada: 8,25,11,8,8,3,6,7,3
	salida: 8	
	*/
	lista c2;
	std::vector<int> caso2{8,25,11,8,8,3,6,7,3};
	for(int i:caso2){
		c2.insertar(i);
	}
	c2.duplicados();
  return 0;
}