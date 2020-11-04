#include <iostream>

using namespace std;

class funcao{
public:
  int x, y;

  funcao(){
    x = 0;
    y = 0;
  }  //construtor

  void setxy(int xn, int yn){
    x = xn;
    y = yn;
  }

  int fRafael(){
    return (9*x*x + y*y);
  }

  int fBeto(){
    return (2*x*x + 25*y*y);
  }

  int fCarlos(){
    return (x*(-100) + y*y*y);
  }
};

int main() {

  setlocale(LC_ALL,"portuguese");
    int x, y, n;
  int rafael, beto, carlos;
  funcao f;

  cin >> n;//quantos testes ser�o feitos

  for(int i = 0; i < n; i++){
    do{
      cin >> x;//valor de x
    }while(x < 1);
    do{
      cin >> y;//valor de y
    }while(y > 100);
    f.setxy(x,y);
    rafael =  f.fRafael();
    beto = f.fBeto();
    carlos = f.fCarlos();

      if(rafael > beto && rafael > carlos){
        cout << "Rafael ganhou" << endl;
      }
      if(beto > rafael && beto > carlos){
        cout << "Beto ganhou" << endl;
      }
      if(carlos > rafael && carlos > beto){
        cout << "Carlos ganhou" << endl;
      }

  }

    return 0;
}
