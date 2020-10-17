#ifndef MODIFICAR_H_INCLUDED
#define MODIFICAR_H_INCLUDED

bool modificar(int opt){
    switch(opt){
    case 1://modificar Nombre CAMPO
        {
            Campo reg;
            char nom[50];
            int id;
            cout << "ID CAMPO: ";
            cin >> id;
            cin.ignore();
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "NOMBRE NUEVO: ";
            cin.getline(nom,50);

            reg.setNombre(nom);
            reg.escribirDisco(reg.getID()-1);
            return true;

        }
        break;
    case 2://modificar tamaño CAMPO
        {
            Campo reg;
            int id;
            float tam;
            cout << "ID CAMPO: ";
            cin >> id;
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "TAMANO NUEVO: ";
            cin >> tam;
            cin.ignore();
            if(tam<reg.getCargado())return false;
            reg.setTam(tam);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 3://modificar ubicacion CAMPO
        {
            Campo reg;
            int id;
            Ubicacion aux;
            cout << "ID CAMPO: ";
            cin >> id;
            cin.ignore();
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "UBICACION NUEVA" << endl;
            aux.cargar();
            reg.setUbicacion(aux);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 4://modificar tamaño LOTE
        {
            Lote reg;Campo reg2;
            int idcampo,idlote;
            float tam;
            cout << "ID CAMPO: ";
            cin >> idcampo;
            if(!reg2.leerDisco(idcampo-1)||!reg2.getEstado())return false;
            cout << "ID LOTE: ";
            cin >> idlote;
            if(!reg.leerDisco(buscarLote(idcampo,idlote))||!reg.getEstado2())return false;
            cout << "TAMANO NUEVO: ";
            cin >> tam;
            cin.ignore();
            if(tam<0||reg2.getCargado()-reg.getTam()+tam>=reg2.getTam())return false;
            reg2.setCargado(reg2.getCargado()-reg.getTam()+tam);
            reg2.escribirDisco(reg2.getID()-1);
            reg.setTam(tam);
            reg.escribirDisco(buscarLote(idcampo,idlote));
            return true;
        }
        break;
    case 5://modificar nombre CULTIVO
        {
            Cultivo reg;
            int id;
            char nom[50];
            cout << "ID CULTIVO: ";
            cin >> id;
            cin.ignore();
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "NOMBRE NUEVOO: ";
            cin.getline(nom,50);
            reg.setNombre(nom);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 6://modificiar nombre cientifico CULTIVO
        {
            Cultivo reg;
            int id;
            char nom[50];
            cout << "ID CULTIVO: ";
            cin >> id;
            cin.ignore();
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "NOMBRE CIENTIFICO NUEVOO: ";
            cin.getline(nom,50);
            reg.setNombrecien(nom);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 7://modificar precio CULTIVO
        {
            Cultivo reg;
            int id;
            float precio;
            cout << "ID CULTIVO: ";
            cin >> id;
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "PRECIO NUEVOO: ";
            cin >> precio;
            cin.ignore();
            if(precio<0)return false;
            reg.setPrecio(precio);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 8://modificar tipo CULTIVO
        {
            Cultivo reg;
            int id,tipo;
            cout << "ID CULTIVO: ";
            cin >> id;
            if(!reg.leerDisco(id-1)||!reg.getEstado())return false;
            cout << "TIPO NUEVOO: ";
            cin >> tipo;
            cin.ignore();
            if(tipo>3&&tipo<1)return false;
            reg.setType(tipo);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 9://modificar idcampo de SIEMBRA
        {
            Siembra reg;
            int idsiembra, idcampo;
            cout << "ID SIEMBRA: ";
            cin >> idsiembra;
            if(!reg.leerDisco(idsiembra-1)||!reg.getEstado())return false;
            cout << "NUEVO ID CAMPO: ";
            cin >> idcampo;
            cin.ignore();
            Campo reg2;
            if(!reg2.leerDisco(idcampo-1)||!reg2.getEstado())return false;
            reg.setIDCampo(idcampo);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 10://modificar idlote de SIEMBRA
        {
            Siembra reg;
            int idsiembra, idlote ;
            cout << "ID SIEMBRA: ";
            cin >> idsiembra;
            if(!reg.leerDisco(idsiembra-1)||!reg.getEstado())return false;
            cout << "NUEVO ID LOTE: ";
            cin >> idlote;
            cin.ignore();
            Lote reg2;
            if(!reg2.leerDisco(buscarLote(reg.getIDCampo(),idlote))||!reg2.getEstado2())return false;
            reg.setIDLote(idlote);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 11://modificar idcultivo de SIEMBRA
        {
            Siembra reg;
            int idsiembra, idcultivo;
            cout << "ID SIEMBRA: ";
            cin >> idsiembra;
            if(!reg.leerDisco(idsiembra-1)||!reg.getEstado())return false;
            cout << "NUEVO ID CULTIVO: ";
            cin >> idcultivo;
            cin.ignore();
            Cultivo reg2;
            if(!reg2.leerDisco(idcultivo-1)||!reg2.getEstado())return false;
            reg.setIDCultivo(idcultivo);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;//modificar fecha de SIEMBRA
    case 12:
        {
            Siembra reg;
            int idsiembra;
            Fecha aux;
            cout << "ID SIEMBRA: ";
            cin >> idsiembra;
            if(!reg.leerDisco(idsiembra-1)||!reg.getEstado())return false;
            cout << "NUEVA FECHA"<< endl;
            if(!aux.cargar())return false;
            cin.ignore();
            reg.setFecha(aux);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 13://modificar idSiembra de COSECHA
        {
            Cosecha reg;
            int idcosecha,idsiembra;
            cout << "ID COSECHA: ";
            cin >> idcosecha;
            if(!reg.leerDisco(idcosecha-1)||!reg.getEstado())return false;
            cout << "NUEVO ID SIEMBRA: ";
            cin >> idsiembra;
            cin.ignore();
            Siembra reg2;
            if(!reg2.leerDisco(idsiembra-1)||!reg.getEstado())return false;
            reg.setIDSiembra(idsiembra);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 14://modificar produccion de COSECHA
        {
            Cosecha reg;
            int idcosecha;
            float produccion;
            cout << "ID COSECHA: ";
            cin >> idcosecha;
            if(!reg.leerDisco(idcosecha-1)||!reg.getEstado())return false;
            cout << "NUEVA PRODUCCION: ";
            cin>>produccion;
            cin.ignore();
            reg.setProduccion(produccion);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    case 15://modificar fecha de COSECHA
        {
            Cosecha reg;
            int idcosecha;
            Fecha aux;
            cout << "ID COSECHA: ";
            cin >> idcosecha;
            if(!reg.leerDisco(idcosecha-1)||!reg.getEstado())return false;
            cout << "NUEVA FECHA"<< endl;
            if(!aux.cargar())return false;
            cin.ignore();
            reg.setFecha(aux);
            reg.escribirDisco(reg.getID()-1);
            return true;
        }
        break;
    }
    return false;
}

#endif // MODIFICAR_H_INCLUDED
