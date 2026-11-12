#ifndef GRAPH_H
#define GRAPH_H

#include <string>
using namespace std;

struct Edge {
    string destino;
    double distancia;
    Edge* next;
    Edge(string d, double dist) : destino(d), distancia(dist), next(nullptr) {}
};

struct CityNode {
    string nombre;
    Edge* edges;
    CityNode* next;
    CityNode(string n) : nombre(n), edges(nullptr), next(nullptr) {}
};

class Graph {
private:
    CityNode* head;
public:
    Graph() : head(nullptr) {}
    ~Graph();
    bool agregarCiudad(string nombre);
    bool existeCiudad(string nombre);
    bool agregarConexion(string origen, string destino, double distancia);
    bool eliminarConexion(string origen, string destino);
    void mostrarVecinos(string ciudad);
    void listarCiudades();
    bool eliminarCiudad(string nombre);
};

#endif
