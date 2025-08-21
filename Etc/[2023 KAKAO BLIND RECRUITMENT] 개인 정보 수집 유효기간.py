
def solution(today, terms, privacies):
    answer = []
    valid_due_date = {}
    valid_year, valid_month, valid_day = map(int, today.split('.'))

    for data in terms:
        term, due_month = data.split()
        valid_due_date[term] = int(due_month)
    
    for idx, privacy in enumerate(privacies):
        contract_date, term = privacy.split()
        year, month, day = map(int, contract_date.split('.'))
        month += valid_due_date[term]
        
        while(month > 12):
            month -= 12
            year += 1

        if(year < valid_year):
            answer.append(idx+1)
            continue
        
        elif(year == valid_year):
            if(month < valid_month):
                answer.append(idx+1)
                continue
            elif(month == valid_month):
                if(day <= valid_day):
                    answer.append(idx+1)
                    continue
            
    return answer