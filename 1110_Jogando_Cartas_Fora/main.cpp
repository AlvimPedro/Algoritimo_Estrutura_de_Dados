#include <iostream>
using namespace std;

class doubleNode{
public:
  int data;
  doubleNode *previous, *next;//apontadores para anterios e proximo

  //construtores
  doubleNode(){
    previous = 0;
    next = 0;
  }
  doubleNode(int i, doubleNode *prev = 0, doubleNode *prox = 0){
    data = i;
    previous = prev;
    next = prox;
  }
};

class doubleList{
  private : doubleNode *head;
            doubleNode *tail;
public:
  //construtor
  doubleList(){
    head = 0;//topo da pilha de cartas
    tail = 0;//base da pilha de cartas
  }

  bool istwo(){
    int a = 0;//retorna 0 se não tiver 2 cartas
    if(head->next == tail){//se o proximo do head for tail só tem 2 termos
      a = 1;
    }
    return(head->next == tail);//retorna 1 quando só tem 2 termos
  }
  void addTail(int info){
    doubleNode *temp = new doubleNode(info, tail, 0);
    if (tail != 0) //se a lista nao esta vazia
    {
      tail->next = temp;
      tail = tail->next;
    }
    else
    {
      tail = temp;
      head = tail; //somente 1 elemento -> head e tail apontam para ele
    }
  }

  int deleteHead(){
    int infor = head->data;
    if(head == tail) //se só há um elemento na lista
    {
      delete head;
      head = tail = 0;
    }
    else{
      head = head->next; //comeco da lista passa para o proximo elemento
      delete head->previous; //apaga
      head->previous = 0; //novo comeco nao tem antecessor
  	}
    return infor;
  }

  void cartasfora(){ //parametro é a lista
    cout << "Discarded cards: ";
    while(istwo() != 1){ //enquanto tem mais de 2 cartas para acertar a formataçao do uri
      cout <<  deleteHead() << ", ";//deletando topo da pilha
        addTail(deleteHead());//colocando novo topo na base e deletando a carta que foi para a base
    }
    cout << deleteHead() << endl;
    cout << "Remaining card: "<< deleteHead() <<endl;//mostra o ultimo termo e apaga ele
  }
};

int main(){

  int n = 1;
  doubleList cartas;
  cin >> n;
  while(n != 0){// fazer o programa ate a pessoa digitar 0
    for(int i = 1; i <= n; i++){
      cartas.addTail(i);//adiciona as cartas na lista com o topo sendo o head e a base das cartas o tail
    }
    cartas.cartasfora();// funcao que mostra as cartas discartadas e a que sobrou e ja apaga a lista
    cin >> n;
  }
return 0;
}