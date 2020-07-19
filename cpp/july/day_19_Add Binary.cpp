class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = 0, j, c, s;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        c = 0;
        while(i < a.size() || i < b.size()){
            s = c;
            if(i < a.size()){
                s += a[i] == '1' ? 1 : 0;
            }
            if(i < b.size()){
                s += b[i] == '1' ? 1 : 0; 
            }
            c = s / 2;
            s = s % 2;
            res += s ? '1' : '0';
            i++;
        }
        if(c){
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
