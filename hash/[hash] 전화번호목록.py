def solution(phone_book):
    answer = True
    phone_book.sort()
    dic = {i: [] for i in range(10)}

    for number in phone_book:
        dic[int(number[0])].append(number)

    for key, value in dic.items():
        if len(value) > 1:
            for i in range(len(value[1:])):
                if value[i+1].startswith(value[i]):
                    answer = False
                    return answer
                    
    return answer