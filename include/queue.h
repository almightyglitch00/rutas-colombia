#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct SolicitudNode {
    string idPasajero;
    string origen;
    string destino;
    SolicitudNode* next;
    SolicitudNode(string id, string o, string d) : idPasajero(id), origen(o), destino(d), next(nullptr) {}
};

class ColaSolicitudes {
private:
    SolicitudNode* front;
    SolicitudNode* rear;
public:
    ColaSolicitudes() : front(nullptr), rear(nullptr) {}
    ~ColaSolicitudes();
    void encolar(string id, string origen, string destino);
    bool atender();
    void mostrarFrente();
    bool estaVacia();
    void mostrarCola();
};

#endif
