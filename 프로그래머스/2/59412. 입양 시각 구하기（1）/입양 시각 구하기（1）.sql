-- 코드를 입력하세요
SELECT HOUR(DATETIME) as 'HOUR', COUNT(*) as 'COUNT'
from ANIMAL_OUTS
where HOUR(DATETIME) >= 9 and HOUR(DATETIME) < 20
group by HOUR(DATETIME)
order by HOUR;