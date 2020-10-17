#ifndef COSECHA_H_INCLUDED
#define COSECHA_H_INCLUDED

class Cosecha{
private:
    int ID;
    Fecha date;
    bool estado;
    int IDSiembra;
    float produccion;
public:
    int getID(){return ID;}
    Fecha getFecha(){return date;}
    void setFecha(Fecha val){date=val;}
    int getIDSiembra(){return IDSiembra;}
    bool getEstado(){return estado;}
    float getProduccion(){return produccion;}
    void setID(int val){ID=val;}
    void setIDSiembra(int val){IDSiembra=val;}
    void setEstado(bool val){estado=val;}
    void setProduccion(float val){produccion=val;}
    bool cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    void grabarDisco();
    Cosecha();
};
bool validarSiembra(int);
int buscarLote(int,int);
Cosecha::Cosecha(){
    ID=0;
    Fecha(0,0,0);
    estado=false;
    IDSiembra=0;
    produccion=0;
}
bool Cosecha::cargar(){
    cout << "IDSIEMBRA: ";
    cin >> IDSiembra;
    Siembra reg2;
    if((reg2.leerDisco(IDSiembra-1)==false)||(reg2.getEstado()==false)){
        cout << "LA SIEMBRA NO EXISTE" << endl;
        system("pause");
        return false;
    }
    if(validarSiembra(IDSiembra)){
        cout << "LA SIEMBRA YA FUE COSECHADA" << endl;
        system("pause");
        return false;
    }

    cout << "FECHA: " << endl;
    if(date.cargar())return false;

    if(reg2.getFecha()>date){
        cout << "LA FECHA ES ANTES DE LA SIEMBRA" << endl;
        system("pause");
        return false;
    }

    cout << "PRODUCCION(TONELADAS):";
    cin >> produccion;
    cin.ignore();
    Cultivo reg3;
    reg3.leerDisco(reg2.getIDCultivo()-1);
    reg3.setStock(reg3.getStock()+produccion);//ACUMULAR LO PRODUCIDO EN EL STOCK DEL CULTIVO
    reg3.escribirDisco(reg2.getIDCultivo()-1);

    Lote reg;
    reg.leerDisco(buscarLote(reg2.getIDCampo(),reg2.getIDLote()));
    reg.setEstado(false);//CAMBIAR ESTADO DEL LOTE
    reg.escribirDisco(buscarLote(reg2.getIDCampo(),reg2.getIDLote()));

    ID=contarRegistros(5)+1;
    estado=true;
    return true;
}
void Cosecha::mostrar(){
    if(estado==true){
    cout << setw(11) <<  ID;
    cout << setw(11) << IDSiembra;
    cout << setw(12) << produccion;
    date.MostrarFecha();
    }
}
bool Cosecha::escribirDisco(int pos){
    FILE *p=fopen("cosechas.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cosecha),0);
    bool escribio=fwrite(this,sizeof(Cosecha),1,p);
    fclose(p);
    return escribio;
}
bool Cosecha::leerDisco(int pos){
    FILE *p=fopen("cosechas.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cosecha),0);
    bool leyo=fread(this,sizeof(Cosecha),1,p);
    fclose(p);
    return leyo;
}
void Cosecha::grabarDisco(){
    FILE *p=fopen("cosechas.dat","ab");
    if(p==NULL)exit(456);
    fwrite(this,sizeof(Cosecha),1,p);
    fclose(p);
}
int cosechaModificar(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU COSECHAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)MODIFICAR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)MODIFICAR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)MODIFICAR UBICACION" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                if(modificar(13)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                if(modificar(14)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                if(modificar(15)){
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
int cosechaConsultas(){
    system("cls");
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU COSECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CONSULTA POR CULTIVO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)CONSULTA POR LOTE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)CONSULTA POR FECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                consulta(7);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                consulta(8);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                consulta(14);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int cosechaListados(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "      MENU COSECHAS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "-------------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)LISTAR TODOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)ORDENADO POR PRODUCCION" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)ORDENADO POR FECHA" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                mostrar(5);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                listado(4);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                listado(5);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int menuCosecha(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "  MENU COSECHAS" << endl;
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
                agregar(5);
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                cosechaListados();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                cosechaConsultas();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(bajaLogica(5)){
                    cout << "SE ELIMINO CORRECTAMENTE" << endl;
                    }else{
                        cout << "NO SE ELIMINO CORRECTAMENTE" << endl;
                    }
                system("pause");
                system("cls");
        }
        else if(k=='5'){
                system("cls");
                cosechaModificar();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}


#endif // COSECHA_H_INCLUDED
