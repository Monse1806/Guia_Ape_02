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
 * INTEGRANTE: Estudiante 3
 * RESPONSABILIDAD: Opcion 3 - Determinar el promedio de notas de un estudiante
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

// --- Declaraciones externas (definidas por Estudiante 1) ---
// Se asume que en el proyecto unificado estas ya existen:
//   class Estudiante { ... list<double> notas; ... calcularEdad(); calcularPromedio(); ... }
//   list<Estudiante> listaEstudiantes;
//   list<Estudiante>::iterator buscarEstudiantePorCedula(const string&);
//   void limpiarPantalla();
//   void pausar();

// =============================================
// OPCION 3 - PROMEDIO DE NOTAS DE UN ESTUDIANTE
// Recorre la list<double> notas mediante iterador
// =============================================
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
