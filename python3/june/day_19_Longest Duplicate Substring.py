class Solution:
    
    def check_old(self, s, k):
        mp = {}
        p = 31
        h = 1
        curr_hash = 0
        for i in range(k):
            curr_hash = (curr_hash * p + (ord(s[i]) - ord('a')))
            h = (h * p)

        mp[curr_hash] = 0

        for i in range(k, len(s)):
            curr_hash = curr_hash * p + (ord(s[i]) - ord('a'))
            curr_hash = (curr_hash - h * (ord(s[i - k]) - ord('a')))
            if(curr_hash in mp):
                idx = mp[curr_hash]
                # if(s[idx:idx+k] == s[i-k+1:i+1]):
                return True, s[idx:idx+k]

            mp[curr_hash] = i-k+1
        
        return False, ""
    
    def check(self, text, M):
        if M == 0: return True, ""
        h,t,d = 1,0,256
        q = (1<<31) - 1

        dic = defaultdict(list)
        for i in range(M-1):  h = (h * d) % q 

        for i in range(M): 
            t = (d * t + ord(text[i]))% q

        dic[t].append(i-M+1)

        for i in range(len(text) - M):
            t = (d*(t-ord(text[i])*h) + ord(text[i + M]))% q
            dic[t].append(i+1)

        for key in dic:
            for i,j in combinations(dic[key], 2):
                if text[i:i+M] == text[j:j+M]:
                    return (True, text[i:i+M])

        return (False, "")
    
    def longestDupSubstring(self, S: str) -> str:
        left=0
        n = len(S)
        right = n - 1
        res = "";
        while(left <= right):
            mid = left + (right-left)//2
            
            status, new_str = self.check(S, mid)
            if(status):
                if(len(new_str) > len(res)):
                    res = new_str
                left = mid + 1
            else:
                right = mid - 1

        return res
