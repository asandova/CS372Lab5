/**
*
*CS372: Lab5
*File: main.cpp
*Author: August B. Sandoval
*Purpose: The main file for Lab5
*
**/
#include <iostream>
#include <vector>
#include <string>

#include <cstdlib>
#include <cstdio>
#include <ctype.h>

#include "Node.h"
#include "Graph.h"

using namespace std;

void DFS(Graph & G){

}

void DFSRecursive(Graph & G){


}

void DFSIntative(Graph & G){

}

void Explore(Graph & G, Node & C){
    //check if the node has been visited
    //if(C.getPreTime() == 0)
        //return;
    //set post time
    //C.setPreTime();
     //look for next node

    //set post time
   // C.setPostTime();
}

void testall(){

    Graph Tgraph1("Graph1.txt");
    Graph Tgraph2("Graph2.txt");
    Graph Tgraph3("Graph3.txt");
    Tgraph1.save("Graph1out.txt");
    Tgraph2.save("Graph2out.txt");
    Tgraph3.save("Graph3out.txt");

}

int main(){

    testall();

    return 0;
}

/** R

require("igraph")

links <- read.table("file.txt", header = F, quote = "", stringsAsFactors = F)
names(links) <- c("from", "to")
#links <- data.frame( from=c("a", "a", "c", "d", "e" ),
#                                         to = c("d", "b", "b", "c", "a"))
net <- graph_from_data_frame(d=links, directed=T)
plot(net, vertex.size=30, vertex.label.cex=2)

net <- graph_from_data_frame(d=links, directed=F)
plot(net, vertex.size=30,vertex.label.cex=2)

*/
