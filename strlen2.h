#ifndef STRLEN2_H_INCLUDED
#define STRLEN2_H_INCLUDED

int strlen2(int opt){///devuelve el tam de la cadena mas grande, para el encabezado
    switch(opt){
    case(1):
        {
        Campo reg;
        int pos=0;
        int max=6;
        while(reg.leerDisco(pos++)){
            int tam=strlen(reg.getNombre());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
        }
        break;
    case(2):
        {
        Campo reg;
        int pos=0;
        int max=2;
        while(reg.leerDisco(pos++)){
            int tam=strlen(reg.getUbicacion().getPais());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
        }
        break;
    case(3):
        {
        Campo reg;
        int pos=0;
        int max=2;
        while(reg.leerDisco(pos++)){
                int tam=strlen(reg.getUbicacion().getProvincia());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
        }
        break;
    case(4):
        {
        Campo reg;
        int pos=0;
        int max=2;
        while(reg.leerDisco(pos++)){
                int tam=strlen(reg.getUbicacion().getLocalidad());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
        }
        break;
    case(5):
         {
        Cultivo reg;
        int max=6;
        int pos=0;
        while(reg.leerDisco(pos++)){
                int tam=strlen(reg.getNombre());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
         }
        break;
    case(6):
        {
        Cultivo reg;
        int max=17;
        int pos=0;
        while(reg.leerDisco(pos++)){
                int tam=strlen(reg.getNombre());
            if(tam>max){
                max=tam;
            }
        }
        return max+2;
        }
        break;
    }
    return 0;
}


#endif // STRLEN2_H_INCLUDED
