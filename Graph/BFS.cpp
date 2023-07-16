void preparedAdjList(unordered_map<int, vector<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i: adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, vector<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    preparedAdjList(adjList, edges);
    
    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            bfs(adjList, visited, ans, i); 
        }
    }
   return ans; 
}
