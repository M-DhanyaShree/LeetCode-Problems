# Write your MySQL query statement below
select a.product_id, ifnull(b.new_price,10) as price from 
(select distinct product_id from Products) a
left join Products b on a.product_id=b.product_id 
and b.change_date = (
    SELECT MAX(change_date)
    FROM Products
    WHERE product_id = a.product_id
    AND change_date <= '2019-08-16'
);