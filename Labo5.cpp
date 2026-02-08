#include <iostream>
#include <string.h>

using namespace std;

struct Estudiante {
    int carnet;
    char nombre[50];
    float nota;
    Estudiante* izquierdo;
    Estudiante* derecho;
};

Estudiante* crearEstudiante(int carnet, char nom[], float nota) {
    Estudiante* nuevo = new Estudiante();
    nuevo->carnet = carnet;
    nuevo->nota = nota;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    int i = 0;
    while(nom[i] != '\0' && i < 49) {
        nuevo->nombre[i] = nom[i];
        i++;
    }
    nuevo->nombre[i] = '\0';
    return nuevo;
}
