#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED

class Campo{
    private:
        int ID;
        Ubicacion location;
        float tam;
        float cargado;
        char nombre[50];
        bool estado;
    public:
        int getID(){return ID;}
        Ubicacion getUbicacion(){return location;}
        float getTam(){return tam;}
        float getCargado(){return cargado;}
        const char * getNombre(){return nombre;}
        bool getEstado(){return estado;}
        void setID(int _ID){ID=_ID;}
        void setUbicacion(Ubicacion _location){location=_location;}
        void setTam(float _tam){tam=_tam;}
        void setCargado(float _cant){cargado=_cant;}
        void setNombre(const char *_nombre){strcpy(nombre,_nombre);}
        void setEstado(bool _estado){estado=_estado;}
        bool cargar();
        void mostrar();
        bool escribirDisco(int pos);
        bool leerDisco(int pos);
        void grabarDisco();
};
bool modificar(int);
int strlen2(int);
void encabezados(int);
bool validarNombreCampo(const char*);
int contarRegistros(int);
int buscarLote(int,int);
bool Campo::cargar(){
    cout << "NOMBRE: ";
    cin.getline(nombre,50);
    if(validarNombreCampo(nombre)){
    cout << "ESTE NOMBRE YA EXISTE" << endl;
    system("pause");
    return false;
    }
    cout << "TAMANO EN M2: ";
    cin >> tam;
    cin.ignore();
    if(tam<10000){
        cout << "TAMANO INVALIDO" << endl;
        system("pause");
        return false;
    }
    ID=contarRegistros(1)+1;
    estado=true;
    location.cargar();
    cargado=0;
    return true;
}
void Campo::mostrar(){
    if(estado==true){
    cout << left;
    cout << setw(4) <<  ID;
    cout << setw(strlen2(1)) << nombre;
    cout << setw(8) << cargado << setw(8) << tam;
    location.mostrar();
    }
}
bool Campo::escribirDisco(int pos){
    FILE *p=fopen("campos.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Campo),0);
    bool escribio=fwrite(this,sizeof(Campo),1,p);
    fclose(p);
    return escribio;
}
bool Campo::leerDisco(int pos){
    FILE *p=fopen("campos.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof *this,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;
}
void Campo::grabarDisco(){
    FILE *p=fopen("campos.dat","ab");
    if(p==NULL)exit(456);
    fwrite(this,sizeof(Campo),1,p);
    fclose(p);
}
void agregar(int);
void mostrar(int);
void listado(int);
void consulta(int);
bool bajaLogica(int);
int campoModificar(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU CAMPOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)MODIFICAR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)MODIFICAR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)MODIFICAR UBICACION" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                if(modificar(1)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                if(modificar(2)){
                    cout << "SE MODIFICO CORRECTAMENTE" << endl;
                }else{
                    cout << "NO SE MODIFICO CORRECTAMENTE" << endl;
                }
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                if(modificar(3)){
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
int campoConsultas(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU CAMPOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "--------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)CONSULTA POR UBICACION" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)CONSULTA POR NOMBRE" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)CONSULTA POR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                consulta(1);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                consulta(9);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                consulta(10);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}
int campoListados(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "     MENU CAMPOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-3);cout << "----------------------" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-2);cout << "1)LISTAR TODOS" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-1);cout << "2)ORDENADOS POR TAMANO" << endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2);cout <<   "3)ORDENADOS POR NOMBRE"<< endl;
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2+1);cout << "ESC)VOLVER ATRAS" << endl;
        rlutil::hidecursor();
        int k=rlutil::getkey();
        if(k=='1'){
                system("cls");
                mostrar(1);
                system("pause");
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                listado(1);
                system("pause");
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                listado(7);
                system("pause");
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}

int menuCampo(){
    while(true){
        system("cls");
        gotoxy(rlutil::tcols()/2-5,rlutil::trows()/2-4);cout << "   MENU CAMPOS" << endl;
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
                agregar(1);
                system("cls");
        }
        else if(k=='2'){
                system("cls");
                campoListados();
                system("cls");
        }
        else if(k=='3'){
                system("cls");
                campoConsultas();
                system("cls");
        }
        else if(k=='4'){
                system("cls");
                if(bajaLogica(1)){
                    cout << "SE ELIMINO CORRECTAMENTE" << endl;
                    }else{
                        cout << "NO SE ELIMINO CORRECTAMENTE" << endl;
                    }
                system("pause");
                system("cls");
        }
        else if(k=='5'){
                system("cls");
                campoModificar();
                system("cls");
        }
        else if(k==rlutil::KEY_ESCAPE)return 0;
    }
}


#endif // CAMPO_H_INCLUDED
