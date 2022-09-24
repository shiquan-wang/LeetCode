class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 解密
     * @param encryptedNumber int整型 待解密数字
     * @param decryption int整型 私钥参数D
     * @param number int整型 私钥参数N
     * @return int整型
     */
    int poww(int a, int b, int mod){
        int ans = 1, base = a;
        while(b != 0){
            if(b & 1 != 0){
                ans = ans * base;
                ans %= mod;
            }
            base *= base;
            base %= mod;
            b >>= 1;
        }
        return ans;
    }
    int Decrypt(int encryptedNumber, int decryption, int number) {
        // write code here
        return poww(encryptedNumber, decryption, number);
    }
};