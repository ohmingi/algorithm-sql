-- 코드를 입력하세요
SELECT b.USER_ID, b.NICKNAME, sum(a.PRICE) as TOTAL_SALES
from USED_GOODS_BOARD a
join USED_GOODS_USER b on a.WRITER_ID = b.USER_ID
where a.STATUS = 'DONE'
group by b.USER_ID
having sum(a.PRICE) >= 700000
order by TOTAL_SALES;