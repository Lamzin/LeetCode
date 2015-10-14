/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> un_map;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (un_map.count(node)) return un_map[node];

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        for(auto i = node->neighbors.begin(); i != node->neighbors.end(); i++){
            if (node == *i) new_node->neighbors.push_back(new_node);
            else new_node->neighbors.push_back(cloneGraph(*i));
        }
        return un_map[node] = new_node;
    }
};