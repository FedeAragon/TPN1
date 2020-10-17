#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Encabezados.h"
#include "strlen2.h"
#include "BajaLogicas.h"
#include "Consultas.h"
#include "Listados.h"
#include "Modificar.h"

int contarRegistros(int opt){
    int pos=0;
    switch(opt){
case 1:
    Campo reg;
    while(reg.leerDisco(pos))pos++;
    break;
case 2:
    Lote reg2;
    while(reg2.leerDisco(pos))pos++;
    break;
case 3:
    Cultivo reg3;
    while(reg3.leerDisco(pos))pos++;
    break;
case 4:{
    Siembra reg4;
    while(reg4.leerDisco(pos))pos++;
    break;}
case 5:
    Cosecha reg5;
    while(reg5.leerDisco(pos))pos++;
    break;
    }
    return pos;
}
int contarRegistrosLote(int IDCampo){
    int pos=0,cant=0;
    Lote reg;
    while(reg.leerDisco(pos++)){
        if(reg.getIDCampo()==IDCampo){
            cant++;
        }
    }
    return cant;
}
int buscarLote(int campo,int lote){
    int pos=0;
    Lote reg;
    while(reg.leerDisco(pos)){
        if((reg.getIDCampo()==campo)&&(reg.getID()==lote)){
                return pos;
        }
        pos++;
    }
    return 0;
}
void agregar(int opt){
    switch(opt){
case 1:
    Campo reg;
    if(reg.cargar()){
    reg.grabarDisco();
    cout <<endl<< "SE CARGO CORRECTAMENTE" << endl;
    system("pause");
    }
    break;
case 2:
    Lote reg2;
    if(reg2.cargar()){
    reg2.grabarDisco();
    cout <<endl<< "SE CARGO CORRECTAMENTE" << endl;
    system("pause");
    }
    break;
case 3:
    Cultivo reg3;
    if(reg3.cargar()){
    reg3.grabarDisco();
    cout <<endl<< "SE CARGO CORRECTAMENTE" << endl;
    system("pause");
    }
    break;
case 4:
    {
    Siembra reg4;
    if(reg4.cargar()){
    reg4.grabarDisco();
    cout <<endl<< "SE CARGO CORRECTAMENTE" << endl;
    system("pause");
    }
    break;
    }
case 5:
    Cosecha reg5;
    if(reg5.cargar()){
    reg5.grabarDisco();
    cout <<endl<< "SE CARGO CORRECTAMENTE" << endl;
    system("pause");
    }
    break;
    }
}
void mostrar(int opt){
    int pos=0;
    switch(opt){
case 1:
    Campo reg;
    encabezados(1);
    while(reg.leerDisco(pos++)){
            reg.mostrar();
    }
    break;
case 2:
    Lote reg2;
    encabezados(2);
    while(reg2.leerDisco(pos++)){
            reg2.mostrar();
    }
    break;
case 3:
    Cultivo reg3;
    encabezados(3);
    while(reg3.leerDisco(pos++)){
            reg3.mostrar();
    }
    break;
case 4:{
    encabezados(4);
    Siembra reg4;
    while(reg4.leerDisco(pos++)){
            reg4.mostrar();
    }
    break;}
case 5:
    Cosecha reg5;
    encabezados(5);
    while(reg5.leerDisco(pos++)){
            reg5.mostrar();
    }
    break;
    }
}
bool validarNombreCampo(const char *val){///VERDADERO SI LO ENCUENTRA, FALSO SI NO
    Campo reg;
    int pos=0;
    while(reg.leerDisco(pos++)){
        if(reg.getEstado()==true){
            if(strcmp(val,reg.getNombre())==0){
                return true;
            }
        }
    }
    return false;
}
bool validarNombreCultivo(const char *val){
    Cultivo reg;
    int pos=0;
    while(reg.leerDisco(pos++)){
        if(reg.getEstado()==true){
            if(strcmp(val,reg.getNombre())==0){
                return true;
            }
        }
    }
    return false;
}
bool validarSiembra(int idSiembra){
    Cosecha reg;
    int pos=0;
    while(reg.leerDisco(pos++)){
        if(reg.getEstado()==true){
            if(reg.getIDSiembra()==idSiembra){
                return true;
            }
        }
    }
    return false;
}

#endif // FUNCIONES_H_INCLUD
