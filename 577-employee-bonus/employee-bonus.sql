# Write your MySQL query statement below
with ans as(select e.name , b.bonus from Employee e left join Bonus b on e.empId=b.empId )
select name , bonus from ans where bonus<1000 or bonus is null;