#include <iostream>
using namespace std;

int main() {
    // Inicialització de les piles amb 3, 4 i 5 pedres respectivament
    int piles[] = { 3, 4, 5 };
    int jugadorActual = 1; // Variable que indica el jugador actual, comença amb el jugador 1

    cout << "INICI DEL JOC" << endl;

    // Bucle principal del joc
    while (true) {
        // Mostra l'estat actual de les piles
        cout << "Estat Actual del Joc -> ";
        for (int i = 0; i < 3; ++i) {
            cout << piles[i] << " ";
        }
        cout << endl;

        // Torn del jugador
        cout << (jugadorActual == 1 ? "JUGADOR1" : "JUGADOR2") << " retira pedres de la pila amb index: ";
        int indexPila;
        cin >> indexPila;

        // Verifica la validesa de l'índex
        if (indexPila < 0 || indexPila >= 3 || piles[indexPila] == 0) {
            cout << "Moviment invalid. Torna-ho a provar." << endl;
            continue; // Salta a la següent iteració del bucle
        }

        // Sol·licita al jugador que introdueixi el nombre de pedres a treure (1-3)
        cout << "Introdueix el nombre de pedres a treure (1-3): ";
        int pedresARemoure;
        cin >> pedresARemoure;

        // Verifica la validesa de la quantitat de pedres a treure
        if (pedresARemoure < 1 || pedresARemoure > 3 || pedresARemoure > piles[indexPila]) {
            cout << "Nombre de pedres invalid. Torna-ho a provar." << endl;
            continue; // Salta a la següent iteració del bucle
        }

        // Actualitza la quantitat de pedres a la pila seleccionada
        piles[indexPila] -= pedresARemoure;

        // Verifica si el jugador actual ha guanyat
        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0) {
            cout << (jugadorActual == 1 ? "JUGADOR1" : "JUGADOR2") << " ha guanyat" << endl;
            break; // Finalitza el bucle
        }

        // Canvia al següent jugador
        jugadorActual = 3 - jugadorActual; // Alternar entre 1 i 2
    }

    return 0;
}