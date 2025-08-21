def solution(array, commands):
    answer = []
    for cmd in commands:
        # print(arr)
        start_idx, end_idx, num = cmd
        # print(array[start_idx-1:end_idx])
        answer.append(sorted(array[start_idx-1:end_idx])[num-1])
    return answer