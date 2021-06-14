#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
map<pair<string,string>,int> temp2;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    
    
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    pair<string, string> key(vert1, vert2);
    edges[key] = weight;
}

bool Graph::FindVertex(string vert1) {
    list<string>::iterator it;
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        if(vert1==*it){
            cout<<"1"<<"\n";
            return 0;
        }
    }
    cout<<"0"<<"\n";
    return 0;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    pair<string, string> key(vert1, vert2);
    temp2 = edges;
    if(temp2[key] == 0){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<temp2[key]<<"\n";
    }
    return 0;
}

int Graph::IsReachable(string vert1, string vert2) {
    
    queue<string> Q;
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    map<string,int> dup;
    string u = "";
    string connect = "";
    //2147483647
    for(it=vertices.begin(); it!=vertices.end(); it++){
        dup[*it] = 2147483647; //a->a, a->b, a->c, a->d infinity
    }
    
    dup[vert1] = 0; //a->a = 0, assuming vert 1 a
    
    Q.push(vert1);
    
    while(Q.size() != 0){
        u = Q.front();
        Q.pop();
        for(eit=edges.begin(); eit!=edges.end(); eit++){
            if((((*eit).first).first) == u){
                connect=(((*eit).first).second);
                if(dup[connect] == 2147483647){
                    dup[connect] = dup[u] + 1;
                    Q.push(connect);
                }
            }
        }
    }
    
    if(dup[vert2] == 2147483647){
        cout<<"-1"<<"\n";
    }
    
    if(dup[vert2] != 2147483647){
        cout<<dup[vert2]<<"\n";
    }
    
    return 0;
}

int main() {
    Graph G;
    list<string> temp;
    string input;
    string inputX;
    string inputY;
    int x;
    while(input != "END"){
        cin>>input;
        if(input != "END"){
            temp.push_back(input);
        }
    }
    
    G.vertices = temp;
    
    cin>>inputX>>inputY;
    pair<string, string> key(inputX, inputY);
    while(inputX != "END" || inputY != "END"){
        cin>>x;
        G.AddEdge(key.first, key.second, x);
        cin>>inputX;
        if(inputX == "END"){
            break;
        }
        else{
            key.first = inputX;
        }
        cin>>inputY;
        if(inputY == "END"){
            break;
        }
        else{
            key.second = inputY;
        }
    }
    G.PrintOut();
    
    /*string U = "Hannover";
    string P = "Osnabruck";
    pair<string, string> test(U,P);
    cout<<G.edges[key];*/
    
    int operation;
    cin>> operation;
    while(operation != 0){
        if(operation == 1){
            cin>>inputX;
            G.FindVertex(inputX);
        }
        if(operation == 2){
            cin>>inputX;
            cin>>inputY;
            G.FindEdgeCost(inputX, inputY);
        }
        if(operation == 3){
            cin>>inputX;
            cin>>inputY;
            G.IsReachable(inputX, inputY);
        }
        cin>> operation;
    }
}
