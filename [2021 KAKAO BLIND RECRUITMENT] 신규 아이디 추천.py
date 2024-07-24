def replace_consecutive_dots(text):
    while '..' in text:
        text = text.replace('..', '.')
    return text

def check(char_id):
    if(char_id.isalpha() or char_id.isdigit() or char_id == '-' or char_id == "_" or char_id == "."):
        return True
    else:
        return False

def solution(new_id):
    answer = ''
    
    lower_id = new_id.lower()
    for char_id in lower_id:
        if(check(char_id)):
            answer += char_id
    
    # 3단계
    answer = str(replace_consecutive_dots(answer))
    
    if len(answer):
        if(answer[0] == "."):
            answer = answer[1:]
    
    if len(answer) :      
        if(answer[-1] == "."):
            answer = answer[:-1]
    
    if not len(answer):
        answer += "a"
        
    if len(answer) >= 16:
        answer = answer[:15]
        if(answer[-1] == "."):
            answer = answer[:-1]
        
    while (len(answer) < 3):
        answer += answer[-1]
    
    
    return answer