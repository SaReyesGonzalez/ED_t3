#include "Grafo.h"

Grafo::Grafo(vector<NodoServidores*> nodos, vector<AristaConexiones*> aristas) {
    Grafo::nodos = nodos;
    Grafo::aristas = aristas;
}

const vector<NodoServidores*> &Grafo::getNodos() const {
    return nodos;
}

const vector<AristaConexiones*> &Grafo::getAristas() const {
    return aristas;
}
