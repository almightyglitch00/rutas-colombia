#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

struct PassengerNode {
    string id;
    string nombre;
    string destino;
    PassengerNode* next;
    PassengerNode(string i, string n, string d) : id(i), nombre(n), destino(d), next(nullptr) {}
};

class LinkedListPasajeros {
private:
    PassengerNode* head;
public:
    LinkedListPasajeros() : head(nullptr) {}
    ~LinkedListPasajeros();
    bool insertar(string id, string nombre, string destino);
    bool eliminar(string id);
    PassengerNode* buscar(string id);
    bool actualizar(string id, string nuevoNombre, string nuevoDestino);
    void listar();
    bool estaVacia();
};

#endif
