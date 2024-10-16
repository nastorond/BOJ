-- 코드를 입력하세요
SELECT a.WRITER_ID, b.NICKNAME, sub.TOTAL_SALES
from USED_GOODS_BOARD a
join USED_GOODS_USER b on a.WRITER_ID = b.USER_ID
join (
    select WRITER_ID, sum(PRICE) as TOTAL_SALES
    from USED_GOODS_BOARD
    where STATUS = 'DONE'
    group by WRITER_ID
) sub on a.WRITER_ID = sub.WRITER_ID
where a.STATUS = 'DONE' and sub.TOTAL_SALES >= 700000
group by a.WRITER_ID, b.NICKNAME
order by sub.TOTAL_SALES
;
