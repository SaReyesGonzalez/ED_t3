#ifndef ED_T3_GRAFO_H
#define ED_T3_GRAFO_H

#include "AristaConexiones.h"
#include "NodoServidores.h"
#include <iostream>
#include <vector>

using namespace std;

const int MB_MAXIMOS = 300;

class Grafo {

private:
    vector<NodoServidores*> nodos;
    vector<AristaConexiones*> aristas;

public:
    Grafo(vector<NodoServidores*> nodos, vector<AristaConexiones*> aristas);

    const vector<NodoServidores*> &getNodos() const;

    const vector<AristaConexiones*> &getAristas() const;

    void calcularTiempoDemoraADestino(int idOrigen, int idDestino);
};


#endif //ED_T3_GRAFO_H
