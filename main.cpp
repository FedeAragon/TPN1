#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "rlutil.h"
using namespace std;
#include "fecha.h"
#include "Ubicacion.h"
#include "Campo.h"
#include "Lote.h"
#include "Cultivo.h"
#include "Siembra.h"
#include "Cosecha.h"
#include "Funciones.h"
#include "Reportes.h"

int main(){
    std::string titulo(8,'\0');
    titulo="AGROTECH";
    rlutil::setConsoleTitle(titulo);
    rlutil::setColor(15);
while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "   MENU" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CAMPO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)LOTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)CULTIVOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "4)SIEMBRAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+2);cout << "5)COSECHAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+3);cout << "6)REPORTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+4);cout << "ESC)SALIR"<< endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                menuCampo();
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                menuLote();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                menuCultivo();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                menuSiembra();
                system("cls");
        }
        else if(k=='5'){
                system("cls");
                menuCosecha();
                system("cls");
        }
        else if(k=='6'){
                system("cls");
                menuReporte();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
