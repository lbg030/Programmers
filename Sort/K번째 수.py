def solution(numbers):
    strs = [str(n) for n in numbers]
    strs.sort(key=lambda s: s * 4, reverse=True)
    
    answer = ''.join(strs)
    
    if answer[0] == '0':
        answer = '0'
    return answer
