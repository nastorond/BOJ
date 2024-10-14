from collections import deque
def solution(cacheSize, cities):
    answer = 0
    cache = deque()
    for city in cities:
        city = city.lower()
        
        if cacheSize == 0:
            answer += 5
            continue
            
        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
        else:
            answer += 5
            if len(cache)==cacheSize:
                cache.popleft()
            cache.append(city)
            
            
    return answer