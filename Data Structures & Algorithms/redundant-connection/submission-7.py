class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))
        rank   = [0] * (n + 1)    

        def find(u: int) -> int:
            if parent[u] != u:
                parent[u] = find(parent[u])   
            return parent[u]

        def union(u: int, v: int) -> bool:
            pu, pv = find(u), find(v)
            if pu == pv:
                return False         

            if rank[pu] < rank[pv]:
                pu, pv = pv, pu
            parent[pv] = pu
            if rank[pu] == rank[pv]:
                rank[pu] += 1

            return True

        for u, v in edges:
            if not union(u, v):
                return [u, v]

        return []
