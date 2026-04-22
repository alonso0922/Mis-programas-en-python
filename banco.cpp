#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {
public:
    string nombre;
    int id;
    Cliente(string n, int i) {
        nombre = n;
        id = i;
    }
};

class Transaccion {
public:
    string tipo;
    double monto;
    double saldoFinal;

    void mostrar() {
        cout << "Operacion: " << tipo << " | Cantidad: $" << monto << " | Saldo: $" << saldoFinal << endl;
    }
};

class CuentaBancaria {
public:
    double saldo;
    vector<Transaccion> historial; 

    CuentaBancaria(double s) {
        saldo = s;
    }

    void depositar(double m) {
        saldo = saldo + m;
        Transaccion t;
        t.tipo = "Deposito";
        t.monto = m;
        t.saldoFinal = saldo;
        historial.push_back(t);
    }

    void retirar(double m) {
        if (saldo >= m) {
            saldo = saldo - m;
            Transaccion t;
            t.tipo = "Retiro";
            t.monto = m;
            t.saldoFinal = saldo;
            historial.push_back(t);
        } else {
            cout << "No hay dinero suficiente para retirar $" << m << endl;
        }
    }
};

class CuentaAhorro : public CuentaBancaria {
public:
    double interes;

    CuentaAhorro(double s, double i) : CuentaBancaria(s) {
        interes = i;
    }

    void aplicarInteres() {
        double ganancia = saldo * interes;
        saldo = saldo + ganancia;
        
        Transaccion t;
        t.tipo = "Interes Aplicado";
        t.monto = ganancia;
        t.saldoFinal = saldo;
        historial.push_back(t);
    }
};

class Banco {
public:
    string nombreBanco;
    vector<Cliente> listaClientes;

    Banco(string n) {
        nombreBanco = n;
    }

    void agregarCliente(string n, int i) {
        Cliente nuevo(n, i);
        listaClientes.push_back(nuevo);
    }

    void mostrarClientes() {
        cout << "--- " << nombreBanco << " ---" << endl;
        for (int i = 0; i < listaClientes.size(); i++) {
            cout << "ID: " << listaClientes[i].id << " - Nombre: " << listaClientes[i].nombre << endl;
        }
    }
};

int main() {

    Banco miBanco("Banco BIENESTAR");
    miBanco.agregarCliente("Juan Perez", 1);
    miBanco.agregarCliente("Maria Lopez", 2);
    miBanco.mostrarClientes();


    CuentaAhorro miCuenta(1000.0, 0.05);

    miCuenta.depositar(500.0);
    miCuenta.aplicarInteres();
    miCuenta.retirar(200.0);

    // 4. Imprimir todas las transacciones como texto
    cout << "\nLISTA DE TRANSACCIONES:" << endl;
    for (int i = 0; i < miCuenta.historial.size(); i++) {
        miCuenta.historial[i].mostrar();
    }

    return 0;
}