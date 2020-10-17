#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED

class Lote{
private:
    int ID;
    int IDCampo;
    float tam;
    bool estado;//1=PLANTADO , 0=VACIO
    bool estado2;//baja logica
public:
    int getID(){return ID;}
    int getIDCampo(){return IDCampo;}
    float getTam(){return tam;}
    bool getEstado(){return estado;}
    void setID(int _ID){ID=_ID;}
    void setIDCampo(int _IDCampo){IDCampo=_IDCampo;}
    void setTam(float _tam){tam=_tam;}
    void setEstado(bool _estado){estado=_estado;}
    bool cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    void grabarDisco();
    bool getEstado2(){return estado2;}
    void setEstado2(bool val){estado2=val;}
};
int contarRegistrosLote(int);
bool Lote::cargar(){
    cout << "IDCAMPO: ";
    cin >> IDCampo;
    Campo reg;
    if((reg.leerDisco(IDCampo-1)==false)||(reg.getEstado()==false)){
        cout << "CAMPO NO EXISTE" << endl;
        system("pause");
        return false;
    }
    cout << "TAMANO: ";
    cin >> tam;
    cin.ignore();
    reg.leerDisco(IDCampo-1);
    reg.setCargado(reg.getCargado()+tam);
    if(reg.getCargado()>reg.getTam()){
        cout << "SE SOBREPASA EL TAMANO DEL CAMPO" << endl;
        system("pause");
        return false;
    }
    reg.escribirDisco(IDCampo-1);
    ID=contarRegistrosLote(IDCampo)+1;
    estado=false;
    estado2=true;
    return true;
}
void Lote::mostrar(){
    if(estado2==true){
    cout << left;
    cout << setw(8) <<  ID;
    cout << setw(9) << IDCampo;
    cout << setw(10) << tam;
    cout << setw(20)  << estado;
    cout << endl;
    }
}
bool Lote::escribirDisco(int pos){
    FILE *p=fopen("lotes.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Lote),0);
    bool escribio=fwrite(this,sizeof(Lote),1,p);
    fclose(p);
    return escribio;
}
bool Lote::leerDisco(int pos){
    FILE *p=fopen("lotes.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Lote),0);
    bool leyo=fread(this,sizeof(Lote),1,p);
    fclose(p);
    return leyo;
}
void Lote::grabarDisco(){
    FILE *p=fopen("lotes.dat","ab");
    if(p==NULL)exit(456);
    fwrite(this,sizeof(Lote),1,p);
    fclose(p);
}
int loteModificar(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU LOTE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)MODIFICAR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                if(modificar(4)){
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
int loteConsultas(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU LOTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "---------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CONSULTA POR CAMPO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)CONSULTA POR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                consulta(11);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                consulta(12);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int loteListados(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU LOTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "---------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)LISTAR TODOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)ORENADOS POR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                mostrar(2);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                listado(8);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int menuLote(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU LOTES" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CREAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)LISTADOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)CONSULTAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "4)BORRAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+2);cout << "5)MODIFICAR" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+3);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                agregar(2);
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                loteListados();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                loteConsultas();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(bajaLogica(2)){
                    cout << "SE ELIMINO CORRECTAMENTE" << endl;
                    }else{
                        cout << "NO SE ELIMINO CORRECTAMENTE" << endl;
                    }
                system("pause");
                system("cls");
        }
        else if(k=='5'){
                system("cls");
                loteModificar();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
#endif // LOTE_H_INCLUDED
