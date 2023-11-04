#include <vector>
#include <queue>

using namespace std;

class Tournament {
public:
    static vector<int> Torneo(vector<int> habilidades, int N, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int perdidas = 0;
        int perdido;
        int ganador;

        for (int habilidad : habilidades) {
            pq.push(habilidad);
        }

        while (true) {
            int game = 0;
            ganador = pq.top();
            pq.pop();

            while (!pq.empty()) {
                perdido = pq.top();
                pq.pop();

                if (ganador == perdido) {
                    continue;
                }

                game++;
                if (ganador > perdido) {
                    ganador += 2;
                }

                if (perdido == ganador - 2) {
                    perdidas++;
                }

                if (game == K) {
                    return {perdido, ganador};
                }

                break;
            }

            if (ganador > 0) {
                pq.push(ganador - 2);
            }
        }
    }
};
