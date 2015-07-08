class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        string current;

        for (int i = 0; i < path.length(); i++){
            if (path[i] == '/'){
                if (current != ""){
                    folders.push_back(current);
                    current = "";
                }
            }
            else current += path[i];
        }
        if (current != "") folders.push_back(current);

        vector<string> ans;
        for (int i = 0; i < folders.size(); i++){
            if (folders[i] == ".."){
                if (ans.size()){
                    ans.pop_back();
                }
            }
            else if (folders[i] != ".")
                ans.push_back(folders[i]);
        }

        string ansStr;
        for (int i = 0; i < ans.size(); i++){
            ansStr += "/" + ans[i];
        }
        if (ansStr == "") ansStr = "/";

        return ansStr;
    }
};