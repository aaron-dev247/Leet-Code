class WordNode:

    def __init__(self) -> None:
        self.children = {}
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = WordNode()

    def addWord(self, word: str) -> None:
        cur = self.root

        for c in word:
            if c not in cur.children:
                cur.children[c] = WordNode()
            cur = cur.children[c]
        
        cur.endOfWord = True
        
    def search(self, word: str) -> bool:
        
        def dfs(j, root):
            cur = root

            for i in range(j, len(word)):

                if word[i] == '.':
                    for child in cur.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                
                if word[i] not in cur.children:
                    return False
                cur = cur.children[word[i]]
            
            return cur.endOfWord
        
        return dfs(0, self.root)

obj = WordDictionary()
obj.addWord("bad")
param_2 = obj.search("bad")
print(param_2)