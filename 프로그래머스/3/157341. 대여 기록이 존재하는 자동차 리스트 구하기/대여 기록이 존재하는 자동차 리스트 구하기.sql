-- 코드를 입력하세요
SELECT DISTINCT a.CAR_ID
from CAR_RENTAL_COMPANY_CAR a
join CAR_RENTAL_COMPANY_RENTAL_HISTORY b on a.CAR_ID = b.CAR_ID
where b.START_DATE like '2022-10%'
and a.CAR_TYPE = '세단'
order by a.CAR_ID desc;