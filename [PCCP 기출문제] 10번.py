# https://school.programmers.co.kr/learn/courses/30/lessons/250121

def solution(data, ext, val_ext, sort_by):
    # code, date, maximum, remain
    code = 0
    date = 1
    maximum = 2
    remain = 3
    
    sorted_dic = {"code":0,
                 "date": 1,
                 "maximum": 2,
                 "remain": 3}
    
    
    
    c = sorted(data, key = lambda x : x[sorted_dic[ext]])
    
    lst = []
    for value in c:
        if value[sorted_dic[ext]] < val_ext:
            lst.append(value)
            
    answer = sorted(lst, key = lambda x : x[sorted_dic[sort_by]])
    
    
    return answer