class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Flat arrays for maximum speed
        parent = list(range(len(edges) + 1))
        size = [1] * (len(edges) + 1)

        for u, v in edges:
            # Fully inlined iterative 'find' with path compression for node u
            root_u = u
            while root_u != parent[root_u]:
                root_u = parent[root_u]
            
            curr = u
            while curr != root_u:
                parent[curr], curr = root_u, parent[curr]

            # Fully inlined iterative 'find' with path compression for node v
            root_v = v
            while root_v != parent[root_v]:
                root_v = parent[root_v]
            
            curr = v
            while curr != root_v:
                parent[curr], curr = root_v, parent[curr]

            # Cycle found
            if root_u == root_v:
                return [u, v]

            # Inlined Union by Size
            if size[root_u] < size[root_v]:
                root_u, root_v = root_v, root_u
                
            parent[root_v] = root_u
            size[root_u] += size[root_v]

        return []