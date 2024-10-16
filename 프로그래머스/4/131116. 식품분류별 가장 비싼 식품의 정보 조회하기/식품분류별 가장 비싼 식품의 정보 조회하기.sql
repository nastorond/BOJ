-- 코드를 입력하세요
SELECT a.CATEGORY, a.PRICE as MAX_PRICE, a.PRODUCT_NAME
from FOOD_PRODUCT a
join (
    select CATEGORY, MAX(PRICE) as MAX_PRICE
    from FOOD_PRODUCT
    where CATEGORY IN ('식용유', '과자', '국', '김치')
    group by CATEGORY
) sub
on a.CATEGORY = sub.CATEGORY and a.PRICE = sub.MAX_PRICE
where a.CATEGORY IN ('식용유', '과자', '국', '김치')
group by a.CATEGORY
order by a.PRICE desc
;