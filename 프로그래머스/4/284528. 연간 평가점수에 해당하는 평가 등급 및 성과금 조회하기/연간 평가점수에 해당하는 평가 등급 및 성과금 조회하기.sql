-- 코드를 작성해주세요
select a.EMP_NO, a.EMP_NAME, sub.GRADE,
case
    when sub.GRADE = 'S' then a.SAL*0.2
    when sub.GRADE = 'A' then a.SAL*0.15
    when sub.GRADE = 'B' then a.SAL*0.1
    else 0
end as BONUS
from HR_EMPLOYEES a
join (
    select EMP_NO,
    case 
        when tmp.SCORE >= 96 then 'S'
        when tmp.SCORE >= 90 then 'A'
        when tmp.SCORE >= 80 then 'B'
        else 'C'
    end as GRADE
    from (select SUM(SCORE)/2 as SCORE, EMP_NO
          from HR_GRADE
          group by EMP_NO) tmp
) sub
on a.EMP_NO = sub.EMP_NO
order by a.EMP_NO asc
;