#include "Estudiante.h"

// =============================================
// LISTA GLOBAL DE ESTUDIANTES
// =============================================
list<Estudiante> listaEstudiantes;

// =============================================
// FUNCION AUXILIAR: string -> int
// =============================================
int strToInt(const string& s) {
    int resultado = 0;
    stringstream ss(s);
    ss >> resultado;
    return resultado;
}

// =============================================
// CONSTRUCTOR DE ESTUDIANTE
// =============================================
Estudiante::Estudiante() {
    cedula = "";
    nombres = "";
    apellidos = "";
    fechaNacimiento = "";
}

bool Estudiante::buscar(string ced) {
    return (cedula == ced);
}

int Estudiante::calcularEdad() {
    if (fechaNacimiento.length() != 10) return 0;
    int dia = strToInt(fechaNacimiento.substr(0, 2));
    int mes = strToInt(fechaNacimiento.substr(3, 2));
    int anio = strToInt(fechaNacimiento.substr(6, 4));

    time_t t = time(NULL);
    tm* hoy = localtime(&t);
    int anioHoy = hoy->tm_year + 1900;
    int mesHoy = hoy->tm_mon + 1;
    int diaHoy = hoy->tm_mday;

    int edad = anioHoy - anio;
    if (mesHoy < mes || (mesHoy == mes && diaHoy < dia)) {
        edad--;
    }
    return edad;
}

double Estudiante::calcularPromedio() {
    if (notas.empty()) return 0.0;
    double suma = 0.0;
    for (list<double>::iterator it = notas.begin(); it != notas.end(); ++it) {
        suma += *it;
    }
    return suma / (double)notas.size();
}

// =============================================
// FUNCIONES AUXILIARES
// =============================================
void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

list<Estudiante>::iterator buscarEstudiantePorCedula(const string& cedula) {
    for (list<Estudiante>::iterator it = listaEstudiantes.begin();
         it != listaEstudiantes.end(); ++it) {
        if (it->buscar(cedula)) return it;
    }
    return listaEstudiantes.end();
}

bool validarCedula(const string& ced) {
    if (ced.length() != 10) return false;
    for (int i = 0; i < (int)ced.length(); i++) {
        if (ced[i] < '0' || ced[i] > '9') return false;
    }
    return true;
}

bool validarFecha(const string& fecha) {
    if (fecha.length() != 10) return false;
    if (fecha[2] != '/' || fecha[5] != '/') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (fecha[i] < '0' || fecha[i] > '9') return false;
    }
    int dia = strToInt(fecha.substr(0, 2));
    int mes = strToInt(fecha.substr(3, 2));
    int anio = strToInt(fecha.substr(6, 4));
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;
    if (anio < 1900 || anio > 2100) return false;
    return true;
}

double leerNota() {
    double nota;
    while (true) {
        cout << "  Ingrese la nota (0.00 - 10.00): ";
        cin >> nota;
        if (cin.fail() || nota < 0.0 || nota > 10.0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  [!] Nota invalida. Debe ser un valor entre 0 y 10." << endl;
        } else {
            cin.ignore(1000, '\n');
            return nota;
        }
    }
}

void mostrarListaEstudiantes() {
    cout << "\n----------------------------------------------------------" << endl;
    cout << "  No. | Cedula     | Nombres          | Apellidos" << endl;
    cout << "----------------------------------------------------------" << endl;

    if (listaEstudiantes.empty()) {
        cout << "  (No hay estudiantes registrados)" << endl;
    } else {
        int contador = 1;
        for (list<Estudiante>::iterator it = listaEstudiantes.begin();
             it != listaEstudiantes.end(); ++it, ++contador) {
            cout << "  " << setw(3) << contador << " | "
                 << setw(10) << left << it->cedula << " | "
                 << setw(16) << left << it->nombres << " | "
                 << it->apellidos << endl;
        }
    }
    cout << "----------------------------------------------------------" << endl;
}
