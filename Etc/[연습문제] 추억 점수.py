#https://school.programmers.co.kr/learn/courses/30/lessons/176963

def solution(name, yearning, photo):
    name_dic = {k:v for k,v in zip(name, yearning)}
    
    answer = []
    
    for pt in photo:
        temp = []
        for p in pt:
            if name_dic.get(p):
                temp.append(name_dic.get(p))
        answer.append(sum(temp))
    
    return answer