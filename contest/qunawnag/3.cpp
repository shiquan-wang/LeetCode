class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 翻牌
     * @param inHand string字符串 一组以单空格间隔的手牌(例如：SA HK H9 D8 C5 S5 H4)
     * @return string字符串
     */
    string showDown(string inHand) {
        // write code here
        string ans = "HuangJiaTongHuaShun";
        vector<string> vec = {"HuangJiaTongHuaShun", "TongHuaShun", "SiTiao", "HuLu", "TongHua", "ShunZi", "SanTiao", "LiangDui", "YiDui"};

        vector<string> pai;
        string temp = "";
        int start = 0;
        for(int i = 0; i < inHand.size(); ++i){
           if(inHand[i] == ' '){
               temp = inHand.substr(start, i-start);
               pai.push_back(temp);
               start = i+1;
           }
        }
        pai.push_back(inHand.substr(start, inHand.size() - start + 1));
        
//         unordered_map<char, int> shuzi;
//         for(int i = 0; i < pai.size(); ++i){
//             if(pai[i].size() == 2){
//                 shuzi[pai[i][1]]++;
//             }else{
                
//             }
            
//         }
        unordered_map<char, int> huase;
        unordered_map<char, int> shuzi;
        for(int i = 0; i < pai.size(); ++i){
            if(pai[i].size() == 2){
                huase[pai[i][0]]++;
                shuzi[pai[i][1]]++;
            }else{
                huase[pai[i][0]]++;
                shuzi['B']++;//用B代替10
            }
        }
//         for(auto item: shuzi){
//             cout<<item.first<<" "<<item.second;
//         }
//         cout<<shuzi['B'];
        int tonghuageshu = 0;
        for(auto item: huase){
            tonghuageshu = max(tonghuageshu, item.second);
        }
//         cout<<tonghuageshu;
        if(tonghuageshu == 5){//同花个数等于5
            if(shuzi['A'] >= 1 && shuzi['K'] >= 1 && shuzi['Q'] >= 1 && shuzi['J'] >= 1 && shuzi['B'] >= 1){
//                 cout<<shuzi['A']<<shuzi['K']<<shuzi['Q']<<shuzi['J']<<shuzi['B'] ;
                return vec[0];
            }
            return vec[4];//同花
        }
        
        int tongshuzi = 0;
        for(auto item: shuzi){
            tongshuzi = max(tongshuzi, item.second);
        }
        if(tongshuzi == 4){
            return vec[2];
        }
        
        if(tongshuzi == 3){
            for(auto item : shuzi){
                if(item.second == 2){
                    return vec[3];
                }
            }
            if(tonghuageshu == 5){
                return vec[4];
            }
            return vec[6];
        }
        
        if(tongshuzi == 2){
            int count = 0;
            for(auto item: shuzi){
                if(item.second == 2){
                    count++;
                }
            }
            if(count == 2){
                return vec[7];
            }else{
                return vec[8];
            }
        }
        
        return vec[8];
    }
};