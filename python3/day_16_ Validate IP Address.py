class Solution:
    def validIPAddress(self, IP: str) -> str:
        def ip_v4(IP):
            dots = 0
            prev = '.'
            for i, curr in enumerate(IP):
                if prev == '.':
                    if curr == '0' and i+1 < len(IP) and IP[i+1] >= '0' and IP[i+1] <= '9':
                        return False
                    num = 0
                
                if curr == '.':
                    if i+1 < len(IP) and IP[i+1] == '.':
                        return False
                    dots += 1
                    
                    if num > 255 or num < 0:
                        return False
                else:
                    if curr >= '0' and curr <= '9':
                        num = num * 10 + int(curr)
                    else:
                        return False
                
                if num > 255 or num < 0:
                    return False
                prev = curr
                
            if num > 255 or num < 0:
                return False
            return True if dots == 3 and IP[-1] != '.' else False
        
        def ip_v6(IP):
            cols = 0
            prev = ':'
            for i, curr in enumerate(IP):
                if prev == ':':
                    num = 0
                
                if curr == ':':
                    if i+1 < len(IP) and IP[i+1] == ':':
                        return False
                    cols += 1
                    
                    if num > 4 or num < 0:
                        return False
                else:
                    if curr >= 'A' and curr <= 'F' or curr >= 'a' and curr <= 'f' or curr >= '0' and curr <= '9':
                        num += 1
                    else:
                        return False
                
                if num > 4 or num < 0:
                    return False
                prev = curr
                
            if num > 4 or num < 0:
                return False
            return True if cols == 7 and IP[-1] != ':' else False
            
        if '.' in IP and ':' in IP:
            return "Neither"
        elif '.' in IP and ip_v4(IP):
            return "IPv4"
        elif ':' in IP and ip_v6(IP):
            return "IPv6"
        return "Neither"
