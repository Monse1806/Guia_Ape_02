#include "Estudiante.h"

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

int main() {
    menuPrincipal();
    return 0;
}
