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

void Grafo::calcularTiempoDemoraADestino(int idOrigen, int idDestino) {

    NodoServidores* nodoOrigen = encontrarNodoPorId(idOrigen);
    NodoServidores* nodoDestino = encontrarNodoPorId(idDestino);
    NodoServidores* nodoAux = nullptr;

    bellmanFord(nodoOrigen);

    int peso;
    int partes;
    int tiempoTotal = 0;
    vector<NodoServidores*> ruta;

    ruta.push_back(nodoDestino);

    cout << "Ingrese el peso del archivo que desea enviar: ";
    cin >> peso;

    do {
        nodoAux = nodoDestino->getNodoCaminoMasCorto();

        AristaConexiones* auxArista = encontrarAristaPorIds(nodoDestino->getId(), nodoAux->getId());

        int mbMaximos = auxArista->getVelocidad();
        int distancia = auxArista->getDistancia();
        partes = peso / mbMaximos;

        tiempoTotal = tiempoTotal + (partes * distancia);

        ruta.push_back(nodoAux);

        nodoDestino = nodoAux;
        nodoAux = nodoAux->getNodoCaminoMasCorto();

    } while (nodoDestino != nodoOrigen);

    cout << "El tiempo de entrega entre el nodo " << idOrigen <<
    " y el nodo " << idDestino << " es de " << tiempoTotal << " segundos." << endl;

}

void Grafo::bellmanFord(NodoServidores* nodoOrigen) {

    //Inicializacion
    for (auto &nodo : nodos) {
        int distancia = (nodo == nodoOrigen) ? 0 : numeric_limits<int>::max();
        nodo->setDistanciaMasCorta(distancia);
        nodo->setNodoCaminoMasCorto(nullptr);
    }

    //Relajacion
    for (auto &nodo : nodos) {

        if (nodo->getVNodosEnviados().size() == 1 && nodo->getTipo() == "cliente\r") {

            NodoServidores* routerConectado = nodo->getVNodosEnviados().front();
            AristaConexiones* arista = encontrarAristaPorIds(nodo->getId(), routerConectado->getId());

            if (arista) {  // Asegurémonos de que la arista exista
                nodo->setNodoCaminoMasCorto(routerConectado);
                nodo->setDistanciaMasCorta(arista->getDistancia());
            }

        }
    }

    for (int i = 1; i <= nodos.size() - 1; i++) {
        for (auto &arista : aristas) {
            int idCliente = arista->getIdCliente();
            int idServidor = arista->getIdServidor();
            int distancia = arista->getDistancia();

            NodoServidores* u = encontrarNodoPorId(idCliente);
            NodoServidores* v = encontrarNodoPorId(idServidor);

            if (u->getDistanciaMasCorta() != numeric_limits<int>::max() &&
                u->getDistanciaMasCorta() + distancia < v->getDistanciaMasCorta()) {

                v->setDistanciaMasCorta(u->getDistanciaMasCorta() + distancia);
                v->setNodoCaminoMasCorto(u);
            }
        }
    }
}

NodoServidores* Grafo::encontrarNodoPorId(int idNodo) {

    for (int i = 0; i < aristas.size() ; i++) {
        if (nodos.at(i)->getId() == idNodo) {
            return nodos.at(i);
        }
    }

    return nullptr;
}

AristaConexiones* Grafo::encontrarAristaPorIds(int idNodo1, int idNodo2) {
    for (auto &arista : aristas) {
        if ((arista->getIdCliente() == idNodo1 && arista->getIdServidor() == idNodo2) ||
            (arista->getIdCliente() == idNodo2 && arista->getIdServidor() == idNodo1)) {
            return arista;
        }
    }
    return nullptr;  // Si no se encuentra ninguna arista entre los dos nodos
}
