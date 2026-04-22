#include <iostream>
#include <cmath.h>
using namespace std;
class calculadora{
private:
double op;
public:
void suma(double n1,double n2){
    op=n1+n2;
    cout<<"El resultado es: "<<op<<"\n";
}
void resta(double n1,double n2){
    op=n1-n2;
    cout<<"El resultado es: "<<op<<"\n";
}
void multi(double n1,double n2){
    op=n1*n2;
    cout<<"El resultado es: "<<op<<"\n";
}
void div(double n1,double n2){
    op=n1/n2;
    cout<<"El resultado es: "<<op<<"\n";
}
void pot(double n1,double n2){
    op=pow(n1,n2);
    cout<<"El resultado es: "<<op<<"\n";
}
void raiz(double n1){
    op=sqrt(n1);
    cout<<"El resultado es: "<<op<<"\n";
}
};
int main(){
int opc;
double n1,n2;
bool acc=true;
calculadora usuario;
while(acc){
cout<<"////////////////////////////////////////////////////////\n";
cout<<"1) Suma\n2) Resta\n3) Multiplicacion\n4) Division\n5) Potencia\n6) Raiz\n7) Salir\n";
cout<<"Ingresa la operacion que quieras que realice la calculadora:\n";
cin>>opc;
switch(opc){
case 1:
cout<<"Ingresa los numeros:\n";
cin>>n1>>n2;
usuario.suma(n1,n2);
break;
case 2:
cout<<"Ingresa los numeros:\n";
cin>>n1>>n2;
usuario.resta(n1,n2);
break;
case 3:
cout<<"Ingresa los numeros:\n";
cin>>n1>>n2;
usuario.multi(n1,n2);
break;
case 4:
cout<<"Ingresa los numeros:\n";
cin>>n1>>n2;
usuario.div(n1,n2);
break;
case 5:
cout<<"Ingresa los numeros:\n";
cin>>n1>>n2;
usuario.pot(n1,n2);
break;
case 6:
cout<<"Ingresa el numero:\n";
cin>>n1;
usuario.raiz(n1);
break;
case 7:
cout<<"Saliendo del sistema\n";
acc=false;
break;
default:
cout<<"Opcion no disponible\n";
}
}
}