#ifndef NEURONA_H
#define NEURONA_H


class neurona
{
private:
    int id, posicion_x, posicion_y, red, green, blue;
    float voltaje;
    neurona *sig_neurona;

public:
    neurona();
    void set_all(int id, float voltaje, int posicion_x, int posicion_y, int red, int green, int blue);
    void print();
    neurona* get_sig_neurona();
    void set_sig_neurona(neurona *neu_ind);
    int get_id();
    float get_voltaje();
    int get_posicion_x();
    int get_posicion_y();
    int get_red();
    int get_green();
    int get_blue();
};

#endif // NEURONA_H
