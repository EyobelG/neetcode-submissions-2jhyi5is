class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = [i for i in range(n + 1)]
        rank = [1] * (n + 1)

        def find(n):
            if n != parent[n]:
                parent[n] = find(parent[n])
            return parent[n]
        
        def union(u, v):
            p1, p2 = find(u), find(v)
            if p1 == p2:
                return False
            if rank[p1] > rank[p2]:
                parent[p2] = p1
                rank[p1] += rank[p2]
            else:
                parent[p1] = p2
                rank[p1] += rank[p2]
            return True
        for u, v in edges:
            if not union(u, v):
                return [u, v]         