/*
 * UNIVERSIDAD TECNICA DE AMBATO
 * FACULTAD: INGENIERIA EN SISTEMAS, ELECTRONICA E INDUSTRIAL
 * CARRERA: Software
 * ASIGNATURA: ESTRUCTURA DE DATOS
 * CICLO ACADEMICO: ENERO 2026 - JULIO 2026
 * TEMA: Gestion de coleccion de datos utilizando listas
 * OBJETIVO: Determinar el calculo de la media de valores estructurados
 *           utilizando programacion orientada a objetos y listas.
 *
 * INTEGRANTE: Estudiante 4
 * RESPONSABILIDAD: Opcion 4 - Promedio general del curso y menu principal (main)
 *
 * NOTA: Este archivo depende de las definiciones de Estudiante1_Opcion1.cpp
 *       (clase Estudiante, listaEstudiantes, funciones auxiliares).
 *       En el proyecto unificado se incluye todo junto.
 */

#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;

// --- Declaraciones externas (definidas por los otros integrantes) ---
// Se asume que en el proyecto unificado estas ya existen:
//   class Estudiante { ... list<double> notas; ... }
//   list<Estudiante> listaEstudiantes;
//   void menuEstudiantes();         // Estudiante 1
//   void registroCalificaciones();  // Estudiante 2
//   void promedioEstudiante();      // Estudiante 3
//   void limpiarPantalla();
//   void pausar();

// =============================================
// OPCION 4 - PROMEDIO GENERAL DEL CURSO
// Recorre la list<Estudiante> y dentro de cada
// estudiante recorre su list<double> notas
// =============================================
void promedioCurso() {
    limpiarPantalla();
    cout << "=== PROMEDIO GENERAL DE CALIFICACIONES DEL CURSO ===" << endl;

    double sumaTotal  = 0.0;
    int    totalNotas = 0;

    // Iterar sobre cada estudiante de la lista global
    for (list<Estudiante>::iterator it = listaEstudiantes.begin();
         it != listaEstudiantes.end(); ++it) {

        // Iterar sobre la lista de notas de cada estudiante
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

// =============================================
// MENU PRINCIPAL
// =============================================
void menuPrincipal() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "==============================" << endl;
        cout << "    === GESTOR DE PERSONAS ===" << endl;
        cout << "==============================" << endl;
        cout << "  1. Estudiantes." << endl;
        cout << "  2. Registro de calificaciones." << endl;
        cout << "  3. Determinar el promedio de notas de un estudiante." << endl;
        cout << "  4. Determinar el promedio de notas del curso." << endl;
        cout << "  0. Salir." << endl;
        cout << "------------------------------" << endl;
        cout << "Teclee su opcion (1-4): ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1: menuEstudiantes();        break;
            case 2: registroCalificaciones(); break;
            case 3: promedioEstudiante();     break;
            case 4: promedioCurso();          break;
            case 0:
                cout << "\nHasta luego." << endl;
                break;
            default:
                cout << "[!] Opcion invalida." << endl;
                pausar();
        }
    } while (opcion != 0);
}

// =============================================
// MAIN
// =============================================
int main() {
    menuPrincipal();
    return 0;
}
