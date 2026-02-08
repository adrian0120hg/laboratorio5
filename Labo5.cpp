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
int main() {
    Estudiante* sistema = NULL;
    int opcion, carnetTmp;
    char nombreTmp[50];
    float notaTmp;
    do {
        cout << "\n===== SISTEMA DE GESTION DE ESTUDIANTES =====\n";
        cout << "1. Agregar\n2. Mostrar todos\n3. Buscar\n4. Aprobados\n5. Reprobados\n6. Promedio\n7. Mejor nota\n8. Salir\nOpcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "Carnet: "; cin >> carnetTmp;
                cout << "Nombre: "; cin.ignore(); cin.getline(nombreTmp, 50);
                cout << "Nota: "; cin >> notaTmp;
                sistema = insertar(sistema, carnetTmp, nombreTmp, notaTmp);
                break;
            case 2: mostrarEstudiantes(sistema); break;
            case 3:
                cout << "Carnet a buscar: "; cin >> carnetTmp;
                buscarEstudiante(sistema, carnetTmp);
                break;
            case 4: mostrarAprobados(sistema); break;
            case 5: mostrarReprobados(sistema); break;
            case 6: {
                int contador = 0;
                float suma = sumarNotas(sistema, &contador);
                if (contador > 0) cout << "Promedio: " << (suma / contador) << endl;
                break;
            }
            case 7: {
                Estudiante* mejor = encontrarMejorNota(sistema);
                if (mejor) cout << "Mejor: " << mejor->nombre << " (" << mejor->nota << ")" << endl;
                break;
            }
        }
    } while(opcion != 8);
    return 0;
}
