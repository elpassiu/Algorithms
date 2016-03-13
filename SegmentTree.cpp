#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[1000000], seg[4000000];                       // v es l'array base i seg el vector segment tree;
int n;

void build(int x, int y, int node) {                // constructor: x, y = interval en el que estic; node = node en el que estic
    if (x == y) seg[node] = v[x];                   // si x == y estic a una fulla => en aquest node el valor es el de l'array base
    else {
        build (x, (x+y)/2, 2*node);                 // contrueixo el subarbre que surt d'aquest node i poso a seg[node] el maxim del subarbre
        build ((x+y)/2 + 1, y, 2*node + 1);
        seg[node] = max (seg[2*node], seg[2*node + 1]);
    }
}

int query(int a, int b, int x, int y, int node) {   // buscador de maxim: a i b es l'interval que busco; x i y es en el que estic
    if (a <= x and b >= y) return seg[node];        // si en el que estic esta inclos en el que busco, en retorno el maxim
    if (b < x or a > y) return 0;                   // si en el que estic es disjunt del que busco, retorno 0
    return max (query(a, b, x, (x+y)/2, 2*node), query(a, b, (x+y)/2 + 1, y, 2*node+1)); // si no es cap de les interiors (vol dir que esta mig inclos,
                                                                                         // crido al subarbre
}

void actualitza (int x, int y, int node, int pos, int valor) { // actualitzador: x, y es l'interval en que estic; node es el node on soc; pos = posicio
    if (x == y and x == pos) {                                  // que vull actualitzar; valor = valor que hi vull posar
        v[pos] = valor;                                         // si x == y == pos ja he estic a la fulla => a aquest node hi poso el nou valor i
        seg[node] = valor;                                      // a l'array base tambe
    }
    else if (x <= pos and pos <= y) {                           // si pos esta a linterval x, y actualitzo el subarbre i al node hi poso el maxim de les
        actualitza (x, (x+y)/2, 2*node, pos, valor);            // dues branques
        actualitza ((x+y)/2 + 1, y, 2*node + 1, pos, valor);
        seg[node] = max (seg[2*node], seg[2*node + 1]);
    }
}
int main() {
    
}
