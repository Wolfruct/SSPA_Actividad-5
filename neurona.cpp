#include <iostream>
#include "neurona.h"

using namespace std;

neurona::neurona()
{
    id = 0;
    voltaje = 0;
    posicion_x = 0;
    posicion_y = 0;
    red = 0;
    green = 0;
    blue = 0;
    sig_neurona = NULL;
}

void neurona::set_all(int id, float voltaje, int posicion_x, int posicion_y, int red, int green, int blue)
{
    this->id = id;
    this->voltaje = voltaje;
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->red = red;
    this->green = green;
    this->blue = blue;

    return;
}

void neurona::print()
{
    cout << "   ---- Neurona ----" << "\nID: " << id << "\nVoltaje: " << voltaje << "\nPosicion x: " << posicion_x << "\nPosicion y: " << posicion_y << "\nRed: " << red << "\nGreen: " << green << "\nBlue: " << blue << endl;
    return;
}

neurona* neurona::get_sig_neurona()
{
    return sig_neurona;
}

void neurona::set_sig_neurona(neurona *neu_ind)
{
    sig_neurona = neu_ind;
    return;
}

int neurona::get_id()
{
    return id;
}

float neurona::get_voltaje()
{
    return voltaje;
}

int neurona::get_posicion_x()
{
    return posicion_x;
}

int neurona::get_posicion_y()
{
    return posicion_y;
}

int neurona::get_red()
{
    return red;
}

int neurona::get_green()
{
    return green;
}

int neurona::get_blue()
{
    return blue;
}
