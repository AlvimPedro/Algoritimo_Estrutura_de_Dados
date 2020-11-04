#include<iostream>

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
    cout << "Pre.:";
    preordem(root);
    cout << endl << "In..:";
    inordem(root);
    cout << endl << "Post:";
    posordem(root);
    cout << endl << endl;
  }

  void preordem(BSTNode *p){
    if (p != 0) {
      cout << " "<< p->el;//ja da cout na formataçao
      preordem(p->left);
      preordem(p->right);
    }
  }
  void inordem(BSTNode *p){
    if (p != 0) {
        inordem(p->left);
        cout << " "<< p->el;
        inordem(p->right);
    }
  }
  void posordem(BSTNode *p){
    if (p != 0) {
      posordem(p->left);
      posordem(p->right);
      cout << " "<< p->el;
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
    //arv.limpar();//esvaziar a arvore para o proximo caso
  }

  return 0;
}
