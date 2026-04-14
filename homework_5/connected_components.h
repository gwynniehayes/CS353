#ifndef CONNECTED_COMPONENTS
#define CONNECTED_COMPONENTS

#include <iostream>
#include <stack>

#include "adjacency_list.h"

void connected_components(AdjacencyList* graph, int numNodes){
    bool* visited = new bool[numNodes]();  // all false initially

    for (int i = 0; i < numNodes; i++){
        if (!visited[i]){
            // start a new component
            std::stack<int> to_visit;
            to_visit.push(i);

            while (!to_visit.empty()){
                int current = to_visit.top();
                to_visit.pop();

                if (!visited[current]){
                    visited[current] = true;
                    std::cout << current << " ";  // print node as part of this component

                    // push all unvisited neighbors
                    for (auto neighbor : *(graph->neighbors(current))){
                        if (!visited[neighbor]){
                            to_visit.push(neighbor);
                        }
                    }
                }
            }
            std::cout << std::endl;  // line break between components
        }
    }

    delete[] visited;
}

#endif