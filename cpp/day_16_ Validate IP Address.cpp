class Solution {
public:
    bool ip_v4(string ip){
        int i, j, num, dots = 0;
        char prev, curr;
        // cout << ip << " :";
        prev = '.';
        for(i = 0; i < ip.size(); i++){
            curr = ip[i];
            if(prev == '.'){
                if(curr == '0' && i+1 < ip.size() && ip[i+1] >= '0' && ip[i+1] <= '9'){
                    return false;
                }
                num = 0;
            }

            if(curr == '.'){
                if(i+1 < ip.size() && ip[i+1] == '.'){
                    return false;
                }
                dots++;
                // cout << num << " ";
                if(num > 255 || num < 0){
                    return false;
                }
            }else{
                if(curr >= '0' && curr <= '9'){
                    num = num * 10 + curr - '0';
                }else{
                    return false;
                }
                
            }
            if(num > 255 || num < 0){
                return false;
            }
            
            prev = curr;
        }
        // cout <<endl;
        if(num > 255 || num < 0){
            return false;
        }
        return dots == 3 && ip[ip.size()-1] != '.' ? true : false;
    }
    
    bool ip_v6(string ip){
        int i, j, num, cols = 0;
        char prev, curr;
        // cout << ip << " :";
        prev = ':';
        for(i = 0; i < ip.size(); i++){
            curr = ip[i];
            if(prev == ':'){
                // if(curr == '0' && i < ip.size() && ip[i+1] >= '0' && ip[i+1] <= '9'){
                //     return false;
                // }
                num = 0;
            }

            if(curr == ':'){
                if(i+1 < ip.size() && ip[i+1] == ':'){
                    return false;
                }
                cols++;
                // cout << num << " ";
                if(num > 4 || num < 0){
                    return false;
                }
            }else{
                // num = num * 10 + curr - '0';
                if(curr >= 'A' && curr <= 'F' || curr >= 'a' && curr <= 'f' || curr >= '0' && curr <= '9'){
                    num++;
                }else{
                    return false;
                }
                
            }
            if(num > 4 || num < 0){
                return false;
            }
            prev = curr;
        }
        // cout <<endl;
        if(num > 4 || num < 0){
            return false;
        }
        return cols == 7 && ip[ip.size()-1] != ':'  ? true : false;
    }
    
    string validIPAddress(string IP) {
        // cout << endl;
        long long d = IP.find('.');
        long long c = IP.find(':');
        // cout << d << endl;
        if(d > -1 && c == -1 && ip_v4(IP)){
            return "IPv4";
        }else if(d == -1 && c > -1 && ip_v6(IP)){
            return "IPv6";
        }
        return "Neither";
    }
};
