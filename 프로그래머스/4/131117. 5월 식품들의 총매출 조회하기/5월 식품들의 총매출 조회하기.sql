-- 코드를 입력하세요
SELECT a.PRODUCT_ID, a.PRODUCT_NAME, sum(a.PRICE * b.AMOUNT) as TOTAL_SALES
from FOOD_PRODUCT a join FOOD_ORDER b  
on a.PRODUCT_ID = b.PRODUCT_ID
where b.PRODUCE_DATE like "2022-05%"
group by a.PRODUCT_NAME
order by TOTAL_SALES desc, a.PRODUCT_ID asc;