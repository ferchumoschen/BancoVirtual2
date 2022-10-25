//Codificado por; sAfOrAs
//Depositos
int main();

#include<iostream>
#include <cstdlib>
using namespace std;

double saldo(double retiro,double deposito,double saldot)
{

    system("cls");
    saldot=saldot+deposito-retiro;
    return saldot;


}

double deposit(double saldot)
{

    double dep=0;
    char sn;
    do
    {
LDeposito:
    system("cls");
    cout<<"Ingrese cantidad a Depositar: ";
    cin>>dep;

    while(dep<=0)
    {
        cout<<"Desea ingresar un valor valido s/S n/N: ";
        cin>>sn;
        if(sn=='S'||sn=='s')
            goto LDeposito;
        else
            exit(0);
    }
    saldot=saldo(0,dep,saldot);
    cout<<"Desea realizar otro deposito s/S n/N: ";cin>>sn;
    }while(sn=='s'||sn=='S');

return saldot;
}

double retiro(double saldot)
{
    double retir=0;
        char sn;
        system("cls");
        if (saldot==0)
        {cout<<"Ud. no cuenta con saldo \n";
            cout<<"Desea realizar otra operacion s/S n/N: ";cin>>sn;
            if(sn=='S'||sn=='s')
            {
            system("cls");
            main();
            }
            else
            exit(0);

        }
        do
        {
            LRetir:
            system("cls");
            cout<<"Ingrese cantidad a Retirar: ";
            cin>>retir;

            while(saldot<retir)
            {
                cout<<"Ud. no cuenta con saldo suficiente para hacer ese retiro\n";
                goto reintentar;
            }

            while(retir<=0)
            {
            reintentar:
                cout<<"Desea ingresar un valor valido s/S n/N: ";
                cin>>sn;
                if(sn=='S'||sn=='s')
                    goto LRetir;
                else
                    exit(0);
            }
            saldot=saldo(retir,0,saldot);
            cout<<"Desea realizar otro retiro s/S n/N: ";cin>>sn;
        }while(sn=='s'||sn=='S');

return saldot;
}



double Option(int option1,double saldot)
{
    switch(option1)
    {
    case 1:saldot=deposit(saldot);break;
    case 2:saldot=retiro(saldot);break;
    case 3: {
            saldot=saldo(0,0,saldot);
            cout<<"Usted cuenta con :"<<saldot<<" dolares\n";
            }break;
    case 4:{system("cls");cout<<"Cerrando Sistema...";exit(0);}break;

    }


return saldot;
}


int main()
{
    int opt;
    char sn;
    double saldot=0;

    do
    {
    system("cls");
    cout<<"\t\t\tOperaciones Bancarias\n";
    cout<<"1. Deposito\n";
    cout<<"2. Retiro\n";
    cout<<"3. Saldo\n";
    cout<<"4. Salir\n\n";
    cout<<"Elija el numero de la opcion: ";cin>>opt;
    saldot=Option(opt,saldot);
    cout<<"Desea continuar con otra operacion s/S n/N: ";cin>>sn;
    }while(sn=='s'||sn=='S');
    system("cls");
    cout<<"Cerrando Sistema...\n";exit(0);
    return 0;
}
