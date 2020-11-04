#include<iostream>
#include<stack>
using namespace std;

int main(){
  int var = 1; // variavel para ver se a combinação é possivel, 1 se sim e 0 de não
  int vagao = 1, n, cont = 0 ,conta = 0;
  int i = 1;
  int sup = 0;
  stack<int> trem;
  cin >> n;
  trem.push(0);
  while(n != 0){//se saiu do bloco e digitou 0 denovo foi para finalizar o programa


    while (vagao != 0) {//enquanto está do mesmo bloco
      for(int k = 0; k < n && vagao != 0; k++){//for para cada linha de combinação e se a pessoa digita o 0 para acabar o bloco
      cin >> vagao;
        if(trem.top() == vagao){ //se o topo da pilha for o proximo vagao a sair
            trem.pop();
        }
        else if(vagao > trem.top()){ // se o proximo vagao ainda não esta na pilha
          for(i; i <= vagao; i++){//enquanto o vagao q tem que sair entrar
            trem.push(i); //vai adicionanda na pilha até chegar o vagao a sair
          }
          trem.pop(); // tira o topo da pilha do vagao q saiu
        }
        else{ // se nao acontecer os outros quer dizer que a combinação da errado
          var  = 0;
        }
      }
		if(cont != 0){
			if(conta == 0){
				cout << endl;		//formata��o do uri
			}
		}
		conta = 1;

      if(vagao != 0 && sup != 0){
        cout << endl;
      }
      sup = 1;

      if(var == 1 && vagao != 0){//a combinação deu certo
        cout << "Yes";
      }
      if(var == 0 && vagao != 0){//a combinação deu algum erro
        cout << "No";
      }
      var = 1;//resetando variavel do erro;
      i = 1;//resetar a variavel i de apoio
      while(!trem.empty()){   // resetar a pilha caso de erro na variavel
        trem.pop();
      }
      trem.push(0);
    }
    conta = 0;

    cin >> n;
    if(n!=0){	// se nao finalizou o programa
    	vagao = 1; //para entrar no while das combina��es

	}
   cont  = 1;
  }

  cout << endl << endl;
  return 0;
}