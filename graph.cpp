/******************************************
 * @Author: SHAILESH GUPTA
 *
 * Following C++ program creates an undirected and directed graph testcases having
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
        cout << endl << "3. Directed Weighted Graph";
        cout << endl << "4. Directed Unweighted Graph";
        cout << endl << "Choice: _____\b\b\b\b\b";
        cin >> choice;
    }while(choice < 1 || choice > 4);

    do{
        cout << endl << "Enter max number of vertices: ";
        cin >> maxVertices;

        cout << endl << "Enter max number of edges: ";
        cin >> maxEdges;
    }while(!GraphFactory::validateGraph(maxVertices, maxEdges) && maxVertices <= 110000);

    try{
        int directedMaxLength;
        switch(choice){
        case 1:
        case 3:
            cout << endl << "Maximum weight of graph: ";
            cin >> directedMaxLength;
            GenerateGraph::printGraph(maxVertices, maxEdges, choice, directedMaxLength);
            break;
        case 2:
        case 4:
            GenerateGraph::printGraph(maxVertices, maxEdges, choice, -1);
            break;
        }
    }catch(char const* error){
        cout << endl << "Error: " << error << endl;
        return 1;
    }

	return 0;
}
