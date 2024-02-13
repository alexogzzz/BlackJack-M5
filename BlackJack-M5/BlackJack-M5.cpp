#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para obtener un valor de carta aleatorio

int obtenerCarta() {
    return rand() % 9 + 2; // Cartas del 2 al 10
}

// Función para calcular la puntuación de una mano

int calcularPuntuacion(int mano[], int tamano) {

    int puntuacion = 0;
    int ases = 0;


    for (int i = 0; i < tamano; i++) {

        if (mano[i] == 11) {
            ases++;
        }
        puntuacion += mano[i];
    }


    while (puntuacion > 21 && ases > 0) {

        puntuacion -= 10;
        ases--;
    }


    return puntuacion;

}

int main() {

    srand(time(0));

    int jugador[10]; // Almacena las cartas del jugador

    int croupier[10]; // Almacena las cartas del croupier


    int tamanoJugador = 2; // Inicia al jugador con dos cartas

    int tamanoCroupier = 1; // Inicia al croupier con una carta


    // Inicializa las cartas del jugador

    jugador[0] = obtenerCarta();
    jugador[1] = obtenerCarta();


    // Inicializa las cartas del croupier

    croupier[0] = obtenerCarta();


    cout << "Bienvenido al Blackjack" << endl;


    // Juego del jugador

    while (true) {

        // Mostrar cartas del croupier

        cout << "Carta del croupier: " << croupier[0] << endl;

        cout << "Tus cartas: ";

        for (int i = 0; i < tamanoJugador; i++) {

            cout << jugador[i] << " ";
        }


        cout << "\nPuntuacion: " << calcularPuntuacion(jugador, tamanoJugador) << endl;


        if (calcularPuntuacion(jugador, tamanoJugador) == 21) {

            cout << "Blackjack Ganaste" << endl;

            break;
        }
        else if (calcularPuntuacion(jugador, tamanoJugador) > 21) {

            cout << "Te has pasado de 21. Perdiste" << endl;

            break;
        }


        char opcion;

        cout << "Quieres pedir una carta? (s/n): ";
        cin >> opcion;

        if (opcion == 's') {
            jugador[tamanoJugador] = obtenerCarta();
            tamanoJugador++;
        }

        else if (opcion == 'n') {
            break;
        }
    }


    // Juego del croupier
    cout << "\nTurno del croupier:" << endl;
    while (calcularPuntuacion(croupier, tamanoCroupier) < 17) {

        croupier[tamanoCroupier] = obtenerCarta();

        tamanoCroupier++;

        // Mostrar cartas del croupier durante su turno

        cout << "Cartas del croupier: ";

        for (int i = 0; i < tamanoCroupier; i++) {
            cout << croupier[i] << " ";
        }

        cout << "\nPuntuacion del croupier: " << calcularPuntuacion(croupier, tamanoCroupier) << endl;

    }

    // Determinar el resultado del juego
    int puntuacionJugador = calcularPuntuacion(jugador, tamanoJugador);
    int puntuacionCroupier = calcularPuntuacion(croupier, tamanoCroupier);

    if (puntuacionJugador == puntuacionCroupier) {
        cout << "Empate" << endl;
    }
    else if (puntuacionJugador > puntuacionCroupier && puntuacionJugador <= 21) {
        cout << "Gano el jugador" << endl;
    }
    else if (puntuacionCroupier > 21){
        cout << "Gano el juagador" << endl;
    }
    else {
        cout << "Gano el coupier" << endl;
    }

    return 0;
}
