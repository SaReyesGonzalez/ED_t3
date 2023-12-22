# Documentación de Proyecto 

## Comando de compilacion
- g++ -o main main.cpp NodoServidores.cpp AristaConexiones.cpp Grafo.cpp

## Descripción General
Este proyecto implementa un simulador de aplicación de mensajería utilizando un algoritmo de Bellman-Ford para calcular la ruta más corta en una red de nodos que representan servidores y clientes. El objetivo es determinar el tiempo de demora para la entrega de mensajes entre diferentes dispositivos en la red.

## Estructura del Proyecto

### Clases Principales

#### NodoServidores
- **Descripción**: Representa los nodos individuales en la red, que pueden ser servidores o clientes.
- **Atributos Principales**:
    - `id`: Identificador único del nodo.
    - `nombre`: Nombre descriptivo del nodo.
    - `tipo`: Tipo del nodo (cliente o router).
    - `distanciaMasCorta`: La distancia más corta calculada desde un nodo origen.
    - `nodoCaminoMasCorto`: Apunta al nodo anterior en el camino más corto.
    - `vNodosEnviados`: Vector de nodos a los que este nodo está directamente conectado.
- **Métodos Principales**:
    - Constructores, getters y setters para los atributos mencionados.

#### AristaConexiones
- **Descripción**: Representa las aristas en la red, es decir, las conexiones entre dos nodos.
- **Atributos Principales**:
    - `idCliente`: ID del nodo cliente en la conexión.
    - `idServidor`: ID del nodo servidor (o router) en la conexión.
    - `velocidad`: Velocidad de la conexión.
    - `distancia`: Distancia o tiempo de demora asociado con la conexión.
- **Métodos Principales**:
    - Constructores, getters para los atributos mencionados.

#### Grafo
- **Descripción**: Gestiona la red completa, incluyendo todos los nodos y aristas, y la lógica para calcular rutas más cortas.
- **Atributos Principales**:
    - `nodos`: Vector de todos los nodos (`NodoServidores`) en la red.
    - `aristas`: Vector de todas las aristas (`AristaConexiones`) en la red.
- **Métodos Principales**:
    - `calcularTiempoDemoraADestino`: Calcula y muestra el tiempo total para enviar un mensaje del nodo origen al nodo destino.
    - `bellmanFord`: Implementa el algoritmo de Bellman-Ford para calcular la ruta más corta desde un nodo origen a todos los demás nodos.

### Algoritmo de Bellman-Ford
El algoritmo de Bellman-Ford se utiliza para calcular la ruta más corta en la red. Este algoritmo es especialmente útil en redes donde las rutas y las distancias varían, y es capaz de manejar pesos negativos en las aristas.

### Funciones Adicionales
- `lecturaServidores`: Lee y carga los nodos desde un archivo CSV.
- `lecturaConexiones`: Lee y carga las aristas desde un archivo CSV.
- `crearGrafo`: Construye la red conectando nodos a través de aristas basadas en los datos leídos.
- `registro`: Registra o verifica la existencia de un ID de usuario en la red.
- `encontrarNodoPorId`: Encuentra un nodo en la red por su ID.
- `encontrarAristaPorIds`: Encuentra una arista en la red dados los IDs de dos nodos.
- `listaNodosConectados`: Printea la lista de nodos intrelazados a un nodo de referencia.
