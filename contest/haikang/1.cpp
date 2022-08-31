#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):val(0), left(left), right(right){}
};

class Solution{
public:
    vector<int> buf;
    void dfs1(TreeNode* root, string& str){
        if(root == nullptr){
            str += '#';
            return;
        }
        string temp = to_string(root->val);
        str += temp + '!';
        dfs1(root->left, str);
        dfs1(root->right, str);
    }

    char* serialize(TreeNode* root){
        if(root == nullptr){
            return "#";
        }
        string res;
        dfs1(root, res);
        char* charres = new char[res.length() + 1];
        strcpy(charres, res.c_str());
        charres[res.length()] = '\0';
        return charres;
    }
    TreeNode* deser(char** str){
        if(** str == '#'){
            (*str)++;
            return NULL;
        }
        int val = 0;
        while (**str != '!' && **str != '\0')
        {
            /* code */
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(val);
        if(**str == '\0'){
            return root;
        }else{
            (*str)++;
        }
        root->left = deser(str);
        root->right = deser(str);
        return root;
    }
    TreeNode* deserialize(char *str){
        if(str == '#'){
            return NULL;
        }
        TreeNode* res = deser(str);
        return res;
    }
};

int main(){
    
}