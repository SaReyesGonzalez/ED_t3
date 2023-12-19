#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include "NodoServidores.h"
#include "AristaConexiones.h"
#include "Grafo.h"

using namespace std;

vector<NodoServidores*> lecturaServidores();
vector<AristaConexiones*> lecturaConexiones();
bool existeUsuarioId(int user, vector<NodoServidores*> vServidores);
int registro(bool flag, int userId, const vector<NodoServidores*> &vServidores);
void crearGrafo(vector<NodoServidores*>& nodos, vector<AristaConexiones*> aristas);
NodoServidores* encontrarNodoPorId(vector<NodoServidores*> nodos, int idNodo);

int main() {

    vector<NodoServidores*> vServidores = lecturaServidores();
    vector<AristaConexiones*> vConexiones = lecturaConexiones();
    crearGrafo(vServidores, vConexiones);

    auto* grafo = new Grafo(vServidores, vConexiones);

    char funcion;
    bool flag = true;
    int userId = 0;
    int idOrigen = 0;
    int idDestino = 0;

    cout << "Bienvenido a: Simulador - aplicacion de mensajeria !" << endl;

    //Registro
    userId = registro(flag,userId,vServidores);

    // opciones menu
    do {
        cout << "\n----- PANEL DE OPCIONES -----" << endl;
        cout << "A) Calcular tiempo de demora entre usted y un dispositivo destino." << endl; //Funcion basica
        cout << "B) Calcular tiempo de demora entre un dispositivo de origen y destino." << endl; //Funcion extra 1
        cout << "C) Agregar vector." << endl; //Funcion extra 2
        cout << "D) Lista de Vectores y aristas." << endl; //Funcion extra 3
        cout << "E) Salir" << endl;

        flag = true;

        cout << "\nIngrese la funcion que desea usar: ";
        cin >> funcion;

        switch (funcion) {

            case 'a':
            case 'A':
                idDestino = registro(flag,idDestino,vServidores);
                grafo->calcularTiempoDemoraADestino(userId,idDestino);

                break;

            case 'b':
            case 'B':
                idOrigen = registro(flag,idOrigen,vServidores);
                idDestino = registro(flag,idDestino,vServidores);
                grafo->calcularTiempoDemoraADestino(idOrigen,idDestino);

                break;

            case 'c':
            case 'C':
                cout << "FUNCION EXTRA 2" << endl;
                break;

            case 'd':
            case 'D':
                cout << "FUNCION EXTRA 3" << endl;
                break;

            case 'e':
            case 'E':
                cout << "\nHasta luego, vuelva pronto." << endl;
                flag = false;
                break;

            default:
                cout << "Opcion invalida. Pruebe nuevamente." << endl;
        }

    } while(flag);

    return 0;
}


vector<NodoServidores*> lecturaServidores() {
    ifstream archivo("/home/sebastian/Programacion/C++/ED_t3/servidores.csv");

    if (archivo.is_open()) {

        vector<NodoServidores *> datos;
        string linea;
        getline(archivo, linea);

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
        getline(archivo, linea);

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

bool existeUsuarioId(int userId, vector<NodoServidores*> vServidores) {

    for (int i = 0 ; i < vServidores.size() ; i++) {
        if (userId == vServidores.at(i)->getId()) {
            return true;
        }
    }

    return false;
}

int registro(bool flag, int userId, const vector<NodoServidores*>& vServidores) {
    do {
        cout << "Ingrese su id dispositivo: ";
        cin >> userId;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        flag = existeUsuarioId(userId,vServidores);

        if (!flag) {
            cout << "Id dispositivo no existe, ingrese un id nuevamente." << endl;
        }

    } while (!flag);

    return userId;
}

void crearGrafo(vector<NodoServidores*>& nodos, vector<AristaConexiones*> aristas) {

    for (int i = 0 ; i < aristas.size() ; i++) {

        int auxIdOrigen = aristas.at(i)->getIdCliente();
        int auxIdDestino = aristas.at(i)->getIdServidor();

        NodoServidores* auxNodoOrigen = encontrarNodoPorId(nodos, auxIdOrigen);
        NodoServidores* auxNodoDestino = encontrarNodoPorId(nodos,auxIdDestino);

        auxNodoOrigen->getVNodosEnviados().push_back(auxNodoDestino);
        auxNodoDestino->getVNodosEnviados().push_back(auxNodoOrigen);
    }
}

NodoServidores* encontrarNodoPorId(vector<NodoServidores*> nodos, int idNodo) {

    for (int i = 0; i < nodos.size() ; i++) {
        if (nodos.at(i)->getId() == idNodo) {
            return nodos.at(i);
        }
    }
    return nullptr;
}