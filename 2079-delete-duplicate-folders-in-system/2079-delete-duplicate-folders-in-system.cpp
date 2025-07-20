class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;  
        bool toDelete = false;                      
    };
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        
        buildTrie(root, paths);
        
        unordered_map<string, vector<TrieNode*>> signatureToNodes;
        generateSignatures(root, signatureToNodes);
        
        markDuplicatesForDeletion(signatureToNodes);
        
        vector<vector<string>> result;
        vector<string> currentPath;
        collectValidPaths(root, currentPath, result);
        
        return result;
    }
    
private:
    void buildTrie(TrieNode* root, vector<vector<string>>& paths) {
        for (auto& path : paths) {
            TrieNode* current = root;
            for (string& folder : path) {
                if (current->children.find(folder) == current->children.end()) {
                    current->children[folder] = new TrieNode();
                }
                current = current->children[folder];
            }
        }
    }
    
    string generateSignatures(TrieNode* node, unordered_map<string, vector<TrieNode*>>& signatureToNodes) {
        if (!node) return "";
        
        vector<string> childSignatures;
        for (auto& [folderName, childNode] : node->children) {
            string childSig = generateSignatures(childNode, signatureToNodes);
            childSignatures.push_back(folderName + ":" + childSig);
        }
        
        sort(childSignatures.begin(), childSignatures.end());
        
        string signature = "[";
        for (int i = 0; i < childSignatures.size(); i++) {
            if (i > 0) signature += ",";
            signature += childSignatures[i];
        }
        signature += "]";
        
        if (!childSignatures.empty()) {
            signatureToNodes[signature].push_back(node);
        }
        
        return signature;
    }
    
    void markDuplicatesForDeletion(unordered_map<string, vector<TrieNode*>>& signatureToNodes) {
        for (auto& [signature, nodesList] : signatureToNodes) {
            if (nodesList.size() > 1) {  
                for (TrieNode* node : nodesList) {
                    markNodeAndSubfoldersForDeletion(node);
                }
            }
        }
    }
    
    void markNodeAndSubfoldersForDeletion(TrieNode* node) {
        if (!node) return;
        node->toDelete = true;
        
        for (auto& [folderName, childNode] : node->children) {
            markNodeAndSubfoldersForDeletion(childNode);
        }
    }
    
    void collectValidPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        if (!node) return;
        
        for (auto& [folderName, childNode] : node->children) {
            if (!childNode->toDelete) {  
                currentPath.push_back(folderName);
                result.push_back(currentPath);  
                
                collectValidPaths(childNode, currentPath, result);
                
                currentPath.pop_back();  
            }
        }
    }
};
