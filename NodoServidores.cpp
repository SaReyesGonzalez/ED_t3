#include "NodoServidores.h"

NodoServidores::NodoServidores() {

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

