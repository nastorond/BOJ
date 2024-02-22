-- 코드를 입력하세요
SELECT pt.PT_NAME, pt.PT_NO, pt.GEND_CD, pt.AGE, ifnull(pt.TLNO, 'NONE') as TLNO from PATIENT pt
where pt.AGE <= 12 and pt.GEND_CD = 'W' 
order by pt.AGE desc, pt.PT_NAME;
