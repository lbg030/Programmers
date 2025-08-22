def solution(k, dungeons):
    n = len(dungeons)
    visited = [False] * n

    def dfs(energy):
        best_here = 0
        for i in range(n):
            need, cost = dungeons[i]
            if not visited[i] and energy >= need:
                visited[i] = True
                # 이 던전을 간 경우: 1 + 이후에 더 갈 수 있는 최댓값
                best_here = max(best_here, 1 + dfs(energy - cost))
                visited[i] = False
        return best_here  # 더 못 가면 0을 반환

    return dfs(k)
