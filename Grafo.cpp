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

    int peso;
    cout << "Ingrese el peso del archivo que desea enviar ";
    cin >> peso;

    int partes;
    partes = peso / MB_MAXIMOS;




}

void Grafo::bellmanFord(int idOrigen, int idDestino) {

    NodoServidores* nodoOrigen = encontrarNodoPorId(idOrigen);
    NodoServidores* nodoDestino = encontrarNodoPorId(idDestino);





}

NodoServidores *Grafo::encontrarNodoPorId(int idNodo) {

    for (int i = 0; i < nodos.size() ; i++) {
        if (nodos.at(i)->getId() == idNodo) {
            return nodos.at(i);
        }
    }

    return nullptr;
}

