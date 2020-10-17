#ifndef UBICACION_H_INCLUDED
#define UBICACION_H_INCLUDED

class Ubicacion{
    private:
        char pais[50];
        char provincia[50];
        char localidad[50];
    public:
        const char * getPais(){return pais;}
        const char * getProvincia(){return provincia;}
        const char * getLocalidad(){return localidad;}
        void setPais(const char * _pais){strcpy(pais,_pais);}
        void setProvincia(const char *_prov){strcpy(provincia,_prov);}
        void setLocalidad(const char *_local){strcpy(localidad,_local);}
        void cargar();
        void mostrar();
        bool operator ==(Ubicacion &);
};
int strlen2(int);
void Ubicacion::cargar(){
    cout << "PAIS: ";
    cin.getline(pais,50);
    cout << "PROVINCIA: ";
    cin.getline(provincia,50);
    cout << "LOCALIDAD: ";
    cin.getline(localidad,50);
}
void Ubicacion::mostrar(){
    cout << left;
    cout << setw(strlen2(2)) << pais << ", "<< setw(strlen2(3))  << provincia << ", "<< setw(strlen2(4))  << localidad << endl;
}
bool Ubicacion::operator==(Ubicacion &obj){
    if(strcmp(pais,obj.getPais())!=0)return false;
    if(strcmp(provincia,obj.getProvincia())!=0)return false;
    if(strcmp(localidad,obj.getLocalidad())!=0)return false;
    return true;
}

#endif // UBICACION_H_INCLUDED
