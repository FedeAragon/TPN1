#ifndef ENCABEZADOS_H_INCLUDED
#define ENCABEZADOS_H_INCLUDED

void encabezados(int opt){
    switch(opt){
    case(1):
        {
            cout << left;
            cout << setw(4) << "ID";
            cout << setw(strlen2(1)) << "NOMBRE";
            cout << setw(16) << "OCUPADO/TAMANO";
            cout << setw(strlen2(2)+strlen2(3)+strlen2(4)) << "UBICACION";
            cout << endl << "--------------------------------------------------------------------------" << endl;

        }
        break;
    case(2):
        {
            cout << left;
            cout << setw(8) << "IDLOTE";
            cout << setw(9) << "IDCAMPO";
            cout << setw(10) << "TAMANO";
            cout << setw(20) << "ESTADO(PLANTADO/VACIO)";
            cout << endl << "-------------------------------------------------" << endl;
        }
        break;
    case(3):
        {
            cout << left;
            cout << setw(4) << "ID";
            cout << setw(strlen2(5)) << "NOMBRE";
            cout << setw(strlen2(6)) << "NOMBRE CIENTIFICO";
            cout << setw(18) << "STOCK(TONELADAS)";
            cout << setw(6) << "TIPO";
            cout << setw(20) << "PRECIO POR TONELADA";
            cout << endl << "-------------------------------------------------------------------------------" << endl;
        }
        break;
    case(4):
        {
            cout << left;
            cout << setw(11) << "IDSIEMBRA";
            cout << setw(9) << "IDCAMPO";
            cout << setw(8) << "IDLOTE";
            cout << setw(11) << "IDCULTIVO";
            cout << setw(12) << "FECHA";
            cout << endl << "--------------------------------------------------" << endl;
        }
        break;
    case(5):
        {
            cout << left;
            cout << setw(11) << "IDCOSECHA";
            cout << setw(11) << "IDSIEMBRA";
            cout << setw(12) << "PRODUCCION";
            cout << setw(12) << "FECHA";
            cout << endl << "---------------------------------------------" << endl;
        }
        break;
    }
}


#endif // ENCABEZADOS_H_INCLUDED
