# https://school.programmers.co.kr/learn/courses/30/lessons/250125

def solution(board, h, w):
    answer = 0
    color = board[h][w]
    dw, dh = [0, 1, -1, 0], [1, 0, 0, -1]
    limit = len(board)
    
    for idx, (nw,nh) in enumerate(zip(dw, dh)):
        if 0 <= h+nh < limit and 0 <= w + nw < limit:
            if (board[h+nh][w+nw] == color):
                answer += 1
        
    return answer