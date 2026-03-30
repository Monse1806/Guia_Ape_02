#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;
void promedioEstudiante() {
    limpiarPantalla();
    cout << "=== PROMEDIO DE NOTAS DE UN ESTUDIANTE ===" << endl;

    string cedula;
    cout << "Ingrese la cedula del estudiante: ";
    cin >> cedula;
    cin.ignore(1000, '\n');

    // Busca en la lista de estudiantes usando el iterador
    list<Estudiante>::iterator it = buscarEstudiantePorCedula(cedula);

    if (it == listaEstudiantes.end()) {
        // No se encontro: emitir mensaje de error
        cout << "\n[!] Error: No se encontro un estudiante con cedula: "
             << cedula << endl;
    } else {
        // Mostrar datos del estudiante
        cout << "\n  Nombres  : " << it->nombres << " " << it->apellidos << endl;
        cout << "  Edad     : " << it->calcularEdad() << " anios" << endl;

        if (it->notas.empty()) {
            cout << "  Promedio : (Sin calificaciones registradas)" << endl;
        } else {
            // Recorrer la lista de notas para mostrarlas
            cout << "  Calificaciones: ";
            bool primero = true;
            for (list<double>::iterator nit = it->notas.begin();
                 nit != it->notas.end(); ++nit) {
                if (!primero) cout << ", ";
                cout << fixed << setprecision(2) << *nit;
                primero = false;
            }
            cout << endl;

            // calcularPromedio() ya recorre internamente la lista de notas
            cout << "  Promedio : " << fixed << setprecision(2)
                 << it->calcularPromedio() << endl;
        }
    }

    pausar();
}
