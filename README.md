# SITRAC - Sistema Inteligente de Transporte y Gestión de Rutas

Proyecto de aula - Estructura de Datos (2026-II)

## Integrantes
- Santiago Ramirez
- Steven Monsalve

## Compilación

```bash
g++ -std=c++17 src/main.cpp src/passenger.cpp src/graph.cpp src/queue.cpp -o sitrac
./sitrac
```

O con Makefile:

```bash
make run
```

## Estructuras implementadas (propias, sin STL)

- **Lista enlazada** de pasajeros (`LinkedListPasajeros`)
- **Grafo** con lista de adyacencia propia (`Graph`)
- **Cola enlazada** de solicitudes (`ColaSolicitudes`)

## Funcionalidades

- Menú principal persistente + submenús con opción Volver
- Gestión completa de ciudades, conexiones, pasajeros y cola
- Manejo de errores: duplicados, distancias negativas, cola vacía, entradas inválidas

## Uso de IA

Se consultó asistencia de IA (Grok) para estructurar el código base y las estructuras propias.  
El código fue revisado y adaptado manualmente.

## Pendientes

- Pila de historial
- Árbol de búsquedas
- Reportes
- Persistencia (guardar/cargar en archivo)
