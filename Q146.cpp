#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class LRUCache {
public:
	int _capacity;
	unordered_map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int, int>> cache;
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end()) return -1;
		cache.splice(cache.begin(), cache, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = hash.find(key);
		if (it != hash.end()) {
			it->second->second = value;
			cache.splice(cache.begin(), cache, it->second);
			return;
		}
		cache.insert(cache.begin(), make_pair(key, value));
		hash[key] = cache.begin();
		if (cache.size() > _capacity) {
			hash.erase(cache.back().first);
			cache.pop_back();
		}
	}
};

int main(void) {

	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);

	cache.put(3, 3);

	return 0;
}