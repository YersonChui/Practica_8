// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 6
// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el campo Precio. La condición podrá ser: Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
//aquellos artículos para los que se cumple la condición de entrada. Mostrar el archivo de salida “salida.dat”
#include <iostream>
#include <fstream>

using namespace std;

struct Articulo {
    int codigo;
    char nombre[50];
    int existencias;
    double precio;
};

void filtrarArticulosPorPrecio(const char* archivoEntrada, const char* archivoSalida, double precio);
void mostrarContenidoArchivo(const char* archivo);

int main() {
    setlocale(LC_ALL, "");
    const char* ARCHIVO_ENTRADA = "articulos.dat";
    const char* ARCHIVO_SALIDA = "salida.dat";
    setlocale(LC_ALL, "");
    double precio;
    cout << "Ingrese el precio mínimo: ";
    cin >> precio;

    filtrarArticulosPorPrecio(ARCHIVO_ENTRADA, ARCHIVO_SALIDA, precio);
    mostrarContenidoArchivo(ARCHIVO_SALIDA);

    return 0;
}

void filtrarArticulosPorPrecio(const char* archivoEntrada, const char* archivoSalida, double precio) {
    ifstream entrada(archivoEntrada, ios::binary);
    ofstream salida(archivoSalida, ios::binary);

    Articulo articulo;
    while (entrada.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        if (articulo.precio >= precio) {
            salida.write(reinterpret_cast<const char*>(&articulo), sizeof(Articulo));
        }
    }

    entrada.close();
    salida.close();
}

void mostrarContenidoArchivo(const char* archivo) {
    ifstream archivoEntrada(archivo, ios::binary);
    Articulo articulo;

    cout << "Contenido del archivo '" << archivo << "':" << endl;
    while (archivoEntrada.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        cout << "Código: " << articulo.codigo
             << ", Nombre: " << articulo.nombre
             << ", Existencias: " << articulo.existencias
             << ", Precio: " << articulo.precio << endl;
    }

    archivoEntrada.close();
}



