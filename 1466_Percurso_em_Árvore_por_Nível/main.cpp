#include<iostream>
#include<queue>

using namespace std;

class BSTNode{
public:
  //CONSTRUTORES
  BSTNode() {
      left = right = 0;
  }
  BSTNode(const int& el, BSTNode *left = 0, BSTNode *right = 0) {
      this->el = el;
      this->left = left;
      this->right = right;
  }
  //ATRIBUTOS
  int el; //elemento a se armazenar
  BSTNode *left, *right; //apontadores para subarvore esquerda e direita
};

class arvore{
public:
  arvore(){
    root = 0;
  }
  void inserir(const int& el){
    BSTNode *p, *prev;
    p = this->root;//começar a busca de onde inserir a partir da raiz
    while(p != 0){ //enquanto não chegou em uma folha "vazia"
      prev = p;
      if(el < p->el)
        p = p->left;
      else
        p = p->right;
    }
    if (root == 0)    // tree is empty;
      root = new BSTNode(el);
    else
      if (el < prev->el)
        prev->left  = new BSTNode(el);
      else
        prev->right = new BSTNode(el);
  }

  void ordem(){//funcao que ja usa as funcoes para dar cout nas ordem e na formataçao do uri
    queue< BSTNode* > fila;
    BSTNode *p = root;
    if (p != 0) {
        fila.push(p);
        while (!fila.empty()) {
            p = fila.front(); //pega no do inicio da fila
            fila.pop(); //remove no do inicio da fila
            if(p == root)
              cout << p->el;
            else
              cout<<" "<< p->el;
            if (p->left != 0)
                 fila.push(p->left); //insere no final da fila
            if (p->right != 0)
                 fila.push(p->right); //insere no final da fila
        }
    }
  }


protected:
  BSTNode* root; //raiz
};

int main(){

  int n,x,y;
  cin >> n;//quantos testes serão feitos
  for(int i = 1; i <= n; i++){//rodar o numero de testes selecionados
    arvore arv;
    cin >> x;//quantidade de numeros que vai compor a arvore
    for(int k = 0; k < x; k++){//inserçao de todos os termos da arvore
      cin >> y;
      arv.inserir(y);
    }
    cout << "Case "<< i << ":\n";
    arv.ordem();//mostrar a ordem
    cout << endl << endl;
  }
  return 0;
}
