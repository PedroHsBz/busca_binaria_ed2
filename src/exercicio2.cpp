// EXERCÍCIO 2 — Variante avançada: lower_bound e upper_bound
//
// Enunciado: as notas da turma estão em ordem crescente, com notas repetidas.
// Para cada nota consultada, diga quantos alunos tiraram essa nota,
// em O(log n), sem percorrer as notas repetidas.
//
// lowerBound(x) = primeira posição com v[i] >= x  (onde a nota começa)
// upperBound(x) = primeira posição com v[i] >  x  (logo depois de onde termina)
// quantidade    = upperBound(x) - lowerBound(x)
//
// Executar: ./exercicio2 < entradas/exercicio2.txt
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

// Primeira posição com v[i] >= x
int lowerBound(vi &v, int x) {
    int ini = 0, fim = v.size();       // fim fica DE FORA: [ini, fim)
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        cout << "    lower: ini=" << ini << " fim=" << fim << " meio=" << meio
             << " v[meio]=" << v[meio] << "\n";
        if (v[meio] < x) ini = meio + 1;
        else             fim = meio;   // meio pode ser a resposta
    }
    return ini;
}

// Primeira posição com v[i] > x  (só muda o < para <=)
int upperBound(vi &v, int x) {
    int ini = 0, fim = v.size();
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        cout << "    upper: ini=" << ini << " fim=" << fim << " meio=" << meio
             << " v[meio]=" << v[meio] << "\n";
        if (v[meio] <= x) ini = meio + 1;
        else              fim = meio;
    }
    return ini;
}

int main() {
    int n;
    cin >> n;
    vi notas(n);
    for (int i = 0; i < n; i++) cin >> notas[i];

    // Pré-condição: o vetor precisa estar ordenado
    if (!is_sorted(notas.begin(), notas.end())) {
        cout << "ERRO: as notas precisam estar ordenadas\n";
        return 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << "Nota " << x << "\n";
        int lb = lowerBound(notas, x);
        int ub = upperBound(notas, x);
        cout << "  -> lower=" << lb << " upper=" << ub
             << " -> " << ub - lb << " aluno(s)\n\n";
    }
    return 0;
}
