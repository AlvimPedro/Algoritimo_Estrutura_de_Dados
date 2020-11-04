#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class sapatos{
  public:
    string n;
    int contn;
    int contm;
    int contf;


    sapatos(){
      n = " ";
      contn = 0;
      contm = 0;
      contf = 0;
    }

    void setn(string nn){
      n = nn;
      contn = 0;
      contm = 0;
      contf = 0;
    }

    void contador(string sapatos){
      string delimitador = " ";
      size_t pos = 0;
      string parte, parteant = "";


      while((pos = sapatos.find(delimitador)) != std::string::npos){
        parte = sapatos.substr(0, pos);
        if(parte == n){
          contn++;
        }
        if(parteant == n){
          if(parte == "M"){
            contm++;
          }
          if(parte == "F"){
            contf++;
          }
        }
        parteant = parte;

        sapatos.erase(0, pos + delimitador.length());
      }
        if(parte == n){
          if(sapatos == "M"){
            contm++;
          }
          if(sapatos == "F"){
            contf++;
          }
        }
    }

    int getContn(){
      return contn;
    }
    int getContm(){
      return contm;
    }
    int getContf(){
      return contf;
    }


};

int main(){
	string sapato;
	string n, busca;
	int cont = 1;
	sapatos sap;
while(getline(cin, n)){

	sap.setn(n);
	getline(cin, sapato);
	sap.contador(sapato);

    if(cont != 1){
        cout << endl;
    }
	cout <<"Caso "<< cont << ":"<< endl << "Pares Iguais: "<<sap.getContn()<< endl
	 << "F: "<< sap.getContf() << endl << "M: "<< sap.getContm() << endl;

cont++;
}
return 0;
}