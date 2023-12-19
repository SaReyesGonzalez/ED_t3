#include "NodoServidores.h"

#include <utility>

NodoServidores::NodoServidores(int id, string nombre, string tipo) {
    NodoServidores::id = id;
    NodoServidores::nombre = std::move(nombre);
    NodoServidores::tipo = std::move(tipo);
    NodoServidores::vNodosEnviados = {};
}

int NodoServidores::getId() const {
    return id;
}

const string &NodoServidores::getNombre() const {
    return nombre;
}

const string &NodoServidores::getTipo() const {
    return tipo;
}

vector<NodoServidores*> &NodoServidores::getVNodosEnviados() {
    return vNodosEnviados;
}
