-- 코드를 입력하세요
SELECT year(b.SALES_DATE) as YEAR, month(b.SALES_DATE) as MONTH, a.GENDER, 
    count(distinct a.USER_ID) as USERS
from USER_INFO a
join ONLINE_SALE b on a.USER_ID = b.USER_ID
where a.GENDER IS NOT NULL
group by year(b.SALES_DATE), month(b.SALES_DATE), a.GENDER
order by year(b.SALES_DATE), month(b.SALES_DATE), a.GENDER
;
