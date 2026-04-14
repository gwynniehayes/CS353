void bfs(AdjacencyList* graph, int start, int numNodes){
    // track which nodes have been visited using an array of booleans
    bool* visited = new bool[numNodes]();  // all false initially

    // to_visit tracks nodes that need to be explored, stored in a queue
    std::queue<int> to_visit;

    // mark start node as visited and enqueue it
    visited[start] = true;
    to_visit.push(start);

    int current;

    // while there are still nodes to explore
    while (!to_visit.empty()){
        // dequeue a node and assign it to current
        current = to_visit.front();
        to_visit.pop();

        // print current node
        std::cout << current << " ";

        // explore all neighbors of current
        for (auto neighbor : *(graph->neighbors(current))){
            if (!visited[neighbor]){
                visited[neighbor] = true;        // mark neighbor as visited
                to_visit.push(neighbor);         // enqueue neighbor
            }
        }
    }
    std::cout << std::endl;

    // free memory for visited
    delete[] visited;
}