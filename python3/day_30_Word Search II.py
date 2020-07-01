class TrieNode():

    def __init__(self):
        self.next = defaultdict(TrieNode)
        self.word = ""


class Trie():

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for w in word:
            node = node.next[w]

        node.word = word


class Solution:
    

    def dfs(self, node, i, j):
        c = self.board[i][j]
        node = node.next.get(c)
        if(c == '$' or not node):
            return

        if(node.word != ""):
            self.res.append(node.word)
            node.word = ""

        self.board[i][j] = '$'
        dr = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        for l in range(4):
            pos_i = i + dr[l][0]
            pos_j = j + dr[l][1]
            if(pos_i >= 0 and pos_i < len(self.board) and pos_j >= 0 and pos_j < len(self.board[0]) and self.board[pos_i][pos_j] != '$'):
                self.dfs(node, pos_i, pos_j)

        self.board[i][j] = c


    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        self.board = board
        self.res = []
        
        node = trie.root
        for i in range(len(self.board)):
            for j in range(len(self.board[0])):
                self.dfs(node, i, j)

        return self.res
