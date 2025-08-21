def solution(clothes):
    answer = 1
    clothes_dic = {}
    for data in clothes:
        clothes_dic[data[-1]] = clothes_dic.get(data[-1], 0) + 1
    
    for v in clothes_dic.values():
        answer *= (v+1)
        
    answer -= 1
    
    return answer