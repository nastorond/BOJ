-- 코드를 입력하세요
SELECT b.INGREDIENT_TYPE, sum(sub.SALES * a.TOTAL_ORDER) as TOTAL_ORDER
from FIRST_HALF a
join ICECREAM_INFO b on a.FLAVOR = b.FLAVOR
join (
    select FLAVOR, COUNT(*) as SALES
    from FIRST_HALF
    group by FLAVOR
) sub
on a.FLAVOR = sub.FLAVOR
group by b.INGREDIENT_TYPE
;