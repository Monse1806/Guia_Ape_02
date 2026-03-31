#include "Estudiante.h"

void registroCalificaciones() {
    bool seguirBuscando = true;

    while (seguirBuscando) {
        limpiarPantalla();
        cout << "=== REGISTRO DE CALIFICACIONES ===" << endl;

        string cedula;
        cout << "Ingrese la cedula del estudiante: ";
        cin >> cedula;
        cin.ignore(1000, '\n');

        list<Estudiante>::iterator it = buscarEstudiantePorCedula(cedula);

        if (it == listaEstudiantes.end()) {
            cout << "\n[!] No se encontro un estudiante con cedula: " << cedula << endl;
            char resp;
            cout << "Desea ingresar otra cedula? (s/n): ";
            cin >> resp;
            cin.ignore(1000, '\n');
            if (resp != 's' && resp != 'S') {
                seguirBuscando = false;
            }
            continue;
        }

        cout << "\nEstudiante encontrado:" << endl;
        cout << "  Nombres  : " << it->nombres << " " << it->apellidos << endl;
        cout << "  Edad     : " << it->calcularEdad() << " anios" << endl;
        pausar();

        bool gestionNotas = true;
        while (gestionNotas) {
            limpiarPantalla();
            cout << "=== CALIFICACIONES DE: " << it->nombres
                 << " " << it->apellidos << " ===" << endl;

            cout << "\n  Calificaciones registradas:" << endl;
            if (it->notas.empty()) {
                cout << "  (Sin calificaciones)" << endl;
            } else {
                int idx = 1;
                for (list<double>::iterator nit = it->notas.begin();
                     nit != it->notas.end(); ++nit, ++idx) {
                    cout << "  " << setw(3) << idx << ". "
                         << fixed << setprecision(2) << *nit << endl;
                }
            }

            cout << "\n  Opciones:" << endl;
            if ((int)it->notas.size() < MAX_NOTAS) {
                cout << "  1. Insertar calificacion" << endl;
            } else {
                cout << "  [Se han ingresado todas las calificaciones posibles ("
                     << MAX_NOTAS << ")]" << endl;
            }
            if (!it->notas.empty()) {
                cout << "  2. Modificar calificacion" << endl;
                cout << "  3. Eliminar calificacion" << endl;
            }
            cout << "  4. Regresar" << endl;
            cout << "\nTeclee su opcion: ";

            int subOp;
            cin >> subOp;
            cin.ignore(1000, '\n');

            if (subOp == 1) {
                if ((int)it->notas.size() >= MAX_NOTAS) {
                    cout << "[!] Ya se ingresaron todas las calificaciones posibles ("
                         << MAX_NOTAS << "). Proceso terminado." << endl;
                    pausar();
                } else {
                    cout << "\n--- Insertar Calificacion ---" << endl;
                    double nota = leerNota();
                    it->notas.push_back(nota);
                    cout << "[OK] Calificacion agregada." << endl;
                    if ((int)it->notas.size() == MAX_NOTAS) {
                        cout << "[!] Se han ingresado todas las calificaciones posibles. "
                             << "Proceso terminado." << endl;
                        pausar();
                    }
                }
            } else if (subOp == 2) {
                if (it->notas.empty()) {
                    cout << "[!] No hay calificaciones para modificar." << endl;
                    pausar();
                } else {
                    int numNota;
                    cout << "Numero de la calificacion a modificar (1-"
                         << (int)it->notas.size() << "): ";
                    cin >> numNota;
                    cin.ignore(1000, '\n');
                    if (numNota < 1 || numNota > (int)it->notas.size()) {
                        cout << "[!] Numero invalido." << endl;
                        pausar();
                    } else {
                        list<double>::iterator nit = it->notas.begin();
                        for (int i = 1; i < numNota; i++) ++nit;
                        cout << "Calificacion actual: "
                             << fixed << setprecision(2) << *nit << endl;
                        double nuevaNota = leerNota();
                        *nit = nuevaNota;
                        cout << "[OK] Calificacion modificada." << endl;
                    }
                }
            } else if (subOp == 3) {
                if (it->notas.empty()) {
                    cout << "[!] No hay calificaciones para eliminar." << endl;
                    pausar();
                } else {
                    int numNota;
                    cout << "Numero de la calificacion a eliminar (1-"
                         << (int)it->notas.size() << "): ";
                    cin >> numNota;
                    cin.ignore(1000, '\n');
                    if (numNota < 1 || numNota > (int)it->notas.size()) {
                        cout << "[!] Numero invalido." << endl;
                        pausar();
                    } else {
                        list<double>::iterator nit = it->notas.begin();
                        for (int i = 1; i < numNota; i++) ++nit;
                        it->notas.erase(nit);
                        cout << "[OK] Calificacion eliminada." << endl;
                    }
                }
            } else if (subOp == 4) {
                gestionNotas = false;
            } else {
                cout << "[!] Opcion invalida." << endl;
                pausar();
            }
        }

        seguirBuscando = false;
    }
}
