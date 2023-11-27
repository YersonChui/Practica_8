// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 4
// Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los artículos de un almacén

#include <iostream>
#include <fstream>

using namespace std;

struct Articulo {
    int codigo;
    char nombre[50];
    int existencias;
    double precio;
};

void ingresarArticulos(const char* archivoTemporal);
void ordenarYGuardarArticulos(const char* archivoTemporal, const char* archivoFinal);
void ordenacionBurbuja(Articulo arr[], int n);

const char* ARCHIVO_TEMPORAL = "articulos_temp.dat";
const char* ARCHIVO_FINAL = "articulos.dat";
const int MAX_ARTICULOS = 1000; // limite :D

int main() {
    setlocale(LC_ALL, "");
    ingresarArticulos(ARCHIVO_TEMPORAL);
    ordenarYGuardarArticulos(ARCHIVO_TEMPORAL, ARCHIVO_FINAL);
    remove(ARCHIVO_TEMPORAL); // Opcional: elimina el archivo temporal

    return 0;
}

void ingresarArticulos(const char* archivoTemporal) {
    ofstream archivo(archivoTemporal, ios::binary);
    Articulo articulo;

    while (true) {
        cout << "Ingrese código del artículo (0 para terminar): ";
        cin >> articulo.codigo;
        cin.ignore();

        if (articulo.codigo == 0) {
            break;
        }

        cout << "Ingrese nombre del artículo: ";
        cin.getline(articulo.nombre, 50);
        cout << "Ingrese existencias actuales: ";
        cin >> articulo.existencias;
        cout << "Ingrese precio: ";
        cin >> articulo.precio;

        archivo.write(reinterpret_cast<const char*>(&articulo), sizeof(articulo));
    }

    archivo.close();
}

void ordenarYGuardarArticulos(const char* archivoTemporal, const char* archivoFinal) {
    Articulo articulos[MAX_ARTICULOS];
    int numArticulos = 0;

    ifstream archivoLeer(archivoTemporal, ios::binary);
    while (archivoLeer.read(reinterpret_cast<char*>(&articulos[numArticulos]), sizeof(Articulo))) {
        numArticulos++;
    }
    archivoLeer.close();

    ordenacionBurbuja(articulos, numArticulos);

    ofstream archivoEscribir(archivoFinal, ios::binary);
    for (int i = 0; i < numArticulos; i++) {
        archivoEscribir.write(reinterpret_cast<const char*>(&articulos[i]), sizeof(Articulo));
    }
    archivoEscribir.close();
}

void ordenacionBurbuja(Articulo arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].codigo > arr[j+1].codigo) {
                Articulo temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

