#ifndef FORD_FULKERSON
#define FORD_FULKERSON

#include <stack>
#include <climits>
#include <iostream>

int* find_path(const AdjacencyMatrix* residual_capacity, int numNodes, int source, int sink, bool print_progress=false){

    bool* visited = new bool[numNodes];

    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    int* prev = new int[numNodes];

    std::stack<int> to_visit;

    to_visit.push(source);

    int current, node, edge_weight;

    while (!to_visit.empty()){

        // POP
        current = to_visit.top();
        to_visit.pop();

        if (!visited[current]){

            // MARK VISITED
            visited[current] = true;

            for (node = 0; node < numNodes; node++){

                edge_weight = residual_capacity->get_weight(current, node);

                if (edge_weight != 0 && !visited[node]){

                    if (print_progress){
                        std::cout << "Trying edge (" << current << "," << node
                                  << ") with weight " << edge_weight << std::endl;
                    }

                    to_visit.push(node);
                    prev[node] = current;

                    if (node == sink){
                        break;
                    }
                }
            }

            if (node == sink){
                break;
            }
        }
    }

    int* path = NULL;

    if (node == sink){

        std::stack<int> path_nodes;
        int current = sink;
        int prev_node;

        while (current != source){
            path_nodes.push(current);
            current = prev[current];
        }

        path_nodes.push(source);

        path = new int[path_nodes.size()];

        int i = 0;
        while (!path_nodes.empty()){
            current = path_nodes.top();
            path_nodes.pop();
            path[i] = current;
            i++;
        }
    }

    delete[] visited;
    delete[] prev;

    return path;
}


int find_new_flow(const int* path, const AdjacencyMatrix* residual_capacity,
                  int numNodes, int source, int sink, bool print_progress=false){

    if (path == NULL)
        return 0;

    int i = 0;
    int current_node = path[i];
    int new_flow = INT_MAX;
    int next_node, edge_weight;

    while (current_node != sink){

        next_node = path[i + 1];

        edge_weight = residual_capacity->get_weight(current_node, next_node);

        if (print_progress){
            std::cout << "Edge (" << current_node << "," << next_node
                      << ") has weight " << edge_weight << std::endl;
        }

        if (edge_weight < new_flow){
            new_flow = edge_weight;
        }

        i++;
        current_node = path[i];
    }

    return new_flow;
}


int ford_fulkerson(const AdjacencyMatrix* capacity, int numNodes, int source, int sink, bool print_progress=false){

    AdjacencyMatrix flow(numNodes);

    if (print_progress){
        std::cout << "Capacity matrix:\n";
        capacity->printMatrix();
        std::cout << std::endl;

        std::cout << "Flow matrix:\n";
        flow.printMatrix();
        std::cout << std::endl;
    }

    int max_flow = 0;

    AdjacencyMatrix residual_capacity(capacity);

    if (print_progress){
        std::cout << "Residual capacity matrix:\n";
        residual_capacity.printMatrix();
        std::cout << std::endl;
    }

    int* next_path = find_path(&residual_capacity, numNodes, source, sink, print_progress);

    int new_flow, current_node, next_node;

    while (next_path != NULL){

        new_flow = find_new_flow(next_path, &residual_capacity, numNodes, source, sink, print_progress);

        max_flow += new_flow;

        int i = 0;
        current_node = next_path[i];

        while (current_node != sink){

            next_node = next_path[i + 1];

            flow.set_weight(current_node, next_node,
                flow.get_weight(current_node, next_node) + new_flow);

            flow.set_weight(next_node, current_node,
                flow.get_weight(next_node, current_node) - new_flow);

            residual_capacity.set_weight(current_node, next_node,
                residual_capacity.get_weight(current_node, next_node) - new_flow);

            residual_capacity.set_weight(next_node, current_node,
                residual_capacity.get_weight(next_node, current_node) + new_flow);

            i++;
            current_node = next_path[i];
        }

        if (print_progress){
            std::cout << "Added new flow " << new_flow << " along path ";
            int i = 0;
            while (next_path[i] != sink){
                std::cout << next_path[i] << "->";
                i++;
            }
            std::cout << sink << std::endl;

            std::cout << "Flow matrix:\n";
            flow.printMatrix();
            std::cout << std::endl;

            std::cout << "Residual capacity matrix:\n";
            residual_capacity.printMatrix();
            std::cout << std::endl;
        }

        delete[] next_path;
        next_path = find_path(&residual_capacity, numNodes, source, sink, print_progress);
    }

    return max_flow;
}

#endif