#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode *> map;
		UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> q;
		q.push(node);
		map[node] = res;
		while (!q.empty()){
			UndirectedGraphNode* front = q.front();
			q.pop();
			for (auto node : front->neighbors){
				if (map.find(node) == map.end()){
					q.push(node);
					UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
					map[front]->neighbors.push_back(newNode);
					map[node] = newNode;
				}
				else{
					map[front]->neighbors.push_back(map[node]);
				}
			}
		}

		return res;
	}
};

int main(void){
	UndirectedGraphNode* node;
	node = new UndirectedGraphNode(0);
	UndirectedGraphNode* firstNode;
	firstNode = new UndirectedGraphNode(1);
	node->neighbors.push_back(firstNode);
	UndirectedGraphNode* secondNode;
	secondNode = new UndirectedGraphNode(2);
	firstNode->neighbors.push_back(secondNode);
	secondNode->neighbors.push_back(secondNode);

	Solution model;
	UndirectedGraphNode* res = model.cloneGraph(node);

	return 0;
}