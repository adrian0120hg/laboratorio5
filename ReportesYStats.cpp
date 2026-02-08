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