# Write your MySQL query statement below
select round(avg(a.order_date=a.customer_pref_delivery_date)*100,2) as immediate_percentage
from Delivery a join 
(select customer_id,min(order_date) as first_order from Delivery group by customer_id) b on
a.customer_id=b.customer_id and a.order_date=b.first_order;
