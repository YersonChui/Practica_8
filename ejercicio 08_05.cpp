// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 5
// Problema planteado: Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados
// genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros.
#include <iostream>
#include <fstream>

using namespace std;

struct Articulo {
    int codigo;
    char nombre[50];
    int existencias;
    double precio;
};

void mezclarArchivos(const char* archivo1, const char* archivo2, const char* archivoSalida);

int main() {
    setlocale(LC_ALL, "");
    const char* ARCHIVO1 = "articulos1.dat";
    const char* ARCHIVO2 = "articulos2.dat";
    const char* ARCHIVO_SALIDA = "articulos_mezclados.dat";

    mezclarArchivos(ARCHIVO1, ARCHIVO2, ARCHIVO_SALIDA);

    return 0;
}

void mezclarArchivos(const char* archivo1, const char* archivo2, const char* archivoSalida) {
    ifstream file1(archivo1, ios::binary);
    ifstream file2(archivo2, ios::binary);
    ofstream salida(archivoSalida, ios::binary);

    Articulo articulo1, articulo2;
    bool hayArticulo1 = file1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo)).good();
    bool hayArticulo2 = file2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo)).good();

    while (hayArticulo1 && hayArticulo2) {
        if (articulo1.codigo < articulo2.codigo) {
            salida.write(reinterpret_cast<const char*>(&articulo1), sizeof(Articulo));
            hayArticulo1 = file1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo)).good();
        } else {
            salida.write(reinterpret_cast<const char*>(&articulo2), sizeof(Articulo));
            hayArticulo2 = file2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo)).good();
        }
    }

    // los artículos restantes de cada archivo
    while (hayArticulo1) {
        salida.write(reinterpret_cast<const char*>(&articulo1), sizeof(Articulo));
        hayArticulo1 = file1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo)).good();
    }

    while (hayArticulo2) {
        salida.write(reinterpret_cast<const char*>(&articulo2), sizeof(Articulo));
        hayArticulo2 = file2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo)).good();
    }

    file1.close();
    file2.close();
    salida.close();
}


