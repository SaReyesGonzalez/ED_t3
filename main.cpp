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
int registro(const vector<NodoServidores*> &vServidores);
void crearGrafo(vector<NodoServidores*>& nodos, vector<AristaConexiones*> aristas);
NodoServidores* encontrarNodoPorId(vector<NodoServidores*> nodos, int idNodo);
void listaNodosConectados(vector<NodoServidores*> nodos, int nodoReferencia);

int main() {

    vector<NodoServidores*> vServidores = lecturaServidores();
    vector<AristaConexiones*> vConexiones = lecturaConexiones();
    crearGrafo(vServidores, vConexiones);

    auto* grafo = new Grafo(vServidores, vConexiones);

    char funcion;
    bool flag;
    int userId;
    int idOrigen;
    int idDestino;

    cout << "Bienvenido a: Simulador - aplicacion de mensajeria !" << endl;

    //Registro
    userId = registro(vServidores);

    // opciones menu
    do {
        cout << "\n----- PANEL DE OPCIONES -----" << endl;
        cout << "A) Calcular tiempo de demora entre usted y un dispositivo destino." << endl; //Funcion basica
        cout << "B) Calcular tiempo de demora entre un dispositivo de origen y destino." << endl; //Funcion extra 1
        cout << "C) Agregar vector." << endl; //Funcion extra 2
        cout << "D) Lista de servidores asociado sobre un punto de referencia." << endl; //Funcion extra 3
        cout << "E) Salir" << endl;

        flag = true;

        cout << "\nIngrese la funcion que desea usar: ";
        cin >> funcion;

        switch (funcion) {

            case 'a':
            case 'A':
                //Esta solo para evitar errores de printeo en la consola
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                idDestino = registro(vServidores);

                grafo->bellmanFord(encontrarNodoPorId(vServidores,userId));
                grafo->calcularTiempoDemoraADestino(userId,idDestino);
                break;

            case 'b':
            case 'B':
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                idOrigen = registro(vServidores);

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                idDestino = registro(vServidores);

                grafo->bellmanFord(encontrarNodoPorId(vServidores,idOrigen));
                grafo->calcularTiempoDemoraADestino(idOrigen,idDestino);

                break;

            case 'c':
            case 'C':
                cout << "FUNCION EXTRA 2" << endl;
                break;

            case 'd':
            case 'D':
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                idOrigen = registro(vServidores);
                listaNodosConectados(vServidores,idOrigen);

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

int registro(const vector<NodoServidores*>& vServidores) {
    int userId;
    string input;
    bool flag;

    do {
        cout << "Ingrese id dispositivo: ";
        getline(cin, input);
        stringstream ss(input);

        // Verifica si la entrada es un entero y si existe como ID de usuario
        if (ss >> userId && !(ss >> input) && existeUsuarioId(userId, vServidores)) {
            flag = true;
        } else {
            cout << "Id inválido o dispositivo no existe, intente nuevamente." << endl;
            flag = false;
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

void listaNodosConectados(vector<NodoServidores*> nodos, int idReferencia) {
    NodoServidores* nodo = encontrarNodoPorId(nodos, idReferencia);

    vector<NodoServidores*> nodosConectados = nodo->getVNodosEnviados();

    cout << "Los servidores conectado a este son: ";
    for (int i = 0; i < nodosConectados.size() ; i++) {
        cout << nodosConectados.at(i)->getId() << " / ";
    }
    cout << endl;

}