-- 코드를 입력하세요
SELECT r.REST_ID, r.REST_NAME, r.FOOD_TYPE, r.FAVORITES, r.ADDRESS, 
ROUND(avg(rv.REVIEW_SCORE), 2) as SCORE
from REST_INFO r
join REST_REVIEW rv on r.REST_ID = rv.REST_ID
where r.ADDRESS  like '서울%'
group by r.REST_ID, r.REST_NAME, r.FOOD_TYPE, r.FAVORITES, r.ADDRESS
order by SCORE desc, r.FAVORITES desc
;