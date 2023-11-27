// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 9
// Problema planteado: Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se introduzca por pantalla.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int FILAS = 2;    // dependera segun la tabla, es para el ej
const int COLUMNAS = 3;

void leerTablaBinaria(const char* nombreArchivo, double tabla[FILAS][COLUMNAS]);
void calcularSumas(const double tabla[FILAS][COLUMNAS], double sumasHorizontales[FILAS], double sumasVerticales[COLUMNAS]);
void escribirResultado(const char* nombreArchivo, const double tabla[FILAS][COLUMNAS], const double sumasHorizontales[FILAS], const double sumasVerticales[COLUMNAS], bool formatoTexto);

int main() {
    setlocale(LC_ALL, "");
    double tabla[FILAS][COLUMNAS];
    double sumasHorizontales[FILAS] = {0}, sumasVerticales[COLUMNAS] = {0};
    leerTablaBinaria("tabla.BIN", tabla);
    calcularSumas(tabla, sumasHorizontales, sumasVerticales);
    char opcion;
    cout << "Escribir en archivo de texto (T) o binario (B)? ";cin >> opcion;
    escribirResultado("resultado.dat", tabla, sumasHorizontales, sumasVerticales, opcion == 'T' || opcion == 't');
    return 0;
}
void leerTablaBinaria(const char* nombreArchivo, double tabla[FILAS][COLUMNAS]) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return;
    }
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            archivo.read(reinterpret_cast<char*>(&tabla[i][j]), sizeof(double));
        }
    }
    archivo.close();
}
void calcularSumas(const double tabla[FILAS][COLUMNAS], double sumasHorizontales[FILAS], double sumasVerticales[COLUMNAS]) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            sumasHorizontales[i] += tabla[i][j];
            sumasVerticales[j] += tabla[i][j];
        }
    }
}
void escribirResultado(const char* nombreArchivo, const double tabla[FILAS][COLUMNAS], const double sumasHorizontales[FILAS], const double sumasVerticales[COLUMNAS], bool formatoTexto) {
    ofstream archivo(nombreArchivo, formatoTexto ? ios::out : ios::binary);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }
    if (formatoTexto) {
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                archivo << fixed << setprecision(2) << tabla[i][j] << " ";
            }
            archivo << sumasHorizontales[i] << endl;
        }
        for (int j = 0; j < COLUMNAS; ++j) {
            archivo << sumasVerticales[j] << " ";
        }
        archivo << endl;
    } else {
        // fomato binario
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                archivo.write(reinterpret_cast<const char*>(&tabla[i][j]), sizeof(double));
            }
            archivo.write(reinterpret_cast<const char*>(&sumasHorizontales[i]), sizeof(double));
        }
        for (int j = 0; j < COLUMNAS; ++j) {
            archivo.write(reinterpret_cast<const char*>(&sumasVerticales[j]), sizeof(double));
        }
    }
    archivo.close();
}


