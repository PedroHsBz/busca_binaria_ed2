// EXERCÍCIO 1 — Busca binária clássica e suas armadilhas
//
// Enunciado: dado um vetor ordenado de N números e Q consultas, diga a
// posição de cada número procurado ou "NAO ENCONTRADO".
//
// Código do estagiário (com 3 erros):
//     while (ini < fim) {               // ERRO 1: deveria ser <=
//         int meio = (ini + fim) / 2;   // ERRO 2: pode dar overflow
//         if (v[meio] == x) return meio;
//         else if (v[meio] < x) ini = meio;   // ERRO 3: falta o +1 (laço infinito)
//         else fim = meio - 1;
//     }
//
// Executar: ./exercicio1 < entradas/exercicio1.txt
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

// Versão CORRIGIDA — iterativa
int buscaIterativa(vi &v, int x) {
    int ini = 0, fim = v.size() - 1;
    while (ini <= fim) {                    // correção 1
        int meio = ini + (fim - ini) / 2;   // correção 2
        cout << "    ini=" << ini << " fim=" << fim << " meio=" << meio
             << " v[meio]=" << v[meio] << "\n";
        if (v[meio] == x) return meio;
        if (v[meio] < x) ini = meio + 1;    // correção 3
        else             fim = meio - 1;
    }
    return -1;
}

// Versão CORRIGIDA — recursiva
int buscaRecursiva(vi &v, int x, int ini, int fim) {
    if (ini > fim) return -1;
    int meio = ini + (fim - ini) / 2;
    cout << "    busca(" << ini << ", " << fim << ") meio=" << meio
         << " v[meio]=" << v[meio] << "\n";
    if (v[meio] == x) return meio;
    if (v[meio] < x) return buscaRecursiva(v, x, meio + 1, fim);
    return buscaRecursiva(v, x, ini, meio - 1);
}

int main() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Pré-condição: a busca binária só funciona com o vetor ORDENADO
    if (!is_sorted(v.begin(), v.end())) {
        cout << "ERRO: o vetor precisa estar ordenado\n";
        return 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << "Consulta " << x << "\n";

        cout << "  iterativa:\n";
        int p = buscaIterativa(v, x);

        cout << "  recursiva:\n";
        int r = buscaRecursiva(v, x, 0, n - 1);

        // As duas versões têm que dar a mesma resposta
        if (p != r) cout << "  ERRO: iterativa e recursiva discordam\n";

        // endl força a saída a aparecer na tela agora (esvazia o buffer)
        if (p == -1) cout << "  -> NAO ENCONTRADO\n" << endl;
        else         cout << "  -> posicao " << p << "\n" << endl;
    }
    return 0;
}