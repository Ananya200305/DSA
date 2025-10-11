class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for u,v in prerequisites:
            adj[v].append(u)
            indegree[u] += 1

        q = deque()

        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        
        count = 0

        while q:
            node = q.popleft()

            count += 1

            for neigh in adj[node]:
                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    q.append(neigh)

        return True if count == numCourses else False