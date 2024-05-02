#include<iostream>
#include<ctype.h>
#include<cstring>
using namespace std;
//Declaración de funciones
int CuentaTodo(const char*);
int CuentaLetras(const char*);
int CuentaEspacios(const char*);
int CuentaNumeros(const char*);
int CuentaSimbolos(const char*);
void imprimirTexto(const char*);
void TextoArriba(char*);
char* pSubSeccion(const char*, int , int);
//Cuerpo principal
int main(){
    char cCadena[]="Hola 1 mundito, te la comes, dobalda y con 745 nudos.";
    char* pCadena=cCadena;
    char* pSubArreglo=pSubSeccion(pCadena,4,10);
    imprimirTexto(pCadena);
    imprimirTexto(pSubArreglo);
    int (*pFuncion[])(const char*)={CuentaTodo,CuentaLetras,CuentaEspacios,CuentaNumeros,CuentaSimbolos};
    int iCadena=pFuncion[0](pCadena);
    int iLetras=pFuncion[1](pCadena);
    int iEspacios=pFuncion[2](pCadena);
    int iNumeros=pFuncion[3](pCadena);
    int iSimbolos=pFuncion[4](pCadena);
    
    TextoArriba(pCadena);

    imprimirTexto(pCadena);
    cout<<"Cadena: "<<iCadena<<"-"<<sizeof(cCadena)/sizeof(cCadena[0])<<endl;
    cout<<"Letras: "<<iLetras<<endl;
    cout<<"Espacios: "<<iEspacios<<endl;
    cout<<"Numeros: "<<iNumeros<<endl;
    cout<<"Simbolos: "<<iSimbolos<<endl;
    return 0;
}
char* pSubSeccion(const char*pCadena, int iInicio, int iFin){
    char *pCadTemp=new char[1+iFin-iInicio];
    int iLongitud=iFin-iInicio;

    for (int i = 0; i < iLongitud; i++)
    {
        *pCadTemp=*(pCadena+(iInicio+i));
        pCadTemp++;
    }

    return pCadTemp;
    
}
void TextoArriba(char* pCadena){
    
    while (*pCadena!='\0')
    {
        *pCadena=toupper(*pCadena);
        pCadena++;
    }
}

void imprimirTexto(const char* pCadena){
    while (*pCadena!='\0')
    {
        cout<<*pCadena;
        pCadena++;
    }
    cout<<endl;
}
int CuentaTodo(const char* pCadena){
    int iContador=0;
    while (*pCadena!='\0')
    {
        iContador++;
        pCadena++;
    }
    return iContador;
}

int CuentaLetras(const char* pCadena){
    int iContador=0;
    while (*pCadena!='\0')
    {
        if (isalpha(*pCadena))
        {
            iContador++;
        }
        pCadena++;
    }
    return iContador;
}

int CuentaEspacios(const char* pCadena){
    int iContador=0;
    while (*pCadena!='\0')
    {
        if (isspace(*pCadena))
        {
            iContador++;
        }
        pCadena++;
    }
    return iContador;
}

int CuentaNumeros(const char* pCadena){
    int iContador=0;
    while (*pCadena!='\0')
    {
        if (isdigit(*pCadena))
        {
            iContador++;
        }
        pCadena++;
    }
    return iContador;
}

int CuentaSimbolos(const char* pCadena){
    int iContador=0;
    iContador=CuentaTodo(pCadena)-CuentaLetras(pCadena)-CuentaEspacios(pCadena)-CuentaNumeros(pCadena);
    return iContador;
}
