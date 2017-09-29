/**
*
*CS372: Lab5
*File: Graph.cpp
*Author: August B. Sandoval
*Purpose: Defines the Graph class in Graph.h
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>

#include <cstring>

#include "Node.h"
#include "Graph.h"

using namespace std;
/*
Graph::Graph(){
    m_nodes = vector<Node>();
    m_adjList = vector<list<Node> > ();
}*/

Graph::Graph(const string& file){
    scan(file);
}
//Insert a edge ( a ,b ) to m_adjList
void Graph::addEdge ( const Node & a , const Node & b ) {
    //adds the two nodes to the others adj list and prevents duplicates
    m_adjList[a.id()].push_back(b);
    m_adjList[b.id()].push_back(a);
}

//Insert a node a to m_nodes
void Graph::addNode ( const Node & a ) {
    m_nodes.reserve( m_nodes.size() + 1 );
    m_nodes [ a.id( ) ] = a ;
}

bool Graph::NodeExist(const string& name)const{
    Node curr;
    for(size_t i = 0; i < m_nodes.size(); i++){
        curr = getNode(i);
        if(curr.name() == name){
            return true;
        }
    }
    return false;
}

size_t Graph::findID(const string & name)const{
    Node curr;
    for(size_t i = 0; i < m_nodes.size(); i++){
        curr = getNode(i);
        if(curr.name() == name){
            return curr.id();
        }
    }
    return -1;
}

// Return node with id equal to i
const Node & Graph::getNode ( size_t i ) const {
    return m_nodes[ i ] ;
}

// Return reference of the adjacency list of node a
list <Node> & Graph::getAdjNodes ( const Node & a ){
    return m_adjList[ a.id ( ) ] ;
}

// Return constant reference to adjacency list of node a
const list <Node> & Graph::getAdjNodes ( const Node & a ) const{
    return m_adjList [ a.id ( ) ] ;
}

// Return the total number of nodes i n the graph
size_t Graph::num_nodes ( ) const {
    return m_nodes.size( ) ;
}

//only splits strings into two on tab character
vector<string>& split(const string& a){
    vector<string> names;
    for(size_t i = 0; i < a.size()-1; i++ ){
        if(a[i] == '\t'){
            names.push_back( a.substr(0, i-1)   ) ;
            names.push_back( a.substr(i+1, a.size() ) );
            break;
        }
    }
    return names;
}

// Create a graph from a tab−separated text edge list file
// to adjacency lists
void Graph::scan ( const string & file ){

    //char* line;
    string fline;
    int id = 0;
    Node N1, N2;
    ifstream iFile;
    iFile.open( file.c_str(), ifstream::in );
    if(  iFile.is_open()  ){
        while( !iFile.eof() ){
                getline(iFile, fline);
                //string L(line);
                vector<string> names = split(fline);
                if(!NodeExist( names[0] ) ){
                        Node tmp1( names[0],id++);
                        N1 = tmp1;
                        addNode(N1);
                }else{
                    N1 = getNode( findID( names[1] ) ) ;
                }
                if(!NodeExist( names[1] ) ){
                        Node tmp2( names[1] ,id++);
                        N2 = tmp2;
                        addNode( N2 ) ;
                }else{
                        N2 = getNode( findID( names[1] ) ) ;
                }
                addEdge(N1, N2);
        }//end of while
        iFile.close();
    }else{
        cout << "File: " << file << " does not exist" << endl;
        m_nodes = vector<Node>();
        m_adjList = vector<list<Node> >();
    }//end of else
}//end of scan

// Save a graph from adjacency lists to a tab−separated
// text edge list file
void Graph::save( const string & file ){
    //NOTE: the method assumes the file does not exist and will overwrite
    // if the file does exist

        ofstream OFile;
        OFile.open(file.c_str(), ofstream::out);
        for(size_t i =0; i < m_nodes.size(); i++){
            const list<Node> neighbors = getAdjNodes( getNode(i) );
            for(list<Node>::const_iterator itr = neighbors.begin(); itr!= neighbors.end(); ++itr){
                    OFile << getNode(i).name() << "\t" << itr->name() << "\n";
            }
        }
        OFile.close();
}

ostream& operator<<(ostream & out, const Graph & g){
    out << "Nodes in the graph: " << endl ;
    for ( unsigned i =0; i <g.num_nodes ( ) ; i ++) {
        out << g.getNode( i ).name ( ) << " ," ;
    }
    out << endl ;
    out << "Adjacency list of the graph : " << endl ;
    for ( unsigned i =0; i <g.num_nodes( ) ; i ++) {
        out << "Node " << g.getNode(i).name( ) << " : ";
        const list <Node> neighbors = g.getAdjNodes ( g.getNode(i) ) ;
            for( list<Node>::const_iterator itr = neighbors.begin( ) ;
                itr!= neighbors.end ( ) ; ++itr ) {
                out << itr->name( ) << " ," ;
            }
        out << endl;
    }
    return out;
}
