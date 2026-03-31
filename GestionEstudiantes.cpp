#include "Estudiante.h"

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

        list<Estudiante>::iterator it = listaEstudiantes.begin();
        for (int i = 1; i < num; i++) ++it;

        cout << "\nConfirma eliminar a " << it->nombres
             << " " << it->apellidos << "? (s/n): ";
        char conf;
        cin >> conf;
        cin.ignore(1000, '\n');

        if (conf == 's' || conf == 'S') {
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
