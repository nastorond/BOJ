-- 코드를 입력하세요
select ANIMAL_TYPE, count(ANIMAL_TYPE) as count
from ANIMAL_INS
where ANIMAL_TYPE in ('Cat', 'dog')
group by ANIMAL_TYPE
order by ANIMAL_TYPE
;