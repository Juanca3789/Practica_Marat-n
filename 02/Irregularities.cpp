#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
using namespace std;

class Grafo {
	private:
		int numVertices;
		vector<list<pair<int, int>>> listaAdyacencia;
	public:
		Grafo(int _numVertices);
		void agregarArco(int origen, int destino, int peso);
		vector<int> dijikstra(int origen);
};

Grafo::Grafo(int _numVertices) {
	this->numVertices = _numVertices;
	this->listaAdyacencia.resize(_numVertices);
}

void Grafo::agregarArco(int origen, int destino, int peso) {
	this->listaAdyacencia[origen].push_back(make_pair(destino, peso));
}

vector<int> Grafo::dijikstra(int origen) {
	vector<int> distancia(this->numVertices, numeric_limits<int>::max());
	distancia[origen] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, origen));
	while(!pq.empty()) {
		int distActual = pq.top().first;
		int verticeActual = pq.top().second;
		pq.pop();
		for(auto& adyacente : this->listaAdyacencia[verticeActual]) {
			int destino = adyacente.first;
			int peso = adyacente.second;
			if(distActual + peso < distancia[destino]) {
				distancia[destino] = distActual + peso;
				pq.push(make_pair(distancia[destino], destino));
			}
		}
	}
	return distancia;
}


/* Prueba dijikstra
int main() {
	Grafo prueba = Grafo(7);
	prueba.agregarArco(0, 1, 2);
	prueba.agregarArco(0, 2, 6);
	prueba.agregarArco(1, 3, 5);
	prueba.agregarArco(2, 3, 8);
	prueba.agregarArco(3, 5, 15);
	prueba.agregarArco(3, 4, 10);
	prueba.agregarArco(4, 5, 6);
	prueba.agregarArco(4, 6, 2);
	prueba.agregarArco(5, 6, 6);
	vector<int> dijikstra = prueba.dijikstra(0);
	for(int i = 0; i < 7; i++){
		cout<<"Distancia minima del nodo 0 al nodo "<<i<<":"<<dijikstra[i]<<endl;
	}
}
*/

int timeToCity(int ri, int rj, int tj, int m) {
	return ri > rj + m ? tj + 1 : 1;
}

int main() {
	int n, q, m;
	cin>>n;
	cin>>q;
	cin>>m;
	Grafo ciudades = Grafo(n);
	vector<int> rvalue;
	rvalue.resize(n);
	for(int i = 0; i < n; i++){
		cin>>rvalue[i];
	}
	vector<int> quarantineTime;
	quarantineTime.resize(n);
	for(int i = 0; i < n; i++){
		cin>>quarantineTime[i];
	}
	for(int origen = 0; origen < n; origen++){
		for(int destino = 0; destino < n; destino++){
			ciudades.agregarArco(origen, destino, timeToCity(rvalue[origen], rvalue[destino], quarantineTime[destino], m));
		}
	}
	for(int i = 0; i < q; i++){
		int x, y;
		cin>>x;
		cin>>y;
		x--;
		y--;
		vector<int> dijikstra = ciudades.dijikstra(x);
		cout<<dijikstra[y]<<endl;
	}
}
