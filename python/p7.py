class Animal:
    def __init__(self, nombre):
        self.nombre = nombre
        
    def hacer_sonido(self):
        print("El animal hace un sonido")

class Perro(Animal): 
    def hacer_sonido(self):
        print(f"{self.nombre} dice: ¡Guau!")

mi_perro = Perro("Firulais")
mi_perro.hacer_sonido()