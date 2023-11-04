#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

// Método: Torneo
vector<int> Torneo(vector<int> habilidades, int N, int K) {
    queue<int> cola;
    vector<int> resultado(2);

    // Construir la cola de prioridad
    priority_queue<int, vector<int>, greater<int>> colaPrioridad;
    for (int habilidad : habilidades) {
        colaPrioridad.push(habilidad);
    }

    int juegosGanados = 0;
    int habilidadGanadora;

    // Jugar juegos hasta llegar al K
    while (juegosGanados < K) {
        int habilidadPerdedora = colaPrioridad.top();
        colaPrioridad.pop();

        if (!colaPrioridad.empty()) {
            habilidadGanadora = colaPrioridad.top();
            colaPrioridad.pop();
            juegosGanados++;

            if (juegosGanados >= N) {
                cola.push(habilidadGanadora);
                juegosGanados = 0;
            } else {
                colaPrioridad.push(habilidadGanadora);
            }
        }

        cola.push(habilidadPerdedora);
    }

    // Asignar habilidades del perdedor y ganador del juego K
    resultado[0] = cola.front();
    cola.pop();
    resultado[1] = cola.front();

    return resultado;
}

int main() {
    // Prueba 1: Caso de prueba de ejemplo
    vector<int> habilidades1 = {1, 2, 3};
    int N1 = 2;
    int K1 = 2;
    vector<int> resultado1 = Torneo(habilidades1, N1, K1);
    assert(resultado1[0] == 2);
    assert(resultado1[1] == 3);

    // Prueba 2: Caso de prueba con habilidades ordenadas en orden inverso
    vector<int> habilidades2 = {3, 2, 1};
    int N2 = 2;
    int K2 = 2;
    vector<int> resultado2 = Torneo(habilidades2, N2, K2);
    assert(resultado2[0] == 2);
    assert(resultado2[1] == 1);

    // Agrega más casos de prueba aquí...

    cout << "Todas las pruebas pasaron" << endl;
    return 0;
}
