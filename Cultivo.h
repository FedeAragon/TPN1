#ifndef CULTIVO_H_INCLUDED
#define CULTIVO_H_INCLUDED

class Cultivo{
private:
    int ID;
    char nombre[50];
    char nombrecien[50];
    float precio;
    float stock;
    bool estado;
    int type;// 1 FRUTA, 2 VEGETAL, 3 GRANO
public:
    int getID(){return ID;}
    const char * getNombre(){return nombre;}
    const char * getNombrecien(){return nombrecien;}
    float getPrecio(){return precio;}
    float getStock(){return stock;}
    bool getEstado(){return estado;}
    int getType(){return type;}
    void setID(int _ID){ID=_ID;}
    void setNombre(const char * _nombre){strcpy(nombre,_nombre);}
    void setNombrecien(const char * _nombrecien){strcpy(nombrecien,_nombrecien);}
    void setPrecio(float val){precio=val;}
    void setStock(float val){stock=val;}
    void setEstado(bool val){estado=val;}
    void setType(int val){type=val;}
    bool cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    void grabarDisco();
};
bool validarNombreCultivo(const char*);
bool Cultivo::cargar(){
    cout << "NOMBRE:";
    cin.getline(nombre,50);
    if(validarNombreCultivo(nombre)){
        cout << "ESTE NOMBRE YA EXISTE" << endl;
        system("pause");
        return false;
    }
    cout << "NOMBRE CIENTIFICO: ";
    cin.getline(nombrecien,50);
    cout << "PRECIO:";
    cin >> precio;
    if(precio<0){
        cout << "PRECIO INVALIDO" << endl;
        system("pause");
        return false;
    }
    cout << "TIPO(1:FRUTA/2:VEGETAL/3:GRANO): ";
    cin >> type;
    if(type<1||type>3){
        cout << "TIPO INVALIDO" << endl;
        system("pause");
        return false;
    }
    ID=contarRegistros(3)+1;
    stock=0;
    estado=true;
    return true;
}
void Cultivo::mostrar(){
    if(estado==true){
    cout << left;
    cout << setw(4) <<  ID;
    cout << setw(strlen2(5)) << nombre;
    cout << setw(strlen2(6)) << nombrecien;
    cout << setw(18) << stock;
    cout << setw(6) << type;
    cout << setw(20) << precio << "$";
    cout << endl;
    }
}
bool Cultivo::escribirDisco(int pos){
    FILE *p=fopen("cultivos.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cultivo),0);
    bool escribio=fwrite(this,sizeof(Cultivo),1,p);
    fclose(p);
    return escribio;
}
bool Cultivo::leerDisco(int pos){
    FILE *p=fopen("cultivos.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cultivo),0);
    bool leyo=fread(this,sizeof(Cultivo),1,p);
    fclose(p);
    return leyo;
}
void Cultivo::grabarDisco(){
    FILE *p=fopen("cultivos.dat","ab");
    if(p==NULL)exit(456);
    fwrite(this,sizeof(Cultivo),1,p);
    fclose(p);
}
int cultivoModificar(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU CULTIVOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)MODIFICAR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)MODIFICAR NOMBRE CIENTIFICO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)MODIFICAR PRECIO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "4)MODIFICAR TIPO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+2);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                if(modificar(5)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                if(modificar(6)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                if(modificar(7)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(modificar(8)){
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
int cultivoConsultas(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "         MENU CULTIVOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CONSULTA POR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)CONSULTA POR NOMBRE CIENTIFICO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)CONSULTA POR RANGO DE PRECIO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                consulta(2);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                consulta(3);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                consulta(4);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int cultivoListados(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "    MENU CULTIVOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)LISTAR TODOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)ORDENADOS POR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout << "3)ORDENADOS POR PRECIO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                mostrar(3);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                listado(2);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                listado(3);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int menuCultivo(){
    while(true){
            system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "  MENU CULTIVOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "-----------------" << endl;
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
                agregar(3);
                system("cls");
        }
        else if(k=='2'){
                system("cls");
            cultivoListados();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
            cultivoConsultas();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(bajaLogica(3)){
                    cout << "SE ELIMINO CORRECTAMENTE" << endl;
                    }else{
                        cout << "NO SE ELIMINO CORRECTAMENTE" << endl;
                    }
                system("pause");
                system("cls");
        }
        else if(k=='5'){
                system("cls");
            cultivoModificar();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}

#endif // CULTIVO_H_INCLUDED
