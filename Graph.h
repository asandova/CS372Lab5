/**
*
*CS372: Lab5
*File: Graph.h
*Author: August B. Sandoval
*Purpose: Provides the class definition of  class Graph
*
**/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    private:
        vector<Node> m_nodes;
        vector< list<Node> > m_adjList;
    public:
        friend ostream& operator<<(ostream & out, const Graph & g); //defined

        Graph(const string & file);

        //Insert a edge ( a , b ) to m_adjList
        void addEdge ( const Node & a , const Node & b ) ;//defined - need to check

        //Insert a node a to m_nodes
        void addNode ( const Node & a ); //defined

        //check is the Node exist in the graph
        //bool NodeExists(const Node & a)const;
        bool NodeExist(const string& name)const; //defined

        //returns the id of the node with given name
        size_t findID(const string& name)const; //defined

        // Return node with id equal to i
        const Node & getNode ( size_t i ) const; //defined6

        // Return reference of the adjacency list of node a
        list <Node> & getAdjNodes ( const Node & a );//defined

        // Return constant reference to adjacency list of node a
        const list <Node> & getAdjNodes ( const Node & a ) const; //defined

        // Return the total number of nodes i n the graph
        size_t num_nodes ( ) const; //defined

        // Create a graph from a tab−separated text edge list file
        // t o adjacency lists
        void scan ( const string & file ) ; //defined

        // Save a graph from adjacency lists to a tab−separated
        // text edge list file
        void save ( const string & file ) ; //defined

};
#endif // GRAPH_H