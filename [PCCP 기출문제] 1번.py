# https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=python3

def solution(bandage, health, attacks):
    # bandage:List = [시전시간, 1초당 회복량, 추가회복량]
    # health:int = 최대체력
    # attacks: List[List] = [공격시간, 피해량]
    # 남은 체력 if 남은체력 > 0 else -1
    continued_time = 0
    prev_time = 0
    current_health = health
    
    for attack in attacks:
        time, damage = attack
        continued_time = time - prev_time
        
        # 회복
        if continued_time:
            for i in range(1, continued_time):
                if i % bandage[0] == 0:
                    current_health += bandage[2]
                current_health += bandage[1]
                
                if current_health >= health:
                    current_health = health
                    break
        
        # 공격
        current_health -= damage
        prev_time = time
        
        if current_health <= 0:
            return -1
        
        # print(f"current_health = {current_health}")
        # print(f"attack = {attack}")
        # print()
    return current_health