#include <iostream>
using namespace std;
class vehiculo{
private:
string marca,tipo;
public:
// Constructor del padre
vehiculo(string m, string t) : marca(m), tipo(t) {}
void mostrarInfo() {
        cout << "Tipo: " << tipo << " | Marca: " << marca << endl;
    }
};
class automovil: public vehiculo{
private:
int numPuertas;
public:
automovil(string m,int p):vehiculo(m,"automovil"),numPuertas(p){}
void mostrarPuertas() {
        cout << "Puertas: " << numPuertas << endl;
    }
};
class moto: public vehiculo{
private:
int llantas;
public:
moto(string m,int r):vehiculo(m,"motocicleta"),llantas(r){}
void mostrardatos() {
        cout << "llantas: " << llantas << endl;
    }
};

class autobus: public vehiculo{
private:
int numPuertas,asientos,piso;
public:
autobus(string m,int p,int a,int r):vehiculo(m,"Autobus"),numPuertas(p),asientos(a),piso(r){}
void mostrardatos() {
        cout << "|puertas: " << numPuertas<<"|Asientos:"<<asientos<<"|Piso:"<<piso << endl;
    }
};
int main(){
automovil micarro("honda",4);
moto mimoto("italika",2);
autobus miautobus("volvo",3,52,2);
micarro.mostrarInfo();
micarro.mostrarPuertas();
mimoto.mostrarInfo();
mimoto.mostrardatos();
miautobus.mostrarInfo();
miautobus.mostrardatos();

}