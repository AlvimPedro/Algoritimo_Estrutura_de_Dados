#include<iostream>
#include<stack>
using namespace std;

int main(){

  int n;
  stack<char> trem;//pilhas dos vagaoes q saem
  stack<char> vagao;//pilha dos vagaoes que entram
  stack<char> suporte;
  int var = 1;
  cin >> n;
  int ca = 0;//formatação
  int sup = 0;
  char nvagao;
  trem.push('0');//nao deixar a pilha vazia para nao dar erro de tentar comparar um char com uma pilha vazia
  vagao.push('0');
  while (n != 0) {//enquanto o numero de vagoes diferente de 0

 //montagem da pilha de chegada
    for( int i = 0; i < n; i++){//colocar os vagoes em uma pilha de suporte para colocar em uma pilha na ordem certa
      cin >> nvagao;
      suporte.push(nvagao);
    }
    for(int i = 0; i< n; i++){//isso é para montar uma pilha onde o topo é o proximo vagao a entrar na estacao
      vagao.push(suporte.top());
      suporte.pop();
    }
//aqui começa a combinação
    trem.push(vagao.top());//o primeiro movimento sempre vai ser inserir o primerio vagao
	  vagao.pop();

    for(int k = 0; (k < n) && (var != 0); k++){// for para as acoes ou da erro na combina��o

      cin >> nvagao;

      if(ca==0){//só funciona pro primeiro vagao
        cout << "I";//insercao do primeiro vagao
      }
      ca = 1;

      if(nvagao == trem.top()){ //se o topo da pilha for o proximo vagao a sair
        trem.pop();
        cout <<"R";
      }
      else if(nvagao == vagao.top()){//se o proximo vagao a sair esta no topo do trem que chega
        trem.push(vagao.top());      //entao vai inserir e logo depois remover
        trem.pop();
        vagao.pop();
        cout<<"IR";
      }
      else {

        while(trem.top() != nvagao && vagao.top() != '0'){//vai inserindo vagao ate chegar no proximo vagao q tem q sair ou se der errado da impossible e sai do while
          cout << "I";
		        trem.push(vagao.top());//insere na estação
            vagao.pop();// e tira do trem q esta chegando
        }
        if((vagao.top() == '0') && (trem.top() != nvagao)){//se o trem q entra esta vazio e o vagao do topo da estacao q vai sair,
          cout << " Impossible"<<endl; //  mas se for diferente do que precisa sair, entao deu erro na combinação
          var = 0;//variavel para sair do for
          while(trem.top() != '0'){ //se ocorreu o erro resetar a pilha pro proximo caso
            trem.pop();
          }
        }
        else{
          cout << "R";//caso só precisa removero topo da pilha do trem para ir pro caminho b
          trem.pop();
        }
      }

      if(k == n-1){
        cout << endl;
      }
    }
    if(var == 0){//caso de impossible estava dando erro
      char c;
      while((c = getchar()) != '\n' && c != EOF);//limpar o buffer
    }
    cin >> n;

    var =1;//resetando variavel suporte
    ca = 0;//resetando
  }

return 0;
}