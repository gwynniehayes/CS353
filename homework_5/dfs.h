void dfs(AdjacencyList* graph, int start, int numNodes){
    // track which nodes have been visited using an array of booleans
    bool* visited = new bool[numNodes]();

    // stack for DFS
    std::stack<int> to_visit;

    // push start node
    to_visit.push(start);

    int current;

    // while there are still nodes to explore
    while (!to_visit.empty()){
        // pop from stack
        current = to_visit.top();
        to_visit.pop();

        // only process if unvisited
        if (!visited[current]){
            visited[current] = true;
            std::cout << current << " ";

            // push neighbors
            for (auto neighbor : *(graph->neighbors(current))){
                if (!visited[neighbor]){
                    to_visit.push(neighbor);
                }
            }
        }
    }
    std::cout << std::endl;

    // free memory for visited
    delete[] visited;
}