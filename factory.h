#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Constants.h"
using namespace std;

class GraphFactory{
    static void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    /*
    *Generates a random number in range [start, end)
    */
    static int generateRandomNumber(int start, int end){
        if(start > end)
            return -1;

        int r = (rand() % end) + start;
        return r;
    }

    static void shuffle(int *arr, int n){

        srand(time(NULL));

        int i = n, j = 0;
        while(i > 1){
            i = i - 1;
            j = generateRandomNumber(0, i) % n;
            swap(arr[i], arr[j]);
        }
    }

public:
    /*
    * Validates whether given graph edges and vertices are valid or not
    */
    static bool validateGraph(int vertices, int edges){
        int maxEdges = (vertices * (vertices - 1)) / 2;
        if(edges < vertices-1 || edges > maxEdges)
            return false;
        return true;
    }

    /*
    * Generates and prints edges of the graph
    */
    static void generateGraph(int vertices, int edges, int choice, int directedMaxLength){
        if(!validateGraph(vertices, edges)){
            throw "Invalid Number of Edges";
        }
        vector<set<int> > graph(vertices);
        int *edgesArr = new int[vertices];

        if(edgesArr == NULL)
            throw "Invalid Vertices. Enter less number of vertices";
        cout << vertices << " " << edges << endl;
        int i = 0;

        for(i = 0; i < vertices; i++){
            edgesArr[i] = i;
        }
        shuffle(edgesArr, vertices);

        int counter = 0;
        for(counter = 0, i = 0; i < vertices && counter < vertices-1; i++){
            if(i != edgesArr[i]){
                graph[i].insert(edgesArr[i]);
                counter++;
            }
        }

        edges = edges - counter;
        i = 0;

        int startVertex, endVertex;
        srand((int)time(0));
        while(i < edges){
            startVertex = generateRandomNumber(0, vertices) % vertices;
            endVertex = generateRandomNumber(0, vertices) % vertices;
            switch(choice){
            case 1:
            case 2:
                //Undirected Graph
                if(graph[startVertex].count(endVertex) == 0 && graph[endVertex].count(startVertex) == 0 && startVertex != endVertex && startVertex != -1 && endVertex != -1){
                    graph[startVertex].insert(endVertex);
                    i++;
                }
                break;
            case 3:
            case 4:
                //Directed Graph
                if(graph[startVertex].count(endVertex) == 0 && startVertex != endVertex && startVertex != -1 && endVertex != -1){
                    graph[startVertex].insert(endVertex);
                    i++;
                }
                break;
            }

        }

        i = 0;
        set<int>::iterator setIt;
        int len = 0;
        while(i < graph.size()){
            setIt = graph[i].begin();
            while(setIt != graph[i].end()){
                switch(choice){
                case 1:
                case 3:
                    len = generateRandomNumber(1, directedMaxLength) % directedMaxLength;
                    cout << i << " " << *setIt << " " << len << endl;
                    break;
                case 2:
                case 4:
                    cout << i << " " << *setIt << endl;
                    break;
                }
                setIt++;
            }
            i++;
        }
        delete []edgesArr;
        return;
    }
};
