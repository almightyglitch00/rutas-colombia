#include "../include/passenger.h"
#include <iostream>
using namespace std;

LinkedListPasajeros::~LinkedListPasajeros() {
    while (head) {
        PassengerNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedListPasajeros::insertar(string id, string nombre, string destino) {
    if (buscar(id)) return false;
    PassengerNode* nuevo = new PassengerNode(id, nombre, destino);
    nuevo->next = head;
    head = nuevo;
    return true;
}

bool LinkedListPasajeros::eliminar(string id) {
    if (!head) return false;
    if (head->id == id) {
        PassengerNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    PassengerNode* actual = head;
    while (actual->next && actual->next->id != id)
        actual = actual->next;
    if (actual->next) {
        PassengerNode* temp = actual->next;
        actual->next = temp->next;
        delete temp;
        return true;
    }
    return false;
}

PassengerNode* LinkedListPasajeros::buscar(string id) {
    PassengerNode* actual = head;
    while (actual) {
        if (actual->id == id) return actual;
        actual = actual->next;
    }
    return nullptr;
}

bool LinkedListPasajeros::actualizar(string id, string nuevoNombre, string nuevoDestino) {
    PassengerNode* p = buscar(id);
    if (!p) return false;
    p->nombre = nuevoNombre;
    p->destino = nuevoDestino;
    return true;
}

void LinkedListPasajeros::listar() {
    if (!head) {
        cout << "No hay pasajeros registrados.\n";
        return;
    }
    PassengerNode* actual = head;
    cout << "\n=== LISTA DE PASAJEROS ===\n";
    while (actual) {
        cout << "ID: " << actual->id 
             << " | Nombre: " << actual->nombre 
             << " | Destino: " << actual->destino << endl;
        actual = actual->next;
    }
}

bool LinkedListPasajeros::estaVacia() {
    return head == nullptr;
}
