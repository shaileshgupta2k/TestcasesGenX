/******************************************
 * @Author: SHAILESH GUPTA
 *
 * Following C++ program creates an undirected graph with
 * V vertices and E edges.
 *
 * Graph is 0-indexed
******************************************/

#include <iostream>
#include "generateGraph.h"
using namespace std;


void printInstructions(){
    cout << "**********************************************************************" << endl;
    cout << "* C++ Program to Generate Directed and Undirected Graph Testcases" << endl;
    cout << "* Constraints:" << endl;
    cout << "* \t1. num(edges) >= num(vertices-1)" << endl;
    cout << "* \t2. edges, vertices > 10" << endl;
    cout << "**********************************************************************" << endl << endl;
}

int main(){
	int maxVertices, maxEdges;

    printInstructions();
    int choice = 0;

    do{
        cout << endl << "1. Undirected Weighted Graph";
        cout << endl << "2. Undirected Unweighted Graph";
        cout << endl << "Choice: ";
        cin >> choice;
    }while(choice < 1 || choice > 2);

    do{
        cout << endl << "Enter max number of vertices: ";
        cin >> maxVertices;

        cout << endl << "Enter max number of edges: ";
        cin >> maxEdges;
    }while(!GraphFactory::validateGraph(maxVertices, maxEdges) && maxVertices <= 110000);

    try{
        switch(choice){
        case 1:
            int directedMaxLength;
            cout << endl << "Maximum weight of graph: ";
            cin >> directedMaxLength;
            GenerateGraph::printGraph(maxVertices, maxEdges, 1, directedMaxLength);
            break;
        case 2:
            GenerateGraph::printGraph(maxVertices, maxEdges, 2, -1);
            break;
        }
    }catch(char const* error){
        cout << endl << "Error: " << error << endl;
        return 0;
    }

	return 0;
}
