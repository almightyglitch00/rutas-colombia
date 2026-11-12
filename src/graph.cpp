#include "../include/graph.h"
#include <iostream>
using namespace std;

Graph::~Graph() {
    while (head) {
        CityNode* tempCity = head;
        head = head->next;
        Edge* e = tempCity->edges;
        while (e) {
            Edge* tempE = e;
            e = e->next;
            delete tempE;
        }
        delete tempCity;
    }
}

bool Graph::existeCiudad(string nombre) {
    CityNode* actual = head;
    while (actual) {
        if (actual->nombre == nombre) return true;
        actual = actual->next;
    }
    return false;
}

bool Graph::agregarCiudad(string nombre) {
    if (existeCiudad(nombre)) return false;
    CityNode* nueva = new CityNode(nombre);
    nueva->next = head;
    head = nueva;
    return true;
}

bool Graph::agregarConexion(string origen, string destino, double distancia) {
    if (distancia <= 0) return false;
    if (!existeCiudad(origen) || !existeCiudad(destino)) return false;
    if (origen == destino) return false;

    CityNode* ciudad = head;
    while (ciudad && ciudad->nombre != origen) ciudad = ciudad->next;
    if (!ciudad) return false;

    Edge* e = ciudad->edges;
    while (e) {
        if (e->destino == destino) return false;
        e = e->next;
    }

    Edge* nueva = new Edge(destino, distancia);
    nueva->next = ciudad->edges;
    ciudad->edges = nueva;
    return true;
}

bool Graph::eliminarConexion(string origen, string destino) {
    CityNode* ciudad = head;
    while (ciudad && ciudad->nombre != origen) ciudad = ciudad->next;
    if (!ciudad || !ciudad->edges) return false;

    if (ciudad->edges->destino == destino) {
        Edge* temp = ciudad->edges;
        ciudad->edges = temp->next;
        delete temp;
        return true;
    }
    Edge* actual = ciudad->edges;
    while (actual->next && actual->next->destino != destino)
        actual = actual->next;
    if (actual->next) {
        Edge* temp = actual->next;
        actual->next = temp->next;
        delete temp;
        return true;
    }
    return false;
}

void Graph::mostrarVecinos(string ciudad) {
    CityNode* c = head;
    while (c && c->nombre != ciudad) c = c->next;
    if (!c) {
        cout << "Ciudad no encontrada.\n";
        return;
    }
    cout << "Vecinos de " << ciudad << ":\n";
    if (!c->edges) {
        cout << "  (sin conexiones)\n";
        return;
    }
    Edge* e = c->edges;
    while (e) {
        cout << "  -> " << e->destino << " (" << e->distancia << " km)\n";
        e = e->next;
    }
}

void Graph::listarCiudades() {
    if (!head) {
        cout << "No hay ciudades registradas.\n";
        return;
    }
    cout << "\n=== CIUDADES ===\n";
    CityNode* actual = head;
    while (actual) {
        cout << "- " << actual->nombre << endl;
        actual = actual->next;
    }
}

bool Graph::eliminarCiudad(string nombre) {
    if (!existeCiudad(nombre)) return false;
    CityNode* c = head;
    while (c) {
        eliminarConexion(c->nombre, nombre);
        c = c->next;
    }
    if (head->nombre == nombre) {
        CityNode* temp = head;
        head = head->next;
        Edge* e = temp->edges;
        while (e) {
            Edge* t = e;
            e = e->next;
            delete t;
        }
        delete temp;
        return true;
    }
    CityNode* actual = head;
    while (actual->next && actual->next->nombre != nombre)
        actual = actual->next;
    if (actual->next) {
        CityNode* temp = actual->next;
        actual->next = temp->next;
        Edge* e = temp->edges;
        while (e) {
            Edge* t = e;
            e = e->next;
            delete t;
        }
        delete temp;
        return true;
    }
    return false;
}
