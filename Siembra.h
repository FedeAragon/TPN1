#ifndef SIEMBRA_H_INCLUDED
#define SIEMBRA_H_INCLUDED

class Siembra{
private:
    int ID;
    Fecha date;
    int IDCampo;
    int IDLote;
    int IDCultivo;
    bool estado;
public:
    int getID(){return ID;}
    Fecha getFecha(){return date;}
    void setFecha(Fecha val){date=val;}
    int getIDCampo(){return IDCampo;}
    int getIDLote(){return IDLote;}
    int getIDCultivo(){return IDCultivo;}
    void setID(int val){ID=val;}
    void setIDCampo(int val){IDCampo=val;}
    void setIDLote(int val){IDLote=val;}
    void setIDCultivo(int val){IDCultivo=val;}
    bool cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    void grabarDisco();
    bool getEstado(){return estado;}
    void setEstado(bool val){estado=val;}
    Siembra();
};
Siembra::Siembra(){
    ID=0;
    Fecha(0,0,0);
    IDCampo=0;
    IDLote=0;
    IDCultivo=0;
    estado=false;
}
bool Siembra::cargar(){
    cout << "IDCAMPO: ";
    cin >> IDCampo;
    Campo reg2;
    if((reg2.leerDisco(IDCampo-1)==false)||(reg2.getEstado()==false)){
        cout << "CAMPO NO EXISTE" << endl;
        system("pause");
        return false;
    }
    cout << "IDLOTE:";
    cin >> IDLote;
    Lote reg;
    if((reg.leerDisco(buscarLote(IDCampo,IDLote))==false)||(reg.getEstado2()==false)){
        cout << "EL LOTE NO EXISTE" << endl;
        system("pause");
        return false;
    };
    reg.leerDisco(buscarLote(IDCampo,IDLote));
    if(reg.getEstado()==true){
        cout << "LOTE OCUPADO" << endl;
        system("pause");
        return false;
    }
    cout << "FECHA: " << endl;
    if(date.cargar())return false;

    cout << "IDCULTIVO: ";
    cin >> IDCultivo;
    cin.ignore();
    Cultivo reg3;
    if((reg3.leerDisco(IDCultivo-1)==false)||(reg3.getEstado()==false)){
        cout << "CULTIVO NO EXISTE" << endl;
        system("pause");
        return false;
    }
    reg.setEstado(true);//CAMBIAR ESTADO DEL LOTE
    reg.escribirDisco(buscarLote(IDCampo,IDLote));
    ID=contarRegistros(4)+1;
    estado=true;
    return true;
}
void Siembra::mostrar(){
    if(estado==true){
    cout << left;
    cout << setw(11) << ID;
    cout << setw(9) << IDCampo;
    cout << setw(8) << IDLote;
    cout << setw(11) << IDCultivo;
    date.MostrarFecha();
    }
}
bool Siembra::escribirDisco(int pos){
    FILE *p=fopen("siembras.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Siembra),0);
    bool escribio=fwrite(this,sizeof(Siembra),1,p);
    fclose(p);
    return escribio;
}
bool Siembra::leerDisco(int pos){
    FILE *p=fopen("siembras.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Siembra),0);
    bool leyo=fread(this,sizeof(Siembra),1,p);
    fclose(p);
    return leyo;
}
void Siembra::grabarDisco(){
    FILE *p=fopen("siembras.dat","ab");
    if(p==NULL)exit(456);
    fwrite(this,sizeof(Siembra),1,p);
    fclose(p);
}
int siembraModificar(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU SIEMBRAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)MODIFICAR IDCAMPO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)MODIFICAR IDLOTE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)MODIFICAR IDCULTIVO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "4)MODIFICAR FECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+2);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                if(modificar(9)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                if(modificar(10)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                if(modificar(11)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(modificar(12)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int siembraConsultas(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU SIEMBRAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CONSULTA POR CULTIVO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)CONSULTA POR LOTE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)CONSULTA POR FECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                consulta(5);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                consulta(6);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                consulta(13);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int siembraListados(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU SIEMBRAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)LISTAR TODOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)ORDENADO POR FECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                mostrar(4);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                listado(6);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int menuSiembra(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "  MENU SIEMBRAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CREAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)LISTADOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)CONSULTAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "4)BORRAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+2);cout << "5)MODIFICAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+3);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                agregar(4);
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                siembraListados();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                siembraConsultas();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(bajaLogica(4)){
                    cout << "SE ELIMINO CORRECTAMENTE" << endl;
                    }else{
                        cout << "NO SE ELIMINO CORRECTAMENTE" << endl;
                    }
                system("pause");
                system("cls");
        }
        else if(k=='5'){
                system("cls");
                siembraModificar();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}

#endif // SIEMBRA_H_INCLUDED
