#ifndef ED_T3_ARISTACONEXIONES_H
#define ED_T3_ARISTACONEXIONES_H


class AristaConexiones {

private:
    int idCliente;
    int idServidor;
    int velocidad;
    int distancia;

public:
    AristaConexiones();

    int getIdCliente() const;

    int getIdServidor() const;

    int getVelocidad() const;

    int getDistancia() const;

};


#endif //ED_T3_ARISTACONEXIONES_H
