class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))
        size = [1] * (n + 1)

        def find(u):
            # Inline path compression path
            root = u
            while root != parent[root]:
                root = parent[root]
            
            # Classic path compression step
            curr = u
            while curr != root:
                nxt = parent[curr]
                parent[curr] = root
                curr = nxt
            return root

        for u, v in edges:
            urep = find(u)
            vrep = find(v)

            if urep == vrep:
                return [u, v]

            # Union by Size
            if size[urep] < size[vrep]:
                urep, vrep = vrep, urep
            parent[vrep] = urep
            size[urep] += size[vrep]

        return None