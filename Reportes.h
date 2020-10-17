#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void prodAnual(){
    Cosecha reg;
    int pos=0;
    float prod=0;
    int anio;
    cout << "ANO: ";
    cin >> anio;
    cin.ignore();
    while(reg.leerDisco(pos++)){
        if(reg.getEstado()==true){
            if(reg.getFecha().getAnio()==anio){
                prod+=reg.getProduccion();
            }
        }
    }
    cout << "SE PRODUJO " << prod << " TONELADAS" << endl;
}
void prodXCampo(){
    Cosecha reg;
    Siembra reg2;
    int pos=0;
    float prod=0;
    int idcampo;
    cout << "ID CAMPO: ";
    cin >> idcampo;
    cin.ignore();

    while(reg.leerDisco(pos++)){
        if(reg.getEstado()==true){
            reg2.leerDisco(reg.getIDSiembra()-1);
            if(reg2.getEstado()==true){
                if(reg2.getIDCampo()==idcampo){
                    prod+=reg.getProduccion();
                   }
                }
            }
    }
    cout << "EL CAMPO ID " << idcampo << " PRODUJO " << prod << " TONELADAS" << endl;

}
void prodXTipo(){
    Cultivo reg3;
    int tipo;
    cout << "ID CULTIVO: ";
    cin >> tipo;
    cin.ignore();
    float prod=0;
    int pos=0;
    while(reg3.leerDisco(pos++)){
        if(reg3.getEstado()==true){
            if(reg3.getType()==tipo){
                prod+=reg3.getStock();
            }
        }
    }
    cout << "EL TIPO DE CULTIVO NRO " << tipo << " PRODUJO: " << prod << " TONELADAS" << endl;
}
int menuReporte(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "MENU REPORTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)PRODUCCION ANUAL" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)PRODUCCION POR CAMPO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)PRODUCCION POR CADA TIPO DE CULTIVO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS"<< endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
            prodAnual();
            system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
            prodXCampo();
            system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
            prodXTipo();
            system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}


#endif // REPORTES_H_INCLUDED
