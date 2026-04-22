class persona:
    def __init__(self,nombre,edad):
        self.nombre=nombre
        self.edad=edad
    def saludar(self):
        print("hola mi nombre es",self.nombre)
Persona1=persona("Francisco",25)
Persona1.saludar()