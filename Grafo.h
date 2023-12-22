#ifndef ED_T3_GRAFO_H
#define ED_T3_GRAFO_H

#include "AristaConexiones.h"
#include "NodoServidores.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Grafo {

private:
    vector<NodoServidores*> nodos;
    vector<AristaConexiones*> aristas;

public:
    Grafo(vector<NodoServidores*> nodos, vector<AristaConexiones*> aristas);

    const vector<NodoServidores*> &getNodos() const;

    const vector<AristaConexiones*> &getAristas() const;

    void calcularTiempoDemoraADestino(int idOrigen, int idDestino);

    void bellmanFord(NodoServidores* nodoOrigen);

    NodoServidores* encontrarNodoPorId(int idNodo);

    AristaConexiones* encontrarAristaPorIds(int idNodoOrigen, int idNodoDestino);
};


#endif //ED_T3_GRAFO_H
