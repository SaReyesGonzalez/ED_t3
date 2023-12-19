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
int registro(bool flag, int userId, const vector<NodoServidores*>& vServidores);

int main() {

    vector<NodoServidores*> vServidores = lecturaServidores();
    vector<AristaConexiones*> vConexiones = lecturaConexiones();
    auto* grafo = new Grafo(vServidores, vConexiones);

    char funcion;
    int userId = 0;
    bool flag = true;

    cout << "Bienvenido a: Simulador - aplicacion de mensajeria !" << endl;

    //Registro
    userId = registro(flag,userId,vServidores);

    // opciones menu
    do {
        cout << "\n----- PANEL DE OPCIONES -----" << endl;
        cout << "A) Calcular tiempo de demora entre usted y un destino." << endl; //Funcion basica
        cout << "B) Calcular tiempo de demora entre un origen y destino." << endl; //Funcion extra 1
        cout << "C) Funcion extra 2" << endl;
        cout << "D) Funcion extra 3" << endl;
        cout << "E) Salir" << endl;

        flag = true;

        cout << "\nIngrese la funcion que desea usar: ";
        cin >> funcion;

        switch (funcion) {

            case 'a':
            case 'A':
                cout << "a" << endl;
                break;

            case 'b':
            case 'B':
                cout << "b" << endl;
                break;

            case 'c':
            case 'C':
                cout << "c" << endl;
                break;

            case 'd':
            case 'D':
                cout << "d" << endl;
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
        flag = true;

        cout << "Ingrese su id de usuario: ";
        cin >> userId;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        flag = existeUsuarioId(userId,vServidores);

        if (!flag) {
            cout << "Id usuario no existe, ingrese un id nuevamente." << endl;
        }

    } while (!flag);

    return userId;
}