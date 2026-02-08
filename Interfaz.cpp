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
