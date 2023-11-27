// Materia: Programaci�n I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creaci�n: 20/11/2023
// Fecha modificaci�n: 26/11/2023
// N�mero de ejericio: 1
// Problema planteado: Escribir un programa con la opci�n de encriptar y de desencriptar un fichero de texto.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encriptarArchivo(const string& archivoEntrada, const string& archivoSalida);
void desencriptarArchivo(const string& archivoEntrada, const string& archivoSalida);

int main() {
    setlocale(LC_ALL, "");
    string archivoEntrada, archivoSalida;
    int opcion;

    cout << "1. Encriptar\n2. Desencriptar\nSeleccione una opci�n: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        cout << "Ingrese el nombre del archivo de texto para encriptar: ";
        getline(cin, archivoEntrada);
        archivoSalida = archivoEntrada + ".COD";
        encriptarArchivo(archivoEntrada, archivoSalida);
    } else if (opcion == 2) {
        cout << "Ingrese el nombre del archivo .COD para desencriptar: ";
        getline(cin, archivoEntrada);
        archivoSalida = "desencriptado_" + archivoEntrada;
        desencriptarArchivo(archivoEntrada, archivoSalida);
    } else {
        cout << "Opci�n no v�lida." << endl;
    }

    return 0;
}

void encriptarArchivo(const string& archivoEntrada, const string& archivoSalida) {
    ifstream entrada(archivoEntrada, ios::binary);
    ofstream salida(archivoSalida, ios::binary);

    if (!entrada.is_open() || !salida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        return;
    }

    char ch;
    while (entrada.get(ch)) {
        salida.put(static_cast<char>(ch + 3));
    }

    entrada.close();
    salida.close();
}

void desencriptarArchivo(const string& archivoEntrada, const string& archivoSalida) {
    ifstream entrada(archivoEntrada, ios::binary);
    ofstream salida(archivoSalida, ios::binary);

    if (!entrada.is_open() || !salida.is_open()) {
        cerr << "Error al abrir los archivos." << endl;
        return;
    }

    char ch;
    while (entrada.get(ch)) {
        salida.put(static_cast<char>(ch - 3));
    }

    entrada.close();
    salida.close();
}
