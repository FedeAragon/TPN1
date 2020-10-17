#ifndef LISTADOS_H_INCLUDED
#define LISTADOS_H_INCLUDED

void listado(int opt){
    int pos=0;
    switch(opt){
case 1://ordenar por tamaño de campo
    {
    Campo *p,reg,aux;
    int tam=contarRegistros(1);
    //crear vector
    p=new Campo[tam];
    if(p==NULL)exit(-303);
    //cargar vector
    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }
    //odernar por tamaño de campo
    for(int i=0;i < contarRegistros(1); i++){
        for(int j=0;j < contarRegistros(1)-1;j++){
            if(p[j].getTam()<p[j+1].getTam()){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }
    //mostrar
    encabezados(1);
    for(int h=0;h<contarRegistros(1);h++){
        p[h].mostrar();
    }
    //liberar
    delete(p);

    break;
    }
case 2://ordenar cultivo por nombre
    {
    Cultivo *p,reg,aux;

    p=new Cultivo[contarRegistros(3)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(3); i++){
        for(int j=0;j < contarRegistros(3)-1;j++){
            if(strcmp(p[j].getNombre(),p[j+1].getNombre())==1){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(3);
    for(int h=0;h<contarRegistros(3);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
case 3://ordenar cultivo por precio
    {
    Cultivo *p,reg,aux;

    p=new Cultivo[contarRegistros(3)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(3); i++){
        for(int j=0;j < contarRegistros(3)-1;j++){
            if(p[j].getPrecio()<p[j+1].getPrecio()){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(3);
    for(int h=0;h<contarRegistros(3);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
case 4://ordenar Cosechas por produccion
    {
    Cosecha *p,reg,aux;

    p=new Cosecha[contarRegistros(5)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(5); i++){
        for(int j=0;j < contarRegistros(5)-1;j++){
            if(p[j].getProduccion()<p[j+1].getProduccion()){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(5);
    for(int h=0;h<contarRegistros(5);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
case 5://ordenar Cosechas por fecha
    {
    Cosecha *p,reg,aux;Fecha a,b;

    p=new Cosecha[contarRegistros(5)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(5); i++){
        for(int j=0;j < contarRegistros(5)-1;j++){
            a=p[j+1].getFecha();
            b=p[j].getFecha();
            if(a>b){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(5);
    for(int h=0;h<contarRegistros(5);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
case 6://ordenar Siembra por fecha
    {
    Siembra *p,reg,aux;Fecha a,b;

    p=new Siembra[contarRegistros(4)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(4); i++){
        for(int j=0;j < contarRegistros(4)-1;j++){
            a=p[j+1].getFecha();
            b=p[j].getFecha();
            if(a>b){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(4);
    for(int h=0;h<contarRegistros(4);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }///NUEVOS
case 7://ordenar CAMPOS por NOMBRE
    {
    Campo *p,reg,aux;

    p=new Campo[contarRegistros(1)];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(1); i++){
        for(int j=0;j < contarRegistros(1)-1;j++){
            if(strcmp(p[j].getNombre(),p[j+1].getNombre())==1){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(1);
    for(int h=0;h<contarRegistros(1);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
case 8://ordenar por tamaño de LOTE
    {
    Lote *p,reg,aux;
    int tam=contarRegistros(2);
    p=new Lote[tam];
    if(p==NULL)exit(-303);

    while(reg.leerDisco(pos)){
        p[pos]=reg;
        pos++;
    }

    for(int i=0;i < contarRegistros(2); i++){
        for(int j=0;j < contarRegistros(2)-1;j++){
            if(p[j].getTam()<p[j+1].getTam()){
                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;
            }
        }
    }

    encabezados(2);
    for(int h=0;h<contarRegistros(2);h++){
        p[h].mostrar();
    }

    delete(p);

    break;
    }
    }
}


#endif // LISTADOS_H_INCLUDED
