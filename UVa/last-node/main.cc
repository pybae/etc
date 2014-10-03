#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <typeinfo>

using namespace std;

int eval(int startNode, int limit, map<int, vector<int> > edges)
{
    map<int, int> visited;
    queue<int> s;
    
    s.push(startNode);
    visited[startNode]=0;
    
    while (!s.empty()) {
        int top = s.front();
        s.pop();
        int size = edges[top].size();
        for (int i = 0; i < size; i++) {
            int n = edges[top][i];
            if (!visited.count(n)) { // Already been here
                visited[n] = visited[top] + 1;
                s.push(n);
            }
        }
    }
    
    map <int,int>::const_iterator itr;
    int result = 0;
    for(itr = visited.begin(); itr != visited.end(); ++itr){
        if ((*itr).second>limit) {
            result++;
        }
    }
    
   result += edges.size()-visited.size();

   return result;
}

int main(int argc, const char *argv[])
{
    int numNodes = 0;
    while (cin >> numNodes && numNodes) {
        map <int, vector<int> > edges;
        for (int i = 0; i < numNodes; i++) {
            int a, b;
            cin >> a;
            cin >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
    
        int startNode, limit;
        int numCases = 0;
        while ((cin >> startNode && cin >> limit) &&
               (startNode != 0 && limit != 0)) { 
            numCases++;
            int result = eval(startNode, limit, edges);
            cout << "Case " << numCases << ": " << result \
                 << " nodes not reachable from node " << startNode << " with TTL = " << limit << endl;
        }
    }
    return 0;
}
