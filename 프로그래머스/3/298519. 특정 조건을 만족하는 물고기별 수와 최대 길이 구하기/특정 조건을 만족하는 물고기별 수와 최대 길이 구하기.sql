-- 코드를 작성해주세요
select count(a.FISH_TYPE) as FISH_COUNT, MAX(a.LENGTH) as MAX_LENGTH, a.FISH_TYPE
from FISH_INFO a
join (
    select avg(LENGTH) as LEN, FISH_TYPE
    from FISH_INFO
    where LENGTH IS NOT NULL
    group by FISH_TYPE
) sub on a.FISH_TYPE = sub.FISH_TYPE
where sub.LEN >= 33
group by a.FISH_TYPE
order by a.FISH_TYPE asc
;