// buscas.cpp — Busca linear, binária iterativa e binária recursiva
// Seminário 02 — Estrutura de Dados II — IFTM Campus Patrocínio
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define ulli unsigned long long int
#define uli unsigned long int
#define lli long long int
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-(s)))
#define DEG_to_RAD(X) (X*PI/180)
#define F first
#define S second
#define PI 2*acos(0)
#include <iostream>
#include <utility>

// Busca linear: olha um por um. Não precisa de vetor ordenado. O(n)
int buscaLinear(vi &v, int x) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == x) return i;   // achou
    }
    return -1;                     // não achou
}

// Busca binária ITERATIVA. O vetor precisa estar ORDENADO. O(log n)
int buscaIterativa(vi &v, int x) {
    int ini = 0;
    int fim = v.size() - 1;
    int it = 1; // interações

    while (ini <= fim) {                    // ainda há candidatos
        int meio = ini + (fim - ini) / 2;   // evita overflow de (ini + fim)

        // teste de mesa: mostra o intervalo a cada iteração
        cout << "  it " << it++ << ": ini=" << ini << " fim=" << fim  << " meio=" << meio << " v[meio]=" << v[meio] << "\n";

        if (v[meio] == x) return meio;      // achou
        if (v[meio] < x) ini = meio + 1;    // x está à direita
        else             fim = meio - 1;    // x está à esquerda
    }
    return -1;                              // intervalo vazio: não achou
}

// Busca binária RECURSIVA. Mesma ideia, mas cada passo é uma nova chamada.
int buscaRecursiva(vi &v, int x, int ini, int fim) {
    if (ini > fim) return -1;               // caso base: intervalo vazio

    int meio = ini + (fim - ini) / 2;

    // teste de mesa: mostra o intervalo a cada chamada
    cout << "  busca(" << ini << ", " << fim << ") meio=" << meio << " v[meio]=" << v[meio] << "\n";

    if (v[meio] == x) return meio;          // caso base: achou
    if (v[meio] < x) return buscaRecursiva(v, x, meio + 1, fim);  // direita
    return buscaRecursiva(v, x, ini, meio - 1);                   // esquerda
}

// Busca no ESPAÇO DE RESPOSTA: menor r tal que r * r >= n.
// Não há vetor: os números de 0 a n são as respostas possíveis.
// A pergunta "r * r >= n?" é monótona: se vale para r, vale para todo
// número maior. Então procuramos onde ela COMEÇA a valer (como um lowerBound).
int menorRaiz(int n) {
    int ini = 0, fim = n;                   // a resposta está entre 0 e n
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        ll quadrado = (ll)meio * meio;      // long long: evita overflow no quadrado

        // teste de mesa: mostra o intervalo a cada iteração
        cout << "  ini=" << ini << " fim=" << fim << " r=" << meio << " r*r=" << quadrado << (quadrado >= n ? " serve" : " nao serve") << "\n";

        if (quadrado >= n) fim = meio;      // serve: a resposta é meio ou menor
        else               ini = meio + 1;  // não serve: precisa de um r maior
    }
    return ini;                             // ini == fim: primeiro r que serve
}

int main() {
    vi v = {1, 3, 5, 7, 9, 11, 13, 15};

    cout << "Linear, x = 11 -> posicao " << buscaLinear(v, 11) << "\n\n";

    cout << "Iterativa, x = 11:\n";
    int r1 = buscaIterativa(v, 11);
    cout << "  resultado: " << r1 << "\n\n";

    cout << "Iterativa, x = 6:\n";
    int r2 = buscaIterativa(v, 6);
    cout << "  resultado: " << r2 << "\n\n";

    cout << "Recursiva, x = 13:\n";
    int r3 = buscaRecursiva(v, 13, 0, v.size() - 1);
    cout << "  resultado: " << r3 << "\n\n";

    cout << "Espaco de resposta: menor r com r*r >= 30\n";
    int r4 = menorRaiz(30);
    cout << "  resultado: r = " << r4 << "\n";
    return 0;
}