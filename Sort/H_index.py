from collections import Counter
def solution(citations):
    answer = 0
    citations.sort()
    
    set_citations = list(set(citations))
    max_values = max(citations)
    
    for h in range(max_values):
        upper_counter = Counter([x for x in citations if x >= h])
        down_counter = Counter([x for x in citations if x <= h])
        upper_values, down_values = sum(upper_counter.values()), sum(down_counter.values())
        
        if (upper_values >= h) & (down_values <= h):
            answer = h
    
    return answer