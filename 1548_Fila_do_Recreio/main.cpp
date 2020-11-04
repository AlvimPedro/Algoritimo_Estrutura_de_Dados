#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n, m, p;
  int cont  = 0;
  cin >> n;//numero de casos
  while(n!=0){
    cin >> m;//numero de pessoas no caso
    int fila[m];//criando array com o numero de pessoas que vao ter na fila
    for(int i = 0; i < m; i++){
      cin >> p;//a nota das pessoas
      fila[i] = p;//colocando as notas no array na ordem passada
    }
    vector<int> v (fila, fila+m); //criando um vetor com os mesmos dados para ordenar usando a funcao sort
    sort(v.begin(), v.begin()+m);// usando a funcao sort para ordenar o vetor
    int j = 0;
    for(int k = m - 1; k >= 0; k--){ //for para comparar o vetor ordenado e o array com ordem antiga
      if(fila[j] == v[k]){// comparo o ultimo elemento do vetor com o primeiro do array, pois o vetor fica ordenado na ordem crescente
        cont++;//se forem iguais quer dizer essa pessoa não precisou mudar de lugar
      }
      j++;
    }
    cout << cont << endl;
    cont = 0;
    n--;
  }

return 0;
}
