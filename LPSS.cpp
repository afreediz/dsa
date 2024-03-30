#include<iostream>
using namespace std;
// PROGRAM FOR LONGEST PALINDROME SUB STRING
class Solution {
    private:
        bool is_palindrome(string str){
            int p;
            bool is_palindrome = true;
            for(p=0;str.length()/2>p;p++){
                if(str[p] != str[str.length() - 1 - p]){
                    is_palindrome = false;
                    break;
                }
            }
            return is_palindrome;
        }
    public:
        string longestPalindrome(string s) {
            if(1>=s.length()){
                return s;
            }
            int i, j, palindrome = 1;
            string temp = "", final_string = "";
            for(i=0;s.length()>i;i++){
                temp = "";
                for(j=i;s.length()>j;j++){
                    temp = temp + s[j];
                    if(is_palindrome(temp) == 1){
                        if(temp.length()>final_string.length()){
                            final_string = temp;
                        }
                    }
                }
            }
            return final_string;
        }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("tfekavrnnptlawqponffseumswvdtjhrndkkjppgiajjhklqpskuubeyofqwubiiduoylurzlorvnfcibxcjjzvlzfvsvwknjkzwthxxrowidmyudbtquktmyunoltklkdvzplxnpkoiikfijgulbxfxhaxnldvwmzpgaiumnvpdirlrutsqenwtihptnhghobrmmzcsrhqgdgzrvvitzgsolsxjxfeencvpnltxeetmtzlwnhlvgtbhkicivylfjhhfqteyxewmnewhmsnfdyneqoywgsgptwdlzbraksgajciebdchindegdfmayvfkwwkkfyxqjcv");
}