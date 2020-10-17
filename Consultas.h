#ifndef CONSULTAS_H_INCLUDED
#define CONSULTAS_H_INCLUDED

void consulta(int opt){
    switch(opt){
    case 1://busca campo por ubicacion
        {
         Campo reg;Ubicacion aux;int pos=0;

         aux.cargar();
        encabezados(1);
            while(reg.leerDisco(pos++)){
            if(reg.getUbicacion()==aux){
                reg.mostrar();
            }
         }
        }
    break;
    case 2://buscar cultivo por nombre
        {
        Cultivo reg;int pos=0;char aux[50];
        cout << "NOMBRE: ";
        cin.getline(aux,50);
    encabezados(3);
        while(reg.leerDisco(pos++)){
            if(strcmp(aux,reg.getNombre())==0){
                reg.mostrar();
            }
        }
        }
    break;;
    case 3://buscar cultivo por nombre cientifico
        {
        Cultivo reg;int pos=0;char aux[50];
        cout << "NOMBRE CIENTIFICO: ";

        cin.getline(aux,50);
    encabezados(3);
        while(reg.leerDisco(pos++)){
            if(strcmp(aux,reg.getNombrecien())==0){
                reg.mostrar();
            }
        }
        }
    break;
    case 4://buscar cultivo por rango de precio
        {
        Cultivo reg;int pos=0;float max,min;
        cout << "PRECIO MAX: ";
        cin >> max;
        cout << "PRECIO MIN: ";
        cin >> min;
        cin.ignore();
    encabezados(3);
        while(reg.leerDisco(pos++)){
            if((reg.getPrecio()<max)&&(reg.getPrecio()>min)){
                reg.mostrar();
            }
        }
        }
    break;
    case 5://buscar Siembra por cultivo
        {
            Siembra reg; int pos=0;int idcultivo;
            cout << "ID PLANTA: ";
            cin >> idcultivo;
    cin.ignore();
    encabezados(4);
            while(reg.leerDisco(pos++)){
                if(reg.getIDCultivo()==idcultivo){
                    reg.mostrar();
                }
            }
        }
        break;
    case 6://buscar siembra por lote
        {
            Siembra reg;int pos=0;int idlote;
            cout << "ID LOTE: ";
            cin >> idlote;
    cin.ignore();
    encabezados(4);
            while(reg.leerDisco(pos++)){
                if(reg.getIDLote()==idlote){
                    reg.mostrar();
                }
            }
        }
        break;
    case 7://buscar cosecha por cultivo
        {
            Cosecha reg;int pos=0;int idcultivo;Siembra aux;
            cout << "ID CULTIVO: ";
            cin >> idcultivo;
    cin.ignore();
    encabezados(5);
            while(reg.leerDisco(pos++)){
                    aux.leerDisco(reg.getIDSiembra());
                    if(aux.getIDCultivo()==idcultivo){
                        reg.mostrar();

                }
            }
        }
        break;
    case 8://buscar cosechas por lote
        {
            Cosecha reg;int pos=0;int idlote;
            Siembra reg2;
            cout << "ID LOTE: ";
            cin >> idlote;
    cin.ignore();
    encabezados(5);
            while(reg.leerDisco(pos++)){
                reg2.leerDisco(reg.getIDSiembra()-1);
                    if(reg2.getIDLote()==idlote){
                        reg.mostrar();
                    }
            }
        }///NUEVOS
         break;
    case 9://buscar por nombre de CAMPO
        {
            Campo reg;int pos=0;char nombre[50];
            cout << "NOMBRE: ";

            cin.getline(nombre,50);
            encabezados(1);
            while(reg.leerDisco(pos++)){
                if(strcmp(reg.getNombre(),nombre)==0){
                    reg.mostrar();
                }
            }
        }
        break;
    case 10://buscar por tamaño de CAMPO
        {
            Campo reg;int pos=0;float tam;
            cout << "TAMANO: ";
            cin >> tam;
    cin.ignore();
            encabezados(1);
            while(reg.leerDisco(pos++)){
                if(reg.getTam()==tam){
                    reg.mostrar();
                }
            }
        }
        break;
    case 11://buscar lote por ID CAMPO
        {
            Lote reg;int pos=0;int IDCampo;
            cout << "ID CAMPO: ";
            cin >> IDCampo;
    cin.ignore();
    encabezados(2);
            while(reg.leerDisco(pos++)){
                if(reg.getIDCampo()==IDCampo){
                    reg.mostrar();
                }
            }
        }
        break;
    case 12://buscar lote por tamaño
        {
            Lote reg;int pos=0;float tam;
            cout << "TAMANO DEL LOTE: ";
            cin >> tam;
    cin.ignore();
    encabezados(2);
            while(reg.leerDisco(pos++)){
                if(reg.getTam()==tam){
                    reg.mostrar();
                }
            }
        }
        break;
    case 13://buscar siembra por fecha
        {
            Fecha date;
            Siembra reg;
            int pos=0;
            cout << "FECHA " << endl;
            cin >> date;
    cin.ignore();
    encabezados(4);
            while(reg.leerDisco(pos++)){
                if(reg.getFecha()==date){
                    reg.mostrar();
                }
            }
        }
        break;
    case 14://buscar cosecha por fecha
        {
            Fecha date;
            Cosecha reg;
            int pos=0;
            cout << "FECHA " << endl;
            cin >> date;
    cin.ignore();
    encabezados(5);
            while(reg.leerDisco(pos++)){
                if(reg.getFecha()==date){
                    reg.mostrar();
                }
            }
        }
        break;
    }
}

#endif // CONSULTAS_H_INCLUDED
