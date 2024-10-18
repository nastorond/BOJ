select sub.SCORE as SCORE, a.EMP_NO, a.EMP_NAME, a.POSITION, a.EMAIL
from HR_EMPLOYEES a
join (select EMP_NO, sum(SCORE) as SCORE
    from HR_GRADE
    group by EMP_NO
) sub
on a.EMP_NO = sub.EMP_NO
where sub.SCORE = (
        select MAX(SCORE) 
        from(select sum(SCORE) as SCORE
                from HR_GRADE
                group by EMP_NO
            ) tmp
    )
order by SCORE desc
;