/*
JZ37 序列化二叉树

描述
请实现两个函数，分别用来序列化和反序列化二叉树

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void ser_dfs(TreeNode* root, string& s) {
        if(!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        ser_dfs(root->left, s);
        ser_dfs(root->right, s);
    }

    char* Serialize(TreeNode *root) {    
        string ret;
        ser_dfs(root, ret);
        char* ans = new char[ret.size() + 1];
        strcpy(ans, ret.c_str());
        return ans;
    }
    
    TreeNode* deser_dfs(list<string>& slist) {
        if(slist.front() == "#") {
            slist.erase(slist.begin());
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(slist.front()));
        slist.erase(slist.begin());
        node->left = deser_dfs(slist);
        node->right = deser_dfs(slist);
        return node;
    }

    TreeNode* Deserialize(char *str) {
        string s(str);
        string tmp;
        list<string> strs;
        for(auto ch : s) {
            if(ch == ',') {
                strs.emplace_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(ch);
            }
        }
        if(!tmp.empty()) {
            strs.emplace_back(tmp);
            tmp.clear();
        }
        return deser_dfs(strs);
    }
};