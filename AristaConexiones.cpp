#include "AristaConexiones.h"

AristaConexiones::AristaConexiones(int idCliente, int idServidor, int velocidad, int distancia) {
    AristaConexiones::idCliente = idCliente;
    AristaConexiones::idServidor = idServidor;
    AristaConexiones::velocidad = velocidad;
    AristaConexiones::distancia = distancia;
}

int AristaConexiones::getIdCliente() const {
    return idCliente;
}

int AristaConexiones::getIdServidor() const {
    return idServidor;
}

int AristaConexiones::getVelocidad() const {
    return velocidad;
}

int AristaConexiones::getDistancia() const {
    return distancia;
}


