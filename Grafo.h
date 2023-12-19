#ifndef ED_T3_GRAFO_H
#define ED_T3_GRAFO_H

#include "AristaConexiones.h"
#include "NodoServidores.h"
#include <vector>

class Grafo {

private:
    vector<NodoServidores*> nodos;
    vector<AristaConexiones*> aristas;

public:
    Grafo(vector<NodoServidores*> nodos, vector<AristaConexiones*> aristas);

    const vector<NodoServidores *> &getNodos() const;

    const vector<AristaConexiones *> &getAristas() const;


};


#endif //ED_T3_GRAFO_H
