#include "factory.h"
#include <math.h>

class GenerateGraph{
    static void testcasesGenerator(int vertices, int edges, int index, int choice, int directedMaxLength){
        char newPath[200];
        char fileNumGen = char(48+index);

        strcpy(newPath, path);
        strcat(newPath, "/output");
        strncat(newPath, &fileNumGen, 1);
        strcat(newPath, ".txt");

        freopen(newPath, "w", stdout);

        try{
            GraphFactory::generateGraph(vertices, edges, choice, directedMaxLength);
        }catch(string error){
            cout << "Error: " << error << endl;
            fclose(stdout);
            return;
        }
        fclose(stdout);
        return;
    }

    static vector<pair<int, int> >* ParametersUtil(int maxVertices, int maxEdges){
        int digitLength = (int) (log10(maxVertices));
        vector<pair<int, int> > *myPair = new vector<pair<int, int> >;
        switch (digitLength) {
        case 1:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (3, 3));
            myPair->push_back(pair<int, int> (4, 4));
            myPair->push_back(pair<int, int> (5, 6));
            myPair->push_back(pair<int, int> (6, 10));
            myPair->push_back(pair<int, int> (7, 13));
            myPair->push_back(pair<int, int> (8, 17));
            myPair->push_back(pair<int, int> (9, 20));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 2:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (10, 16));
            myPair->push_back(pair<int, int> (20, 30));
            myPair->push_back(pair<int, int> (40, 55));
            myPair->push_back(pair<int, int> (50, 60));
            myPair->push_back(pair<int, int> (70, 89));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 3:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (50, 70));
            myPair->push_back(pair<int, int> (100, 132));
            myPair->push_back(pair<int, int> (200, 232));
            myPair->push_back(pair<int, int> (300, 346));
            myPair->push_back(pair<int, int> (500, 576));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 4:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (50, 71));
            myPair->push_back(pair<int, int> (100, 127));
            myPair->push_back(pair<int, int> (500, 549));
            myPair->push_back(pair<int, int> (1000, 1129));
            myPair->push_back(pair<int, int> (3000, 3209));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 5:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (100, 127));
            myPair->push_back(pair<int, int> (500, 549));
            myPair->push_back(pair<int, int> (1000, 1129));
            myPair->push_back(pair<int, int> (3000, 3209));
            myPair->push_back(pair<int, int> (10000, 13000));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 6:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (100, 138));
            myPair->push_back(pair<int, int> (1000, 1199));
            myPair->push_back(pair<int, int> (5000, 5799));
            myPair->push_back(pair<int, int> (10000, 12590));
            myPair->push_back(pair<int, int> (20000, 23098));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        case 7:
            myPair->push_back(pair<int, int> (2, 1));
            myPair->push_back(pair<int, int> (5, 8));
            myPair->push_back(pair<int, int> (9, 14));
            myPair->push_back(pair<int, int> (100, 138));
            myPair->push_back(pair<int, int> (1000, 1199));
            myPair->push_back(pair<int, int> (5000, 5799));
            myPair->push_back(pair<int, int> (10000, 12590));
            myPair->push_back(pair<int, int> (20000, 23098));
            myPair->push_back(pair<int, int> (maxVertices, maxEdges));
            return myPair;
            break;
        default:
            return NULL;
        }
        return NULL;
    }

public:
    static void printGraph(int maxVertices, int maxEdges, int choice, int directedMaxLength){
        int index = 0;
        vector<pair<int, int> > *myPairs = ParametersUtil(maxVertices, maxEdges);

        if(myPairs == NULL){
            cout << "Error: UNABLE TO GENERATE TESTCASES. TRY CHANGING VERTICES AND EDGES";
            return;
        }
        while(index < SMALL_TESTCASES){
            testcasesGenerator(myPairs->at(index).first, myPairs->at(index).second, index+1, choice, directedMaxLength);
            index++;
        }

        while(index < LARGE_TESTCASES + SMALL_TESTCASES){
            testcasesGenerator(myPairs->at(index).first, myPairs->at(index).second, index+1, choice, directedMaxLength);
            index++;
        }
        return;
    }

};


