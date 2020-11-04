#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class rena{//classe para possuir as caracteristicas das renas
public:
  int p, i;
  float a;
  string s;
  rena(){
  }
  rena(int p, int i, float a, string s){ // contrutor
    this->p = p;
    this->i = i;
    this->a = a;
    this->s = s;
  }
  //funções para usar na ordenação
  void mostra(){
    cout << s;
  }
  int peso(){
    return p;
  }
  int idade(){
    return i;
  }
  float altura(){
    return a;
  }
  string nome(){
    return s;
  }
};
//funcao de ordenação fora da classe

/*fiz uma ordenação que compara o primeiro termo com resto pra ver
qual vai ser a primeira posiçao, ai entao "reduzo" o tamanho do vetor
e vejo qual a partir dessa nova primeira posiçao faz denovo*/
  void ordem(vector<rena> &v, int n){//parametro sao o vetor com referenia e o número de renas
    rena aux;//variavel auxiliar da classe rena sem parametro para realizar as trocas de posiçao
    for(int i = 0; i < n-1; i++){ //i é a "primeira" posiçao do vetor
      for(int k = i + 1; k < n; k++){//k é com quem vai comparar a "primeira"
        if(v[k].peso() > v[i].peso()){//se o peso de quem não está na primeira posiçao for maior
          aux = v[k];//entao realiza a troca de posiçao
          v[k] = v[i];
          v[i] = aux;
        }
        else if(v[k].peso() == v[i].peso()){//se for igual vai comparar a idade
          if(v[k].idade() < v[i].idade()){//se for menor
            aux = v[k];//troca
            v[k] = v[i];
            v[i] = aux;
          }
          else if(v[k].idade() == v[i].idade()){//se for igual vai comparar a altura
            if(v[k].altura() < v[i].altura()){
              aux = v[k];
              v[k] = v[i];
              v[i] = aux;
            }
            else if(v[k].altura() == v[i].altura()){
              if(v[k].nome() < v[i].nome()){
                aux = v[k];
                v[k] = v[i];
                v[i] = aux;
              }
            }
          }
        }
      }
    }
  }

int main(){
  int t, n, m, p, i;//casos, renas, renas no trenó, peso, idade
  float a;//altura
  string s;//nome
  cin >> t;//numero de casos
  int k = 1;//contador de CENARIO
  while(k <= t){
    cin >> n >> m;
    vector<rena> todas;//vetor com todas as renas do tipo classe rena para guardar todas as caracteristicas
    for(int j = 0; j < n; j++){//pedir a informação das renas
      cin >> s >> p >> i >> a;
      rena renas(p, i, a, s);//criando uma classe da rena com os parametros dela
      todas.push_back(renas);//colocando no vetor
    }
    ordem(todas, n);  //usando a funcao de ordenação
    cout << "CENARIO {"<< k << "}\n";
    for(int f = 0; f < m; f++){//for para mostrar os nomes já na ordem
      cout << f+1 << " - ";
      todas[f].mostra();
      cout << endl;
    }


    k++;
  }


return 0;
 }
