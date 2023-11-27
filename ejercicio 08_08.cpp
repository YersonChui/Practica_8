// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 8
// Problema planteado:Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de números reales otro fichero de salida <nombre>.BIN grabado en formato binario.
#include <iostream>
#include <fstream>

using namespace std;

void convertirATextoBinario(const char* archivoEntrada, const char* archivoSalida);

int main() {
    setlocale(LC_ALL, "");
    const char* ARCHIVO_ENTRADA = "numeros.txt";
    const char* ARCHIVO_SALIDA = "numeros.BIN";

    convertirATextoBinario(ARCHIVO_ENTRADA, ARCHIVO_SALIDA);

    return 0;
}

void convertirATextoBinario(const char* archivoEntrada, const char* archivoSalida) {
    ifstream entrada(archivoEntrada);
    if (!entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return;
    }
    ofstream salida(archivoSalida, ios::binary);
    if (!salida.is_open()) {
        cerr << "No se pudo crear el archivo de salida." << endl;
        return;
    }
    double numero;
    while (entrada >> numero) {
        salida.write(reinterpret_cast<const char*>(&numero), sizeof(numero));
    }
    entrada.close();
    salida.close();
}



