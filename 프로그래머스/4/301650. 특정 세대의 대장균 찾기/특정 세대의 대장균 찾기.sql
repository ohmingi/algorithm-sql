-- 코드를 작성해주세요
with recursive ge as(
    select ID, PARENT_ID, 1 as gen
    from ECOLI_DATA
    where PARENT_ID is null
    
    union all
    
    select a.ID, a.PARENT_ID, g.gen + 1
    from  ECOLI_DATA a join ge g
    on a.PARENT_ID = g.ID
)
select ID
from ge
where gen = 3
order by ID;