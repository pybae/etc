#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <typeinfo>

using namespace std;

// Does a eval on the nodes
int eval(int startNode, int limit, map<int, vector<int> > edges)
{
  set<int> visited;
  for (int i = 0; i < edges.size(); i++) {
    for (int j = 0; j < edges[i].size(); j++) {
      cout << edges[i][j] << endl;
    }
  }


  return 0;
}

int main(int argc, const char *argv[])
{
  int numNodes = 0;
  while (cin >> numNodes && numNodes) {
    printf("%d\n", numNodes);

    map <int, vector<int> > edges;
    for (int i = 0; i < numNodes; i++) {
      int a, b;
      cin >> a;
      cin >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    
    int startNode, limit;
    int numCases;
    while ((cin >> startNode && cin >> limit) &&
           (startNode != 0 && limit != 0)) { 
      numCases++;
      int result = eval(startNode, limit, edges);
      cout << "Case 1 " << numCases << ": " << result \
        << " nodes not reachable from node " << startNode << " with TTL = " << limit;
    }
  }
  return 0;
}
