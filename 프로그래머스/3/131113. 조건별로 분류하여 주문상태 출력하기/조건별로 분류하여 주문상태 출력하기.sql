-- 코드를 입력하세요
SELECT ORDER_ID, PRODUCT_ID, 
    date_format(OUT_DATE, '%Y-%m-%d') as OUT_DATE,
    CASE
        WHEN OUT_DATE <= '2022-05-01' THEN '출고완료'
        WHEN OUT_DATE > '2022-05-01' THEN '출고대기'
        ELSE '출고미정'
    END AS '출고여부'
from FOOD_ORDER
order by ORDER_ID
