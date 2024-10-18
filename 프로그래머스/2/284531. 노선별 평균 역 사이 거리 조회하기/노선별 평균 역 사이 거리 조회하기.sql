-- 코드를 작성해주세요
select 
    ROUTE,
    concat(round(SUM(D_BETWEEN_DIST), 1), 'km') as TOTAL_DISTANCE, 
    concat(round(AVG(D_BETWEEN_DIST), 2), 'km') as AVERAGE_DISTANCE
from SUBWAY_DISTANCE
group by ROUTE
order by ROUTE desc
;