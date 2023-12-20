#include "NodoServidores.h"

#include <utility>

NodoServidores::NodoServidores(int id, string nombre, string tipo) {
    NodoServidores::id = id;
    NodoServidores::nombre = std::move(nombre);
    NodoServidores::tipo = std::move(tipo);
    NodoServidores::distanciaMasCorta = 999999;
    NodoServidores::nodoCaminoMasCorto = nullptr;
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

NodoServidores *NodoServidores::getNodoCaminoMasCorto() const {
    return nodoCaminoMasCorto;
}

vector<NodoServidores*> &NodoServidores::getVNodosEnviados() {
    return vNodosEnviados;
}

void NodoServidores::setNodoCaminoMasCorto(NodoServidores *nodoCaminoMasCorto) {
    NodoServidores::nodoCaminoMasCorto = nodoCaminoMasCorto;
}

int NodoServidores::getDistanciaMasCorta() const {
    return distanciaMasCorta;
}

void NodoServidores::setDistanciaMasCorta(int distanciaMasCorta) {
    NodoServidores::distanciaMasCorta = distanciaMasCorta;
}
