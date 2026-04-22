#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Dibuja la palabra con guiones o letras
void mostrarPalabra(string secreta, vector<bool> acertadas) {
    for (int i = 0; i < secreta.length(); i++) {
        if (acertadas[i]) {
            cout << secreta[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Revisa si la letra está en la palabra y marca dónde
bool checarLetra(string secreta, vector<bool> &acertadas, char letra) {
    bool huboAcierto = false;
    for (int i = 0; i < secreta.length(); i++) {
        if (tolower(secreta[i]) == letra) {
            acertadas[i] = true;
            huboAcierto = true;
        }
    }
    return huboAcierto;
}

int main() {
    string palabra;
    int vidas = 6;
    char letra;

    cout << "Escribe la palabra secreta: ";
    cin >> palabra;

    // Creamos una lista de visto o no visto del mismo tamaño que la palabra
    vector<bool> acertadas(palabra.length(), false);

    cout << "\n///////////////// EL AHORCADO ////////////////////\n";

    while (vidas > 0) {
        cout << "\nPalabra: ";
        mostrarPalabra(palabra, acertadas);
        cout << "Vidas: " << vidas << endl;

        cout << "Dime una letra: ";
        cin >> letra;
        letra = tolower(letra);

        if (checarLetra(palabra, acertadas, letra)) {
            cout << "Bien Esa letra sí está.\n";
        } else {
            cout << "no esta esa letra.\n";
            vidas--;
        }

        // Comprobamos si ya ganó revisando si quedan guiones
        bool yaGano = true;
        for (bool b : acertadas) {
            if (b == false) yaGano = false;
        }

        if (yaGano) {
            cout << "\nGanaste La palabra era: " << palabra << endl;
            return 0;
        }
    }

    cout << "\nPerdiste... La palabra era: " << palabra << endl;
    return 0;
}