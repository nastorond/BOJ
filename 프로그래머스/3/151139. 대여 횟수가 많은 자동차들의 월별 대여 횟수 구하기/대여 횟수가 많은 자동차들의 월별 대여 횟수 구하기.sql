-- 코드를 입력하세요
select DATE_FORMAT(START_DATE, '%m') as MONTH, CAR_ID, count(CAR_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where START_DATE >= '2022-08-01' and START_DATE <= '2022-10-31'
and CAR_ID IN (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE >= '2022-08-01' and START_DATE <= '2022-10-31'
    group by CAR_ID
    having count(*) >= 5
)
group by DATE_FORMAT(START_DATE, '%Y-%m'), CAR_ID
having count(*) > 0
order by MONTH asc, CAR_ID desc
;
