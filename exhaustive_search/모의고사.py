def answer_check(person_answer, ground_truth):
    if person_answer == ground_truth:
        return 1
    else:
        return 0

def return_person_idx(person_length, idx):
    return idx % person_length

def solution(answers):
    answer = []
    person_1 = [i for i in range(1,6)]
    person_2 = []
    for i in range(1,6):
        if i == 2:
            continue
        person_2.append(2)
        person_2.append(i)
        
    person_3 = [3, 3]
    for i in range(1,6):
        if i == 3:
            continue
        person_3.append(i)
        person_3.append(i)

    score = [0, 0, 0]
    length_person1, length_person2, length_person3 = len(person_1), len(person_2), len(person_3)
    for idx, ans in enumerate(answers):
        person1_idx = return_person_idx(length_person1, idx)
        person2_idx = return_person_idx(length_person2, idx)
        person3_idx = return_person_idx(length_person3, idx)
        
        score[0] += answer_check(person_1[person1_idx], ans)
        score[1] += answer_check(person_2[person2_idx], ans)
        score[2] += answer_check(person_3[person3_idx], ans)
    
    print(score)
    
    max_score = max(score)
    
    for i in range(len(score)):
        if score[i] == max_score:
            answer.append(i+1)
    
    return answer