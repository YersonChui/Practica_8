// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 2
// Problema planteado: Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se guarde la información de un número indeterminado de personas.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    char nombre[31];//+1 para el espacio
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

void leerDatosPersona(Persona& persona);

const char* ARCHIVO_PERSONAS = "PERSONAS.BIN";

int main() {
    setlocale(LC_ALL, "");
    Persona persona;
    ofstream archivo(ARCHIVO_PERSONAS, ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }
    while (true) {
        leerDatosPersona(persona);
        if (persona.nombre[0] == ' ') {
            break;
        }
        archivo.write(reinterpret_cast<const char*>(&persona), sizeof(persona));
    }
    archivo.close();
    return 0;
}

void leerDatosPersona(Persona& persona) {
    cout << "Ingrese nombre (deje en blanco para terminar): ";
    cin.getline(persona.nombre, 31);

    if (persona.nombre[0] != ' ') {
        cout << "Ingrese edad: ";
        cin >> persona.edad;
        cin.ignore();
        cout << "Ingrese sexo (M/F): ";
        cin >> persona.sexo;
        cin.ignore();
        cout << "Ingrese fecha de nacimiento (dd/mm/yyyy): ";
        cin.getline(persona.fechaNacimiento, 11);
    }
}
