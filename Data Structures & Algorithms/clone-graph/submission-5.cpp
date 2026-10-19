/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // unordered_map<int, Node*> mp;
    // Node* deepClone(Node* sourceNode){
    //     if(sourceNode == nullptr) return nullptr;
    //     if(mp.contains(sourceNode->val)) return mp[sourceNode->val];

    //     Node* targetNode = new Node(sourceNode->val);
    //     mp[sourceNode->val] = targetNode;

    //     for(Node* node : sourceNode->neighbors){
    //         Node* temp = deepClone(node);
    //         if(temp != nullptr) targetNode->neighbors.push_back(temp);
    //     }

    //     return targetNode;
    // }
public:
    Node* cloneGraph(Node* node) {
        // return deepClone(node);
        if(!node) return node;
        unordered_map<int, Node*> cloned;
        queue<Node*> q;
        q.push(node);
        cloned[node->val] = new Node(node->val);


        while(!q.empty()){
            Node* sourceNode = q.front();
            q.pop();
            
            Node* targetNode = cloned[sourceNode->val];

            for(Node* temp : sourceNode->neighbors){
                if(cloned.contains(temp->val)){
                    targetNode->neighbors.push_back(cloned[temp->val]);
                }
                else{
                    cloned[temp->val] = new Node(temp->val);
                    q.push(temp);
                    targetNode->neighbors.push_back(cloned[temp->val]);
                }
            }
        }

        return cloned[node->val];
    }
};
