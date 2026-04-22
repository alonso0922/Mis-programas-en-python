#include <iostream>
#include <string>

class Programador {
    private:
        std::string nombre;
        std::string lenguajeFavorito;
        int añosExperiencia;

    public:
        // Constructor usando lista de inicialización
        Programador(std::string _nombre, std::string _lenguaje, int _años) 
            : nombre(_nombre), lenguajeFavorito(_lenguaje), añosExperiencia(_años) {}
        
        void presentarse() {
            std::cout << "Hola, soy " << nombre << "." << std::endl;
            std::cout << "Mi lenguaje favorito es " << lenguajeFavorito << "." << std::endl;
            std::cout << "Tengo " << añosExperiencia << " años de experiencia." << std::endl;
        }

        void celebrarAniversario() {
            añosExperiencia++;
            std::cout << "¡Hackeando el tiempo! Años de experiencia actualizados a: " << añosExperiencia << std::endl;
        }
}; 

int main() {
    // Creación del objeto
    Programador miUsuario("Alonso", "C++", 1);

    miUsuario.presentarse();
    std::cout << "-------------------------------" << std::endl;
    miUsuario.celebrarAniversario();

    return 0;
}