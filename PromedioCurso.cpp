#include "Estudiante.h"

void promedioCurso() {
    limpiarPantalla();
    cout << "=== PROMEDIO GENERAL DE CALIFICACIONES DEL CURSO ===" << endl;

    double sumaTotal = 0.0;
    int totalNotas = 0;

    for (list<Estudiante>::iterator it = listaEstudiantes.begin();
         it != listaEstudiantes.end(); ++it) {
        for (list<double>::iterator nit = it->notas.begin();
             nit != it->notas.end(); ++nit) {
            sumaTotal += *nit;
            totalNotas++;
        }
    }

    if (totalNotas == 0) {
        cout << "\n  No se han registrado calificaciones de estudiantes." << endl;
    } else {
        double promedio = sumaTotal / (double)totalNotas;
        cout << "\n  Total de calificaciones registradas : " << totalNotas << endl;
        cout << "  Promedio general del curso          : "
             << fixed << setprecision(2) << promedio << endl;
    }

    pausar();
}
