#ifndef BAJALOGICAS_H_INCLUDED
#define BAJALOGICAS_H_INCLUDED

bool bajaLogica(int opt){
    switch(opt){
    case 1://borrar CAMPO, LOTES de ese CAMPO, SIEMBRAS Y COSECHAS, resta el stock del Cultivo
        {
            char nom[50];
            Campo reg;Lote reg2;Siembra reg3;Cosecha reg4;Cultivo reg5;
            cout << "NOMBRE DEL CAMPO: ";
            const int x=4;
            bool seBorro[x]={0};

            cin.getline(nom,50);
            int pos=0;
            while(reg.leerDisco(pos++)){
                if(strcmp(reg.getNombre(),nom)==0){
                    reg.setEstado(false);
                    reg.escribirDisco(reg.getID()-1);
                    seBorro[0]=true;
                }
            }

            pos=0;
            while(reg2.leerDisco(pos++)){
                reg.leerDisco(reg2.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    reg2.setEstado2(false);
                    reg2.escribirDisco(buscarLote(reg2.getIDCampo(),reg2.getID()));
                    seBorro[1]=true;
                }
            }
            pos=0;
            while(reg3.leerDisco(pos++)){
                reg.leerDisco(reg3.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    reg3.setEstado(false);
                    reg3.escribirDisco(reg3.getID()-1);
                    seBorro[2]=true;
                }
            }
            pos=0;
            while(reg4.leerDisco(pos++)){
                reg3.leerDisco(reg4.getIDSiembra()-1);
                reg.leerDisco(reg3.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    reg4.setEstado(false);
                    reg4.escribirDisco(reg4.getID()-1);
                    reg5.leerDisco(reg3.getIDCultivo()-1);
                    reg5.setStock(reg5.getStock()-reg4.getProduccion());
                    reg5.escribirDisco(reg5.getID()-1);
                    seBorro[3]=true;
                }
            }
            for(int i=0;i<x;i++){
                if(seBorro[i]==false){return false;}
            }
            return true;
        }
        break;
    case 2://borra lote, siembras y cosechas, resta el stock del cultivo
        {
            char nom[50];
            Campo reg;Lote reg2;Siembra reg3;Cosecha reg4;Cultivo reg5;
            cout << "NOMBRE DEL CAMPO: ";
            const int x=3;
            bool seBorro[x]={0};

            cin.getline(nom,50);
            int id;
            cout << "NUMERO DEL LOTE(ID): ";
            cin >> id;
            int pos=0;
            while(reg2.leerDisco(pos++)){
                reg.leerDisco(reg2.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    if(reg2.getID()==id){
                        reg2.setEstado2(false);
                        reg2.escribirDisco(buscarLote(reg2.getIDCampo(),reg2.getID()));
                    seBorro[0]=true;
                    }
                }
            }
            pos=0;
            while(reg3.leerDisco(pos++)){
                reg.leerDisco(reg3.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    if(reg3.getIDLote()==id){
                        reg3.setEstado(false);
                        reg3.escribirDisco(reg3.getID()-1);
                    seBorro[1]=true;
                    }
                }
            }
            pos=0;
            while(reg4.leerDisco(pos++)){
                reg3.leerDisco(reg4.getIDSiembra()-1);
                reg.leerDisco(reg3.getIDCampo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    if(reg3.getIDLote()==id){
                        reg4.setEstado(false);
                        reg4.escribirDisco(reg4.getID()-1);
                        reg5.leerDisco(reg3.getIDCultivo()-1);
                        reg5.setStock(reg5.getStock()-reg4.getProduccion());
                        reg5.escribirDisco(reg5.getID()-1);
                    seBorro[2]=true;
                    }
                }
            }
            for(int i=0;i<x;i++){
                if(seBorro[i]==false){return false;}
            }
            return true;
        }
        break;
    case 3://borrar Cultivo, Siembras y Cosechas donde esta, cambiar estado del LOTE SEMBRADO a VACIO
        {
            char nom[50];
            Cultivo reg;Lote reg2;Siembra reg3;Cosecha reg4;
            cout << "NOMBRE DEL CULTIVO: ";
            const int x=3;
            bool seBorro[x]={0};

            cin.getline(nom,50);
            int pos=0;
            while(reg.leerDisco(pos++)){
                if(strcmp(reg.getNombre(),nom)==0){
                    reg.setEstado(false);
                    reg.escribirDisco(reg.getID()-1);
                    seBorro[0]=true;
                }
            }
            pos=0;
            while(reg3.leerDisco(pos++)){
                reg.leerDisco(reg3.getIDCultivo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    reg3.setEstado(false);
                    reg3.escribirDisco(reg3.getID()-1);
                    reg2.leerDisco(buscarLote(reg3.getIDCampo(),reg3.getIDLote()));
                    reg2.setEstado(false);
                    reg2.escribirDisco(buscarLote(reg3.getIDCampo(),reg3.getIDLote()));
                    seBorro[1]=true;
                }
            }
            pos=0;
            while(reg4.leerDisco(pos++)){
                reg3.leerDisco(reg4.getIDSiembra()-1);
                reg.leerDisco(reg3.getIDCultivo()-1);
                if(strcmp(reg.getNombre(),nom)==0){
                    reg4.setEstado(false);
                    reg4.escribirDisco(reg4.getID()-1);
                    seBorro[2]=true;
                }
            }
            for(int i=0;i<x;i++){
                if(seBorro[i]==false){return false;}
            }
            return true;
        }
        break;
    case 4://borra Siembra cambia el estado del lote PLANTADO a VACIO
        {
            int id;
            Siembra reg;Lote reg2;
            cout << "ID SIEMBRA: ";
            cin >> id;
            bool seBorro=false;
            int pos=0;
            while(reg.leerDisco(pos++)){
                if(reg.getID()==id){
                    reg.setEstado(false);
                    reg.escribirDisco(reg.getID()-1);
                    reg2.leerDisco(buscarLote(reg.getIDCampo(),reg.getIDLote()));
                    reg2.setEstado(false);
                    reg2.escribirDisco(buscarLote(reg.getIDCampo(),reg.getIDLote()));
                    seBorro=true;
                }
            }
            if(seBorro==false){return false;}
            return true;
        }
        break;
    case 5://Elimina Cosecha y resta Stock de ese cultivo, ademas da la posibilidad de cosechar ese Lote en otro momento(cambiar estado LOTE)
        {
            int id;
            Cosecha reg;Siembra reg2;Cultivo reg3;Lote reg4;
            cout << "ID COSECHA: ";
            cin >> id;
            bool seBorro=false;
            int pos=0;
            while(reg.leerDisco(pos++)){
                if(reg.getID()==id){
                    reg.setEstado(false);
                    reg.escribirDisco(reg.getID()-1);
                    reg2.leerDisco(reg.getIDSiembra()-1);
                    reg3.leerDisco(reg2.getIDCultivo()-1);
                    reg3.setStock(reg3.getStock()-reg.getProduccion());
                    reg3.escribirDisco(reg2.getIDCultivo()-1);
                    reg4.leerDisco(buscarLote(reg2.getIDCampo(),reg2.getIDLote()));
                    reg4.setEstado(true);
                    reg4.escribirDisco(buscarLote(reg2.getIDCampo(),reg2.getIDLote()));
                    seBorro=true;
                }
            }
            if(seBorro==false){return false;}
            return true;
        }
        break;
    }
    return false;
}


#endif // BAJALOGICAS_H_INCLUDED
