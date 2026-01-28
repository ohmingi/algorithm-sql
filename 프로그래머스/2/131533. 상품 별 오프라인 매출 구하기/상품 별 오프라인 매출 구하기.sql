-- 코드를 입력하세요
SELECT a.PRODUCT_CODE, sum(b.SALES_AMOUNT * a.PRICE) as SALES
from PRODUCT a
join OFFLINE_SALE b on a.PRODUCT_ID = b.PRODUCT_ID
group by a.PRODUCT_CODE
order by SALES desc, a.PRODUCT_CODE;
