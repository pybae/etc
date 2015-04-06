#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Entry {
    string id;
    long long size;
    long long last_modified;
    long long last_read;
};

bool compareEntriesById(Entry a, Entry b) {
    return a.id < b.id;
}

bool compareEntriesBySize(Entry a, Entry b) {
    return a.size < b.size;
}

bool compareEntriesByLastModified(Entry a, Entry b) {
    return a.last_modified < b.last_modified;
}

bool compareEntriesByLastRead(Entry a, Entry b) {
    return a.last_read < b.last_read;
}

int d, q, s;
string id, modifier;
long long size;
long long last_modified;
long long last_read;
int shardid;

vector<vector<vector<Entry> > > processed_shards;
vector<vector<Entry> > total_shards;

void query(int shardid, int k, int type) {
    if (shardid == -1) {
        std::cout << total_shards[type][k].id << std::endl;
    } else {
        std::cout << processed_shards[shardid][type][k].id << std::endl;
    }
}

int main(int argc, char *argv[])
{
    cin >> d >> q >> s;
    vector<vector<Entry> > shards(s);
    for (int i = 0; i < s; i++) {
        shards[i] = vector<Entry>();
    }

    while (d--) {
        cin >> id >> shardid >> size >> last_modified >> last_read;
        Entry e;
        e.id = id;
        e.size = size;
        e.last_modified = last_modified;
        e.last_read = last_read;

        shards[shardid].push_back(e);
    }

    for (int i = 0; i < s; i++) {
        vector<Entry> valuesById = shards[i];
        vector<Entry> valuesBySize = shards[i];
        vector<Entry> valuesByLastM = shards[i];
        vector<Entry> valuesByLastR = shards[i];

        sort(valuesById.begin(), valuesById.end(), compareEntriesById);
        sort(valuesBySize.begin(), valuesBySize.end(), compareEntriesBySize);
        sort(valuesByLastM.begin(), valuesByLastM.end(), compareEntriesByLastModified);
        sort(valuesByLastR.begin(), valuesByLastR.end(), compareEntriesByLastRead);

        vector<vector<Entry> > current;
        current.push_back(valuesById);
        current.push_back(valuesBySize);
        current.push_back(valuesByLastM);
        current.push_back(valuesByLastR);
        processed_shards.push_back(current);
    }

    // do the k way merge (shitty version)
    total_shards.push_back(vector<Entry>());
    total_shards.push_back(vector<Entry>());
    total_shards.push_back(vector<Entry>());
    total_shards.push_back(vector<Entry>());
    for (int i = 0; i < s; i++) {
        for (int k = 0; k < processed_shards[i][0].size(); k++) {
            total_shards[0].push_back(processed_shards[i][0][k]);
            total_shards[1].push_back(processed_shards[i][1][k]);
            total_shards[2].push_back(processed_shards[i][2][k]);
            total_shards[3].push_back(processed_shards[i][3][k]);
        }
    }

    sort(total_shards[0].begin(), total_shards[0].end(), compareEntriesById);
    sort(total_shards[1].begin(), total_shards[1].end(), compareEntriesBySize);
    sort(total_shards[2].begin(), total_shards[2].end(), compareEntriesByLastModified);
    sort(total_shards[3].begin(), total_shards[3].end(), compareEntriesByLastRead);

    int k;
    while (q--) {
        cin >> k >> modifier >> shardid;
        if (modifier == "id") {
            query(shardid, k, 0);
        } else if (modifier == "size") {
            query(shardid, k, 1);
        } else if (modifier == "lm") {
            query(shardid, k, 2);
        } else {
            query(shardid, k, 3);
        }
    }

    return 0;
}
