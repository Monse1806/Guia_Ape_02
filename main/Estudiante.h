#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

// =============================================
// CONSTANTES
// =============================================
const int MAX_ESTUDIANTES = 20;
const int MAX_NOTAS = 7;

// =============================================
// FUNCION AUXILIAR: string -> int
// =============================================
int strToInt(const string& s);

// =============================================
// CLASE Estudiante [Estudiante 1]
// =============================================
class Estudiante {
public:
    string        cedula;
    string        nombres;
    string        apellidos;
    string        fechaNacimiento;
    list<double>  notas;

    Estudiante();
    bool buscar(string ced);
    int calcularEdad();
    double calcularPromedio();
};

// =============================================
// LISTA GLOBAL DE ESTUDIANTES
// =============================================
extern list<Estudiante> listaEstudiantes;

// =============================================
// FUNCIONES AUXILIARES (Declaraciones)
// =============================================
void limpiarPantalla();
void pausar();
list<Estudiante>::iterator buscarEstudiantePorCedula(const string& cedula);
bool validarCedula(const string& ced);
bool validarFecha(const string& fecha);
double leerNota();
void mostrarListaEstudiantes();

// =============================================
// DECLARACIONES DE FUNCIONES POR MÓDULO
// =============================================
// Estudiante 1 - Gestión de Estudiantes
void insertarEstudiante();
void modificarEstudiante();
void eliminarEstudiante();
void menuEstudiantes();

// Estudiante 2 - Registro de Calificaciones
void registroCalificaciones();

// Estudiante 3 - Promedio de Estudiante
void promedioEstudiante();

// Estudiante 4 - Promedio del Curso
void promedioCurso();
void menuPrincipal();

#endif
