// Materia: Programaci�n I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 26/11/2023
// N�mero de ejericio: 7
// Problema planteado: Escriba un programa que tenga como entrada un fichero que contenga un texto y d� como resultado una estad�stica del n�mero de palabras.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contarPalabrasEnArchivo(const char* nombreArchivo);

int main() {
    setlocale(LC_ALL, "");
    const char* NOMBRE_ARCHIVO = "texto.txt"; // de acuerdo al nombre dl archivo

    int numPalabras = contarPalabrasEnArchivo(NOMBRE_ARCHIVO);
    cout << "N�mero total de palabras en el archivo: " << numPalabras << endl;

    return 0;
}

int contarPalabrasEnArchivo(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    int contador = 0;
    string palabra;

    while (archivo >> palabra) {
        contador++;
    }
    archivo.close();
    return contador;
}

