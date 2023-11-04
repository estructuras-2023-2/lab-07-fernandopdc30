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
