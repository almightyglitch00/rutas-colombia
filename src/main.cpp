#include <iostream>
#include <string>
#include <limits>
#include "../include/passenger.h"
#include "../include/graph.h"
#include "../include/queue.h"

using namespace std;

LinkedListPasajeros listaPasajeros;
Graph grafo;
ColaSolicitudes cola;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero() {
    int op;
    while (!(cin >> op)) {
        cout << "Entrada inválida. Ingrese un número: ";
        limpiarBuffer();
    }
    limpiarBuffer();
    return op;
}

double leerDouble() {
    double d;
    while (!(cin >> d)) {
        cout << "Entrada inválida. Ingrese un número: ";
        limpiarBuffer();
    }
    limpiarBuffer();
    return d;
}

void menuCiudades() {
    int op;
    do {
        cout << "\n--- GESTIÓN DE CIUDADES ---\n";
        cout << "1. Agregar ciudad\n";
        cout << "2. Listar ciudades\n";
        cout << "3. Ver vecinos de una ciudad\n";
        cout << "4. Eliminar ciudad\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        op = leerEntero();

        string nombre;
        switch (op) {
            case 1:
                cout << "Nombre de la ciudad: ";
                getline(cin, nombre);
                if (grafo.agregarCiudad(nombre))
                    cout << "Ciudad agregada.\n";
                else
                    cout << "Ciudad ya existe o nombre inválido.\n";
                break;
            case 2:
                grafo.listarCiudades();
                break;
            case 3:
                cout << "Ciudad: ";
                getline(cin, nombre);
                grafo.mostrarVecinos(nombre);
                break;
            case 4:
                cout << "Ciudad a eliminar: ";
                getline(cin, nombre);
                if (grafo.eliminarCiudad(nombre))
                    cout << "Ciudad eliminada (conexiones limpiadas).\n";
                else
                    cout << "No se pudo eliminar.\n";
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuRutas() {
    int op;
    do {
        cout << "\n--- GESTIÓN DE RUTAS / CONEXIONES ---\n";
        cout << "1. Agregar conexión\n";
        cout << "2. Eliminar conexión\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        op = leerEntero();

        string origen, destino;
        double dist;
        switch (op) {
            case 1:
                cout << "Origen: "; getline(cin, origen);
                cout << "Destino: "; getline(cin, destino);
                cout << "Distancia (km): "; dist = leerDouble();
                if (grafo.agregarConexion(origen, destino, dist))
                    cout << "Conexión agregada.\n";
                else
                    cout << "Error: ciudades no existen, distancia <=0 o conexión duplicada.\n";
                break;
            case 2:
                cout << "Origen: "; getline(cin, origen);
                cout << "Destino: "; getline(cin, destino);
                if (grafo.eliminarConexion(origen, destino))
                    cout << "Conexión eliminada.\n";
                else
                    cout << "Conexión no encontrada.\n";
                break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuPasajeros() {
    int op;
    do {
        cout << "\n--- GESTIÓN DE PASAJEROS ---\n";
        cout << "1. Registrar pasajero\n";
        cout << "2. Buscar pasajero\n";
        cout << "3. Actualizar pasajero\n";
        cout << "4. Eliminar pasajero\n";
        cout << "5. Listar pasajeros\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        op = leerEntero();

        string id, nombre, destino;
        switch (op) {
            case 1:
                cout << "ID: "; getline(cin, id);
                cout << "Nombre: "; getline(cin, nombre);
                cout << "Destino preferido: "; getline(cin, destino);
                if (listaPasajeros.insertar(id, nombre, destino))
                    cout << "Pasajero registrado.\n";
                else
                    cout << "ID ya existe.\n";
                break;
            case 2:
                cout << "ID a buscar: "; getline(cin, id);
                if (PassengerNode* p = listaPasajeros.buscar(id))
                    cout << "Encontrado: " << p->nombre << " -> " << p->destino << endl;
                else
                    cout << "No encontrado.\n";
                break;
            case 3:
                cout << "ID: "; getline(cin, id);
                cout << "Nuevo nombre: "; getline(cin, nombre);
                cout << "Nuevo destino: "; getline(cin, destino);
                if (listaPasajeros.actualizar(id, nombre, destino))
                    cout << "Actualizado.\n";
                else
                    cout << "No encontrado.\n";
                break;
            case 4:
                cout << "ID a eliminar: "; getline(cin, id);
                if (listaPasajeros.eliminar(id))
                    cout << "Eliminado.\n";
                else
                    cout << "No encontrado.\n";
                break;
            case 5:
                listaPasajeros.listar();
                break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuCola() {
    int op;
    do {
        cout << "\n--- COLA DE SOLICITUDES ---\n";
        cout << "1. Encolar solicitud\n";
        cout << "2. Atender (desencolar)\n";
        cout << "3. Ver frente\n";
        cout << "4. Mostrar toda la cola\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        op = leerEntero();

        string id, origen, destino;
        switch (op) {
            case 1:
                cout << "ID Pasajero: "; getline(cin, id);
                cout << "Origen: "; getline(cin, origen);
                cout << "Destino: "; getline(cin, destino);
                cola.encolar(id, origen, destino);
                break;
            case 2:
                if (!cola.atender())
                    cout << "Cola vacía. No se puede atender.\n";
                break;
            case 3:
                cola.mostrarFrente();
                break;
            case 4:
                cola.mostrarCola();
                break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuPlaceholder(const string& nombre) {
    cout << "\n[" << nombre << "] Módulo en construcción / pendiente.\n";
    cout << "Presione Enter para volver...";
    cin.get();
}

int main() {
    int op;
    cout << "=== SITRAC - Sistema Inteligente de Transporte y Gestión de Rutas ===\n";
    cout << "Estructura de Datos - 2026-II\n";

    do {
        cout << "\n========== MENÚ PRINCIPAL ==========\n";
        cout << "1. Ciudades\n";
        cout << "2. Rutas / Conexiones\n";
        cout << "3. Pasajeros\n";
        cout << "4. Cola de solicitudes\n";
        cout << "5. Historial\n";
        cout << "6. Búsquedas\n";
        cout << "7. Reportes\n";
        cout << "8. Guardar / Cargar\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        op = leerEntero();

        switch (op) {
            case 1: menuCiudades(); break;
            case 2: menuRutas(); break;
            case 3: menuPasajeros(); break;
            case 4: menuCola(); break;
            case 5: menuPlaceholder("Historial (Pila)"); break;
            case 6: menuPlaceholder("Búsquedas (Árbol)"); break;
            case 7: menuPlaceholder("Reportes"); break;
            case 8: menuPlaceholder("Guardar / Cargar"); break;
            case 0: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (op != 0);

    return 0;
}
