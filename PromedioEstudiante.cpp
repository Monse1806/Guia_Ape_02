#include "Estudiante.h"

void promedioEstudiante() {
    limpiarPantalla();
    cout << "=== PROMEDIO DE NOTAS DE UN ESTUDIANTE ===" << endl;

    string cedula;
    cout << "Ingrese la cedula del estudiante: ";
    cin >> cedula;
    cin.ignore(1000, '\n');

    list<Estudiante>::iterator it = buscarEstudiantePorCedula(cedula);

    if (it == listaEstudiantes.end()) {
        cout << "\n[!] Error: No se encontro un estudiante con cedula: "
             << cedula << endl;
    } else {
        cout << "\n  Nombres  : " << it->nombres << " " << it->apellidos << endl;
        cout << "  Edad     : " << it->calcularEdad() << " anios" << endl;

        if (it->notas.empty()) {
            cout << "  Promedio : (Sin calificaciones registradas)" << endl;
        } else {
            cout << "  Calificaciones: ";
            bool primero = true;
            for (list<double>::iterator nit = it->notas.begin();
                 nit != it->notas.end(); ++nit) {
                if (!primero) cout << ", ";
                cout << fixed << setprecision(2) << *nit;
                primero = false;
            }
            cout << endl;
            cout << "  Promedio : " << fixed << setprecision(2)
                 << it->calcularPromedio() << endl;
        }
    }

    pausar();
}
