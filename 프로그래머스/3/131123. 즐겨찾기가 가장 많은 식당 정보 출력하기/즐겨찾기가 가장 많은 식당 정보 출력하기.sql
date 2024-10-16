-- 코드를 입력하세요
SELECT a.FOOD_TYPE, a.REST_ID, a.REST_NAME, a.FAVORITES
from REST_INFO a
join (
    select MAX(FAVORITES) as FAVORITES, FOOD_TYPE
    from REST_INFO
    group by FOOD_TYPE
) sub
on a.FOOD_TYPE = sub.FOOD_TYPE and a.FAVORITES = sub.FAVORITES
order by a.FOOD_TYPE desc
;
