def solution(friends, gifts):
    receive_gift_lists = [0 for _ in range(len(friends))]
    friends = {name: idx for idx,name in enumerate(friends)}
    
    gift_table = [[0 for _ in range(len(friends))] for _ in range(len(friends))]
    gift_score = [0 for _ in range(len(friends))]
    
    for elem in gifts:
        give, get = elem.split()
        give_idx, get_idx = friends[give], friends[get]
        gift_table[give_idx][get_idx] += 1
        gift_score[give_idx] += 1
        gift_score[get_idx] -= 1

    # 2명씩 서로 비교
    for i in range(len(friends)):
        for j in range(i+1, len(friends)):
            gift_value = gift_table[i][j]
            receive_value = gift_table[j][i]
            
            if gift_value < receive_value:
                receive_gift_lists[j] += 1
            elif gift_value > receive_value:
                receive_gift_lists[i] += 1
            # gift_score로 비교
            else:
                gift_value_score, receive_value_score = gift_score[i], gift_score[j]
                
                if gift_value_score > receive_value_score:
                    receive_gift_lists[i] += 1
                elif gift_value_score < receive_value_score:
                    receive_gift_lists[j] += 1
    return max(receive_gift_lists)