#include <iostream>
#include <map>
#include <set>

using namespace std;

int n, k, temp;
set<int> computers[3];
map<int, set<int> > p;

int satisfy_requirements(set<int> requirements, set<int> finished_parts) {
  for (auto it = requirements.begin(); it != requirements.end(); it++) {
    if (finished_parts.find(*it) == finished_parts.end()) {
      return false;
    }
  }

  return true;
}

int compute_cost(int starting_index, map<int, set<int> > parts) {
  int index = starting_index;
  int cost = 0;
  set<int> finished_parts;

  while (finished_parts.size() < n) {
    set<int> current_parts = computers[index];
    bool match = false;

    for (auto it = current_parts.begin(); it != current_parts.end(); it++) {
      if (parts.find(*it) != parts.end()) {
        if (satisfy_requirements(parts[*it], finished_parts)) {
          finished_parts.insert(*it);
          parts.erase(*it);
          cost++;
          match = true;
        }
      }
    }

    if (!match) {
      index = (index + 1) % 3;
      cost++;
    }
  }

  return cost;
}

int main(int argc, char const *argv[]) {
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> temp;
    computers[temp - 1].insert(i);
  }

  for (size_t i = 0; i < n; i++) {
    cin >> k;
    p[i] = set<int>();
    for (size_t j = 0; j < k; j++) {
      cin >> temp;
      p[i].insert(temp - 1);
    }
  }

  int ans = -1;
  for (int i = 0; i < 3; i++) {
    ans = max(ans, compute_cost(i, p));
  }

  std::cout<< ans << std::endl;
  return 0;
}
