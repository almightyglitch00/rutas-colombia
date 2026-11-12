#include "../include/queue.h"
#include <iostream>
using namespace std;

ColaSolicitudes::~ColaSolicitudes() {
    while (front) {
        SolicitudNode* temp = front;
        front = front->next;
        delete temp;
    }
}

void ColaSolicitudes::encolar(string id, string origen, string destino) {
    SolicitudNode* nuevo = new SolicitudNode(id, origen, destino);
    if (!rear) {
        front = rear = nuevo;
    } else {
        rear->next = nuevo;
        rear = nuevo;
    }
    cout << "Solicitud encolada.\n";
}

bool ColaSolicitudes::atender() {
    if (!front) return false;
    SolicitudNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    cout << "Atendida solicitud de " << temp->idPasajero 
         << " (" << temp->origen << " -> " << temp->destino << ")\n";
    delete temp;
    return true;
}

void ColaSolicitudes::mostrarFrente() {
    if (!front) {
        cout << "Cola vacía.\n";
        return;
    }
    cout << "Frente: " << front->idPasajero 
         << " | " << front->origen << " -> " << front->destino << endl;
}

bool ColaSolicitudes::estaVacia() {
    return front == nullptr;
}

void ColaSolicitudes::mostrarCola() {
    if (!front) {
        cout << "Cola vacía.\n";
        return;
    }
    cout << "\n=== COLA DE SOLICITUDES ===\n";
    SolicitudNode* actual = front;
    int i = 1;
    while (actual) {
        cout << i++ << ". " << actual->idPasajero 
             << " (" << actual->origen << " -> " << actual->destino << ")\n";
        actual = actual->next;
    }
}
