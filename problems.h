#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;



void matadd(vector<vector<int>> &graph,int i,int j){
    graph[i][j]=1;
}
/*
    Problem 1 - Course Schedule
*/

bool findcycle(vector<vector<int>> &graph,vector<bool> &visited, vector<bool> &help,int i){

    if(help[i]==true){
        return true;
    }
    help[i]=true;
    visited[i]=true;
    for(int j=0;j<graph[i].size();j++){
        if(graph[i][j]){
            //cout<<i<<" "<<j<<endl;
            if(!visited[j]&&findcycle(graph,visited,help,j)){
                return true;
            }else if(help[j]){
                return true;
            }
        }
    }
    help[i]=false;
    return false;
}

void DFSprint(vector<vector<int>>& graph,vector<bool>& IsVisted, vector<int>& ans,int i){
    
    if(IsVisted[i]){
        return;
    }
    
    IsVisted[i]=true;

    for(int j=0;j<graph.size();j++){
        if(graph[j][i]&&!IsVisted[j]){
            DFSprint(graph,IsVisted,ans,j);
        }
    }

    ans.push_back(i);

    for(int j=0;j<graph.size();j++){
        if(graph[i][j]&&!IsVisted[j]){
            DFSprint(graph,IsVisted,ans,j);
        }
    }
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{   
    int v= numCourses;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for(int i=0;i<prerequisites.size();i++){
        matadd(graph,prerequisites[i][1],prerequisites[i][0]);
    }
    vector<bool> IsVisted(v,false);
    vector<int> ans;
    vector<bool> help(v,false);

    for(int i=0;i<v;i++){
       // cout<<i<<"k"<<endl;
        if(findcycle(graph,IsVisted,help,i)){
            //cout<<"u"<<endl;
            ans.empty();
            //cout<<"ok"<<endl;
            return ans;
        }
    }

   for(int i=0;i<IsVisted.size();i++){
     IsVisted[i]=false;
   }

    for(int i=0;i<v;i++){
        
        if(!IsVisted[i]){
            DFSprint(graph,IsVisted,ans,i);
        }
    }
    return ans;

}

/*
    Problem 2 - Keys & Rooms
*/
int ans;
void DFS2(vector<vector<int>>& graph, vector<vector<int>>& rooms,vector<int>& IsVisted,int i){
    if(IsVisted[i]){
        return;
    }
    IsVisted[i]=1;
   // cout<<"here"<<endl;
    ans++;
    for(auto x:rooms[i]){
        if(IsVisted[x]) continue;
        matadd(graph,0,x);
        DFS2(graph,rooms,IsVisted,x);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    int v = rooms.size();
   // cout<<v<<endl;
    vector<vector<int>> graph(v,vector<int>(v,0));
    vector<int> IsVisted(v,0);
    ans = 0;
    DFS2(graph,rooms,IsVisted,0);
    //cout<<ans<<endl;
    if(ans==v){
        return true;
    }else{
        return false;
    }
}

/*
    Problem 3 - Cheapest Flight
*/
int mindist(vector<int>& dist,vector<bool>& sptSet){
    int min = INT_MAX;
    int ans = -1;
    for(int i = 0;i<dist.size();i++){
        if(!sptSet[i]&&dist[i]<min){
            min = dist[i];
            ans = i;
        }
    }
    return ans;
}

int dijkstra (vector<vector<int>> &graph,int src,int k,int dst){
    k+=1;

    int v = graph.size();

    vector<int> dist(v,INT_MAX);
    vector<bool> sptSet(v,false);
    vector<int> steps(v,0);

    dist[src] = 0;
    steps[src]=0;
    int u;
    
    for(int i=0;i<v;i++){
        u = mindist(dist,sptSet);
        if(u==-1){
            break;
        }

        if(steps[u]==k+1){
            break;
        }

        sptSet[u]=true;
        
        for(int t=0;t<v;t++){
            if(!sptSet[t]&&graph[u][t]&&dist[u]!=INT_MAX&&dist[u]+graph[u][t]<dist[t]&&steps[u]<k){
                dist[t]= dist[u]+graph[u][t];
                steps[t] = steps[u]+1;
            }
        }


    }

    if(dist[dst]==INT_MAX) return -1;
    return dist[dst];
    
    
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    int v = n;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<flights.size();i++){
        graph[flights[i][0]][flights[i][1]]=flights[i][2];
    }
    return dijkstra(graph,src,k,dst);
}

/*
    Problem 4 - Minimum Cost to Make Path
*/
typedef struct pair3 {
    pair<int, int> index;
    int cost;
};

struct lessthanbycost {
    bool operator()(pair3 a, pair3 b) {
        return a.cost > b.cost;
    } // I search online a little bit for this operation 
};

int minCost(vector<vector<int>>& grid) {
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    priority_queue<pair3, vector<pair3>, lessthanbycost> pq;
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    pq.push({{0, 0}, 0});
    cost[0][0] = 0;
    
    while(!pq.empty()) {
        pair3 current = pq.top();
        pq.pop();
        int x = current.index.first;
        int y = current.index.second;
        
        if(visited[x][y]) continue;
        visited[x][y] = true;
        
        if(x==m-1&&y==n-1) {
            return current.cost;
        }
        
        for(int i=0;i<4;i++) {
            int nx = x+dirs[i][0];
            int ny = y+dirs[i][1];
            
            if(nx<0||nx>=m||ny<0||ny>=n) continue;
          
            int new_cost = current.cost;
            if(grid[x][y]!= i+1) { // +1 because directions are 1-4 in problem
                new_cost += 1;
            }
            
            if(new_cost<cost[nx][ny]) {
                cost[nx][ny] = new_cost;
                pq.push({{nx, ny}, new_cost});
            }
        }
    }
    return cost[m-1][n-1];
}
/*
    Problem 5 - Shortest Path Visting All Nodes
*/
struct State {
    int current_node;
    vector<bool> visited;
    int path_length;
};

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    if(n==1) return 0;
    queue<State> q;
    for(int i=0;i<n;i++) {
        vector<bool> initial_visited(n, false);
        initial_visited[i] = true;
        q.push({i, initial_visited, 0});
    }
    
    while(!q.empty()) {
        State current = q.front();
        q.pop();

        bool all_visited = true;
        for(bool v : current.visited) {
            if(!v) {
                all_visited = false;
                break;
            }
        }
        if(all_visited) {
            return current.path_length;
        }
        
        for(int neighbor : graph[current.current_node]) {
            //cout<<neighbor<<endl;
            vector<bool> new_visited = current.visited;
            new_visited[neighbor] = true;
            
            bool state_exists = false;

            queue<State> temp_q=q;
            while(!temp_q.empty()) {
                State s = temp_q.front();
                temp_q.pop();
                if (s.current_node==neighbor&&s.visited==new_visited) {
                    //cout<<"neighbor: "<<neighbor<<endl;
                    state_exists = true;
                    break;
                }
            }
            //cout<<"HERE!!!"<<endl;

            if(!state_exists) {
                q.push({neighbor, new_visited, current.path_length + 1});
                //cout<<"pushed_in"<<neighbor<<endl;
            }
        }
    }
    return -1; 
}
