#include "admin.h"
#include <iostream>

using namespace std;

admin::admin()
{
    lista_beg = NULL;
}

void admin::agregar_inicio(neurona *n_neurona)
{
    if(lista_beg == NULL)
    {
        lista_beg = n_neurona;
    }
    else
    {
        n_neurona->set_sig_neurona(lista_beg);
        lista_beg = n_neurona;
    }
    return;
}

void admin::agregar_final(neurona *n_neurona)
{
    if(lista_beg == NULL)
    {
        lista_beg = n_neurona;
    }
    else
    {
        neurona *aux = lista_beg;
        while(aux->get_sig_neurona() != NULL)
        {
            aux->print();
            aux = aux->get_sig_neurona();
        }
        aux->set_sig_neurona(n_neurona);
    }
    return;
}

void admin::mostrar()
{
    if(lista_beg != NULL)
    {
        neurona *aux = lista_beg;
        while(aux != NULL)
        {
            aux->print();
            aux = aux->get_sig_neurona();
        }
    }
    return;
}

neurona* admin::get_lista_beg()
{
    return this->lista_beg;
}
