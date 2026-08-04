class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        umap = {}
        umap[']'] = '['
        umap[')'] = '('
        umap['}'] = '{'

        for c in s:
            if c in umap:
                if stack and stack[-1] == umap[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return len(stack) == 0
