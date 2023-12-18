#ifndef ED_T3_NODOSERVIDORES_H
#define ED_T3_NODOSERVIDORES_H

#include <string>

using namespace std;

class NodoServidores {

private:
    int id;
    string nombre;
    string tipo;

public:
    NodoServidores(int id, string nombre, string tipo);

    int getId() const;

    const string &getNombre() const;

    const string &getTipo() const;



};


#endif //ED_T3_NODOSERVIDORES_H
