// Materia: Programación I, Paralelo 4
// Autor: Yerson Mateo Chui Mamani
// Fecha creación: 20/11/2023
// Fecha modificación: 26/11/2023
// Número de ejericio: 3
// Problema planteado: Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior, lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
//nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT con toda la información correspondiente a los candidatos aceptados.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    char nombre[31];
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

void leerDatosPersona(Persona& persona);
bool esCandidatoAceptable(const Persona& cliente, const Persona& candidato);
void procesarCandidatos(const Persona& cliente);

const char* ARCHIVO_PERSONAS = "PERSONAS.DAT";
const char* ARCHIVO_ACEPTADOS = "ACEPTADOS.DAT";

int main() {
    setlocale(LC_ALL, "");
    Persona cliente;
    leerDatosPersona(cliente);
    procesarCandidatos(cliente);

    return 0;
}

void leerDatosPersona(Persona& persona) {
    cout << "Ingrese nombre: ";
    cin.getline(persona.nombre, 31);
    cout << "Ingrese edad: ";
    cin >> persona.edad;
    cin.ignore();
    cout << "Ingrese sexo (M/F): ";
    cin >> persona.sexo;
    cin.ignore();
    cout << "Ingrese fecha de nacimiento (dd/mm/yyyy): ";
    cin.getline(persona.fechaNacimiento, 11);
}

bool esCandidatoAceptable(const Persona& cliente, const Persona& candidato) {
    if (cliente.sexo == candidato.sexo) {
        return false;
    }

    string mesAnoCliente(cliente.fechaNacimiento + 3, 7);
    string mesAnoCandidato(candidato.fechaNacimiento + 3, 7);
    return mesAnoCliente == mesAnoCandidato;
}
void procesarCandidatos(const Persona& cliente) {
    ifstream archivoPersonas(ARCHIVO_PERSONAS, ios::binary);
    ofstream archivoAceptados(ARCHIVO_ACEPTADOS, ios::binary);

    if (!archivoPersonas || !archivoAceptados) {
        cerr << "No se pudo abrir uno o ambos archivos." << endl;
        return;
    }
    Persona candidato;
    while (archivoPersonas.read(reinterpret_cast<char*>(&candidato), sizeof(candidato))) {
        if (esCandidatoAceptable(cliente, candidato)) {
            cout << "Candidato aceptado: " << candidato.nombre << endl;
            archivoAceptados.write(reinterpret_cast<const char*>(&candidato), sizeof(candidato));
        }
    }
}

