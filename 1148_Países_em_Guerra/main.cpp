#include<iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cfloat>
using namespace std;

class Edge;
class Node{
public:
    Node(int num){
    this->label = num;
    this->adjacency = set<Edge *>();
    }
    int getLabel(){//retorna nome do vertice
    return this->label;
    }
private:
    int label; //rotulo (identificador) do vertice num da cidade
    set<Edge *> adjacency; //lista de vertices adjacentes
    friend class Graph;
};

class Edge{
public:
    Edge(Node* s, Node* f, double w){
    this->start = s;
    this->finish = f;
    this->weight = w;
    }
private:
    Node* start; //vertice de inicio da aresta
    Node* finish; //vertice de fim da aresta
    double weight; //peso da aresta do grafo, horas demoradas
    friend class Graph;
};

class Graph{
public:
    Graph(bool directed){
    this->directed = directed;
    this->nodeMap = std::map<int, Node *>();
    this->nodes = std::set<Node *>();
    this->edges = std::set<Edge *>();
    }
    void addNode(int name){
    Node *tmp = new Node(name);
    this->nodes.insert(tmp);
    this->nodeMap[name] = tmp;
    }
    void addEdge(int label1, int label2, double weight){//adiciona aresta entre vertices de rotulo label1 e label2
    Node *n1 = this->nodeMap[label1];//busca os dois vertices no mapa pelos seus labels
    Node *n2 = this->nodeMap[label2];
    this->createEdge(n1, n2, weight);//cria aresta entre os vertices
    }
    void zerapeso(){//função para zerar o peso das arestas que ligam duas cidades no mesmo país
    for(Node * v : this->nodes){//pecorre todos os vertices
        for(Edge *arc : v->adjacency){//pecorre todos os adjacntes de cada vertice
        for(Edge *arb : arc->finish->adjacency){//pecorre todos os adjacentes da ponta final de cada caminho de cada node
            if(arc->finish == arb->start && arb->finish == arc->start){//se o finish de um for o start do outro e vice versa
            arc->weight = 0;
            arb->weight = 0;
            }
        }
        }
    }
    }
    double findShortestPath(int initLabel, int finLabel){//procura caminho minimo entre dois vertices
    Node *start = this->nodeMap[initLabel];
    Node *fim = this->nodeMap[finLabel];
    return this->dijkstra(start, fim);
    }
private:
    void createEdge(Node* s, Node* f, double weight){
    Edge *e = new Edge(s, f, weight);
    this->edges.insert(e);//insere nova aresta no conjunto de arestas do grafo
    s->adjacency.insert(e);//seta vertice f como adjacente ao vertice s
    }

    double dijkstra(Node* start, Node* fim){
    std::map<int, double> currDist;
    std::set<Node *> toBeChecked; //todos os nos de G sao copiados para toBeChecked

    for(Node * v : this->nodes){
        currDist[v->label] = DBL_MAX; //inicializa com distancia "infinita"
        toBeChecked.insert(v);
    }

    Node* first = start;
    currDist[first->label] = 0; //no inicial tem distancia 0

    while (!toBeChecked.empty()) { 
        Node *v = *toBeChecked.begin();
        for(Node *next : toBeChecked)//busca vertice v de menor custo/distancia
        if(currDist[next->label] < currDist[v->label])
            v = next;
        toBeChecked.erase(v); //tira v do conj. a checar
        for(Edge *arc : v->adjacency) //para toda aresta adjacente de v
        if(toBeChecked.find(arc->finish) != toBeChecked.end()) //se vertice destino esta em toBeChecked
            if(currDist[arc->finish->label] > (currDist[v->label] + arc->weight)){
            currDist[arc->finish->label] = currDist[v->label] + arc->weight; //atualiza (relaxamento) do custo
            }
    }
    return currDist[fim->label];
    }//alg. de Dijkstra para caminhos minimos

    bool directed; //variável booleana que marca se G é direcionado
    std::map<int, Node *> nodeMap;//mapa de labels para os vertices
    std::set<Node *> nodes;  //conjunto de vertices
    std::set<Edge *> edges; //conjunto de arestas
};


int main(){
    int n=1;//nº de cidades
    int e=1;//nº de acordos
    int x, y;//cidade x à cidade y em h horas
    int k, o, d;//k consultas, cidade o à cidade d;
    double m, h;//tempo min
    cin >> n >> e;
    while(n != 0 && e != 0){
    Graph war(true);//direcionado
    for(int k = 1; k <= n; k++){//colocar as cidades como vertices
        war.addNode(k);
    }
    for(int i = 0; i < e; i++){//pedir os endereçoes e hrs
        cin >> x >> y >> h;
        war.addEdge(x, y, h);//criar as arestas
    }
    war.zerapeso();//chamar a função que zera o peso das arestas que estão no mesmo país
    cin >> k;
    for(int j = 0; j < k; j++){//pedir os casos de testes
        cin >> o >> d;
        m = war.findShortestPath(o, d);//pegar o valor do menor caminho
        if(m == DBL_MAX)//se o valor retornar maximo é porque não tem caminho de uma cidade a outra
        cout << "Nao e possivel entregar a carta" << endl;
        else
        cout << m << endl;
    }
    cout << endl;
    cin >> n >> e;
    }
    cout << endl<<endl;


return 0;
}
