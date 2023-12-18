#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "NodoServidores.h"
#include "AristaConexiones.h"

using namespace std;

vector<NodoServidores*> lecturaServidores();
vector<AristaConexiones*> lecturaConexiones();

int main() {

    vector<NodoServidores*> vServidores = lecturaServidores();
    vector<AristaConexiones*> vConexiones = lecturaConexiones();

    return 0;
}


vector<NodoServidores*> lecturaServidores() {
    ifstream archivo("/home/sebastian/Programacion/C++/ED_t3/servidores.csv");

    if (archivo.is_open()) {

        vector<NodoServidores *> datos;
        string linea;

        while (getline(archivo, linea)) {
            istringstream ss(linea);
            vector<string> fila;
            string token;

            while (getline(ss, token, ',')) {
                fila.push_back(token);
            }

            int id = stoi(fila[0]);
            string nombre = fila[1];
            string tipo = fila[2];

            auto *nodo = new NodoServidores(id, nombre, tipo);
            datos.push_back(nodo);
        }

        archivo.close();
        return datos;

    } else {
        cerr << "Error al abrir archivo CSV." << endl;
        return {};
    }
}

vector<AristaConexiones*> lecturaConexiones() {
    ifstream archivo("/home/sebastian/Programacion/C++/ED_t3/conexiones.csv");

    if (archivo.is_open()) {
        vector<AristaConexiones*> datos;
        string linea;

        while (getline(archivo, linea)) {
            istringstream ss(linea);
            vector<string> fila;
            string token;

            while (getline(ss, token, ',')) {
                fila.push_back(token);
            }

            int idCliente = stoi(fila[0]);
            int idServidor = stoi(fila[1]);
            int velocidad = stoi(fila[2]);
            int distancia = stoi(fila[3]);

            auto *arista = new AristaConexiones(idCliente, idServidor, velocidad, distancia);
            datos.push_back(arista);
        }

        archivo.close();
        return datos;

    } else {
        cerr << "Error al abrir archivo CSV." << endl;
        return {};
    }
}