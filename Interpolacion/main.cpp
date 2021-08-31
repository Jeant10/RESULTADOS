#include <iostream>
#include <fstream>

using namespace std;

void ingresar(int a[],int n);
void inserccion(int a[], int n);

int main()
{
    int n;
    ofstream archivo;
    archivo.open("interpolacion.txt", ios::out);
    int A[7];
    cout<<"INGRESE 7 ELEMENTOS AL ARREGLO :"<<endl;
    ingresar(A,7);
    cout<<endl<<"ELEMENTO DEL ARREGLO: ";
    archivo<<endl<<"ELEMENTO DEL ARREGLO: ";

    for (int i=0; i<7; i++)
    {
        cout<<"["<<A[i]<<"]";
        archivo<<"["<<A[i]<<"]";
    }

    inserccion(A,7);

    cout<<endl<<"ELEMENTO ORDENADOS DEL ARREGLO: ";
    archivo<<endl<<"ELEMENTO ORDENADOS  ARREGLO: ";

    for (int i=0; i<7; i++)
    {
        cout<<"["<<A[i]<<"]";
        archivo<<"["<<A[i]<<"]";
    }

    cout<<endl<<"ELEMENTO A BUSCAR: ";
    cin>>n;

    int primero=0;
    int ultimo=7-1;
    int medio;
    int contador=0;
    while(A[primero]!=n && contador<7)
    {

    medio = primero + ((n-A[primero])*(ultimo-primero))/(A[ultimo]-A[primero]);

    if(A[medio]<n)
          primero = medio+1;

    else if(A[medio]>n)

          ultimo = medio-1;
    else
          primero = medio;

      contador++ ;
      break;
    }

    if(A[primero]==n)
    {
        cout<<endl<<"ELEMENTO ENCONTRADO";
        archivo<<endl<<"ELEMENTO ENCONTRADO";
    }
    else
    {
        cout<<endl<<"ELEMENTO NO ENCONTRADO";
        archivo<<endl<<"ELEMENTO NO ENCONTRADO";
    }
    archivo.close();
    return 0;
}

void ingresar(int a[],int n)
{
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
}

void inserccion(int a[], int n)
{
  int aux;
    for (int i=0; i<n; i++)
    {
        aux=a[i];
        int p=i;
        while (p>0)
        {
           if (a[p-1]>aux)
            {
                a[p]=a[p-1];
                a[p-1]=aux;
            }
            p--;
        }

    }
}

