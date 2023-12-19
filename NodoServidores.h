#ifndef ED_T3_NODOSERVIDORES_H
#define ED_T3_NODOSERVIDORES_H

#include <string>
#include <vector>

using namespace std;

class NodoServidores {

private:
    int id;
    string nombre;
    string tipo;
    vector<NodoServidores*> vNodosEnviados;

public:
    NodoServidores(int id, string nombre, string tipo);

    int getId() const;

    const string &getNombre() const;

    const string &getTipo() const;

    vector<NodoServidores*> &getVNodosEnviados();


};


#endif //ED_T3_NODOSERVIDORES_H
