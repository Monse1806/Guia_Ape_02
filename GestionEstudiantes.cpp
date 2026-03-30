#ifndef ESTUDIANTE1_H
#define ESTUDIANTE1_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;
const int MAX_ESTUDIANTES = 20;
const int MAX_NOTAS       = 7;

// FUNCION AUXILIAR: string -> int
int strToInt(const string& s) {
    int resultado = 0;
    stringstream ss(s);
    ss >> resultado;
    return resultado;
}

// CLASE Estudiante
// Usa list<double> para las notas en lugar de arreglo
class Estudiante {
public:
    string        cedula;
    string        nombres;
    string        apellidos;
    string        fechaNacimiento; 
    list<double>  notas;         

    // Constructor
    Estudiante() {
        cedula          = "";
        nombres         = "";
        apellidos       = "";
        fechaNacimiento = "";
        // La lista se inicializa vacia automaticamente
    }

    // Metodo buscar: retorna true si la cedula coincide
    bool buscar(string ced) {
        return (cedula == ced);
    }

    // Calcula la edad a partir de la fecha de nacimiento (DD/MM/AAAA)
    int calcularEdad() {
        if (fechaNacimiento.length() != 10) return 0;
        int dia  = strToInt(fechaNacimiento.substr(0, 2));
        int mes  = strToInt(fechaNacimiento.substr(3, 2));
        int anio = strToInt(fechaNacimiento.substr(6, 4));

        time_t t   = time(NULL);
        tm*    hoy = localtime(&t);
        int anioHoy = hoy->tm_year + 1900;
        int mesHoy  = hoy->tm_mon  + 1;
        int diaHoy  = hoy->tm_mday;

        int edad = anioHoy - anio;
        if (mesHoy < mes || (mesHoy == mes && diaHoy < dia)) {
            edad--;
        }
        return edad;
    }

    // Calcula el promedio de notas del estudiante recorriendo la lista
    double calcularPromedio() {
        if (notas.empty()) return 0.0;
        double suma = 0.0;
        for (list<double>::iterator it = notas.begin(); it != notas.end(); ++it) {
            suma += *it;
        }
        return suma / (double)notas.size();
    }
};

// LISTA GLOBAL DE ESTUDIANTES (en lugar de arreglo)
list<Estudiante> listaEstudiantes;

// FUNCIONES AUXILIARES

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

// Busca un estudiante por cedula en la lista y retorna un iterador
list<Estudiante>::iterator buscarEstudiantePorCedula(const string& cedula) {
    for (list<Estudiante>::iterator it = listaEstudiantes.begin();
         it != listaEstudiantes.end(); ++it) {
        if (it->buscar(cedula)) {
            return it;
        }
    }
    return listaEstudiantes.end(); // no encontrado
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
    int dia  = strToInt(fecha.substr(0, 2));
    int mes  = strToInt(fecha.substr(3, 2));
    int anio = strToInt(fecha.substr(6, 4));
    if (mes < 1 || mes > 12)   return false;
    if (dia < 1 || dia > 31)   return false;
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
// MUESTRA LISTA DE ESTUDIANTES
void mostrarListaEstudiantes() {
    cout << "  No. | Cedula     | Nombres          | Apellidos" << endl;

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
}

// OPCION 1 - GESTION DE ESTUDIANTES

void insertarEstudiante() {
    if ((int)listaEstudiantes.size() >= MAX_ESTUDIANTES) {
        cout << "\n[!] Ya se alcanzo el cupo maximo de " << MAX_ESTUDIANTES
             << " estudiantes. No se puede insertar mas." << endl;
        pausar();
        return;
    }

    bool continuar = true;
    while (continuar && (int)listaEstudiantes.size() < MAX_ESTUDIANTES) {
        limpiarPantalla();
        cout << "=== INSERTAR ESTUDIANTE ===" << endl;

        Estudiante nuevo;

        // Cedula
        while (true) {
            cout << "Cedula de identidad (10 digitos): ";
            cin >> nuevo.cedula;
            cin.ignore(1000, '\n');
            if (!validarCedula(nuevo.cedula)) {
                cout << "[!] Cedula invalida. Debe tener exactamente 10 digitos numericos." << endl;
                continue;
            }
            if (buscarEstudiantePorCedula(nuevo.cedula) != listaEstudiantes.end()) {
                cout << "[!] Ya existe un estudiante con esa cedula." << endl;
                continue;
            }
            break;
        }

        cout << "Nombres: ";
        getline(cin, nuevo.nombres);

        cout << "Apellidos: ";
        getline(cin, nuevo.apellidos);

        // Fecha
        while (true) {
            cout << "Fecha de nacimiento (DD/MM/AAAA): ";
            cin >> nuevo.fechaNacimiento;
            cin.ignore(1000, '\n');
            if (!validarFecha(nuevo.fechaNacimiento)) {
                cout << "[!] Formato de fecha invalido. Use DD/MM/AAAA." << endl;
            } else {
                break;
            }
        }

        // Agregar a la lista con push_back
        listaEstudiantes.push_back(nuevo);
        cout << "\n[OK] Estudiante registrado exitosamente." << endl;

        if ((int)listaEstudiantes.size() >= MAX_ESTUDIANTES) {
            cout << "[!] Se ha alcanzado el cupo maximo de estudiantes." << endl;
            continuar = false;
            pausar();
        } else {
            char resp;
            cout << "\nDesea ingresar otro estudiante? (s/n): ";
            cin >> resp;
            cin.ignore(1000, '\n');
            continuar = (resp == 's' || resp == 'S');
        }
    }
}

void modificarEstudiante() {
    if (listaEstudiantes.empty()) {
        cout << "\n[!] No hay estudiantes registrados para modificar." << endl;
        pausar();
        return;
    }

    bool continuar = true;
    while (continuar) {
        limpiarPantalla();
        cout << "=== MODIFICAR ESTUDIANTE ===" << endl;
        mostrarListaEstudiantes();

        int num;
        cout << "\nIngrese el numero del estudiante a modificar (0 para cancelar): ";
        cin >> num;
        cin.ignore(1000, '\n');

        if (num == 0) break;
        if (num < 1 || num > (int)listaEstudiantes.size()) {
            cout << "[!] Numero invalido." << endl;
            pausar();
            continue;
        }

        // Avanzar el iterador hasta la posicion deseada
        list<Estudiante>::iterator it = listaEstudiantes.begin();
        for (int i = 1; i < num; i++) ++it;

        cout << "\nModificando: " << it->nombres << " " << it->apellidos << endl;
        cout << "(Presione Enter para mantener el valor actual)" << endl;

        string tmp;

        cout << "Nueva cedula [" << it->cedula << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) {
            if (!validarCedula(tmp)) {
                cout << "[!] Cedula invalida. Se mantiene la anterior." << endl;
            } else {
                list<Estudiante>::iterator otro = buscarEstudiantePorCedula(tmp);
                if (otro != listaEstudiantes.end() && otro != it) {
                    cout << "[!] Ya existe otro estudiante con esa cedula." << endl;
                } else {
                    it->cedula = tmp;
                }
            }
        }

        cout << "Nuevos nombres [" << it->nombres << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) it->nombres = tmp;

        cout << "Nuevos apellidos [" << it->apellidos << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) it->apellidos = tmp;

        cout << "Nueva fecha de nacimiento [" << it->fechaNacimiento << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) {
            if (!validarFecha(tmp)) {
                cout << "[!] Formato invalido. Se mantiene la fecha anterior." << endl;
            } else {
                it->fechaNacimiento = tmp;
            }
        }

        cout << "\n[OK] Datos modificados exitosamente." << endl;

        char resp;
        cout << "\nDesea modificar otro estudiante? (s/n): ";
        cin >> resp;
        cin.ignore(1000, '\n');
        continuar = (resp == 's' || resp == 'S');
    }
}

void eliminarEstudiante() {
    if (listaEstudiantes.empty()) {
        cout << "\n[!] No hay estudiantes registrados para eliminar." << endl;
        pausar();
        return;
    }

    bool continuar = true;
    while (continuar && !listaEstudiantes.empty()) {
        limpiarPantalla();
        cout << "=== ELIMINAR ESTUDIANTE ===" << endl;
        mostrarListaEstudiantes();

        int num;
        cout << "\nIngrese el numero del estudiante a eliminar (0 para cancelar): ";
        cin >> num;
        cin.ignore(1000, '\n');

        if (num == 0) break;
        if (num < 1 || num > (int)listaEstudiantes.size()) {
            cout << "[!] Numero invalido." << endl;
            pausar();
            continue;
        }

        // Obtener iterador en posicion num
        list<Estudiante>::iterator it = listaEstudiantes.begin();
        for (int i = 1; i < num; i++) ++it;

        cout << "\nConfirma eliminar a " << it->nombres
             << " " << it->apellidos << "? (s/n): ";
        char conf;
        cin >> conf;
        cin.ignore(1000, '\n');

        if (conf == 's' || conf == 'S') {
            // erase() elimina el nodo directamente sin desplazar elementos
            listaEstudiantes.erase(it);
            cout << "[OK] Estudiante eliminado exitosamente." << endl;
        } else {
            cout << "[!] Eliminacion cancelada." << endl;
        }

        if (listaEstudiantes.empty()) {
            cout << "[!] Ya no hay estudiantes registrados." << endl;
            continuar = false;
            pausar();
        } else {
            char resp;
            cout << "\nDesea eliminar otro estudiante? (s/n): ";
            cin >> resp;
            cin.ignore(1000, '\n');
            continuar = (resp == 's' || resp == 'S');
        }
    }
}

void menuEstudiantes() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "=== GESTION DE ESTUDIANTES ===" << endl;
        mostrarListaEstudiantes();
        cout << "\n  1. Ingresar estudiante" << endl;
        cout << "  2. Modificar estudiante" << endl;
        cout << "  3. Eliminar estudiante" << endl;
        cout << "  4. Regresar al menu principal" << endl;
        cout << "\nTeclee su opcion (1-4): ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1: insertarEstudiante();  break;
            case 2: modificarEstudiante(); break;
            case 3: eliminarEstudiante();  break;
            case 4: break;
            default:
                cout << "[!] Opcion invalida." << endl;
                pausar();
        }
    } while (opcion != 4);
}

#endif // ESTUDIANTE1_H
