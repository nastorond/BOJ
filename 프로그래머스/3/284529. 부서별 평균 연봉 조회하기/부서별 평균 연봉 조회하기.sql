-- 코드를 작성해주세요
select a.DEPT_ID, a.DEPT_NAME_EN, round(sub.SAL / sub.NUMBER, 0) as AVG_SAL
from HR_DEPARTMENT a
join (select COUNT(EMP_NO) as NUMBER, SUM(SAL) as SAL, DEPT_ID
      from HR_EMPLOYEES
      group by DEPT_ID
     ) sub on a.DEPT_ID = sub.DEPT_ID
order by AVG_SAL desc
;