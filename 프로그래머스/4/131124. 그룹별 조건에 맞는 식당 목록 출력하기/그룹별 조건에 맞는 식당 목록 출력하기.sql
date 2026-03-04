-- 코드를 입력하세요
select a.MEMBER_NAME, b.REVIEW_TEXT, date_format(b.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
from MEMBER_PROFILE a join REST_REVIEW b
on a.MEMBER_ID = b.MEMBER_ID
where a.MEMBER_ID = (
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID
    order by count(*) desc
    limit 1
)
order by b.REVIEW_DATE, b.REVIEW_TEXT;
