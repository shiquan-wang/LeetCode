#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool checkIP(const std::string& strIP){
    if(strIP.empty()){
        return false;
    }
    std::vector<std::string> subVec;
    std::string strSeparator = ".";
    std::string::size_type size_pos = 0;
    std::string::size_type size_prev_pos = 0;

    while ((size_pos = strIP.find(strSeparator, size_prev_pos)) != std::string::npos)
    {
        /* code */
        std::string strTemp = strIP.substr(size_prev_pos, size_pos - size_prev_pos);
        subVec.push_back(strTemp);
        size_prev_pos = size_pos+1;
    }

    if(size_prev_pos < strIP.size()){
        subVec.push_back(strIP.substr(size_prev_pos, strIP.size() - size_prev_pos));
    }
    
    if(subVec.size() != 4){
        return false;
    }

    for(int i = 0; i < subVec.size(); ++i){
        if(subVec[i].empty()){
            return false;
        }
        if(subVec[i].find_first_not_of("0123456789") != std::string::npos){
            return false;
        }
        if(std::stoi(subVec[i]) > 255 || std::stoi(subVec[i]) < 0){
            return false;
        }
    }
    return true;
}
int main(){
    string input = "1.168.0";
    if(checkIP(input)){
        cout<<"y";
    }else{
        cout<<"N";
    }
}