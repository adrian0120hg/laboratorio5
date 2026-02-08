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
Estudiante* insertar(Estudiante* raiz, int carnet, char nombre[], float nota) {
    if (raiz == NULL) return crearEstudiante(carnet, nombre, nota);
    if (carnet < raiz->carnet) {
        raiz->izquierdo = insertar(raiz->izquierdo, carnet, nombre, nota);
    } else if (carnet > raiz->carnet) {
        raiz->derecho = insertar(raiz->derecho, carnet, nombre, nota);
    }
    return raiz;
}

void buscarEstudiante(Estudiante* raiz, int carnet) {
    if (raiz == NULL) {
        cout << "Estudiante no encontrado." << endl;
        return;
    }
    if (raiz->carnet == carnet) {
        cout << "Encontrado: " << raiz->nombre << " - Nota: " << raiz->nota << endl;
    } else if (carnet < raiz->carnet) {
        buscarEstudiante(raiz->izquierdo, carnet);
    } else {
        buscarEstudiante(raiz->derecho, carnet);
    }
}
void mostrarEstudiantes(Estudiante* raiz) {
    if (raiz != NULL) {
        mostrarEstudiantes(raiz->izquierdo);
        cout << "Carnet: " << raiz->carnet << " | Nombre: " << raiz->nombre << " | Nota: " << raiz->nota << endl;
        mostrarEstudiantes(raiz->derecho);
    }
}

void mostrarAprobados(Estudiante* raiz) {
    if (raiz != NULL) {
        mostrarAprobados(raiz->izquierdo);
        if (raiz->nota >= 6.0) cout << "Aprobado: " << raiz->nombre << " (" << raiz->nota << ")" << endl;
        mostrarAprobados(raiz->derecho);
    }
}

void mostrarReprobados(Estudiante* raiz) {
    if (raiz != NULL) {
        mostrarReprobados(raiz->izquierdo);
        if (raiz->nota < 6.0) cout << "Reprobado: " << raiz->nombre << " (" << raiz->nota << ")" << endl;
        mostrarReprobados(raiz->derecho);
    }
}

float sumarNotas(Estudiante* raiz, int* contador) {
    if (raiz == NULL) return 0;
    (*contador)++;
    return raiz->nota + sumarNotas(raiz->izquierdo, contador) + sumarNotas(raiz->derecho, contador);
}

Estudiante* encontrarMejorNota(Estudiante* raiz) {
    if (raiz == NULL) return NULL;
    Estudiante* mejor = raiz;
    Estudiante* izq = encontrarMejorNota(raiz->izquierdo);
    Estudiante* der = encontrarMejorNota(raiz->derecho);
    if (izq != NULL && izq->nota > mejor->nota) mejor = izq;
    if (der != NULL && der->nota > mejor->nota) mejor = der;
    return mejor;
}
