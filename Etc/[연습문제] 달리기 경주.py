# https://school.programmers.co.kr/learn/courses/30/lessons/178871

def solution(players, callings):
    answer = []
    
    init_order = {k:idx for idx,k in enumerate(players)}
    
    for call in callings:
        overtaking_player = init_order[call]
        overtakend_player = players[overtaking_player-1]
        
        players[overtaking_player], players[overtaking_player-1] = players[overtaking_player-1], players[overtaking_player]
        
        init_order[overtakend_player] += 1
        init_order[call] -= 1

    return players