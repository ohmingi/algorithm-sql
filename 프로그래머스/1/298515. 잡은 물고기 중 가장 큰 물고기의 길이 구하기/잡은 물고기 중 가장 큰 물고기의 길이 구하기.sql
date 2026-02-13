-- 코드를 작성해주세요
select concat(max(LENGTH),"cm") as MAX_LENGTH
from FISH_INFO
order by MAX_LENGTH desc
limit 1;