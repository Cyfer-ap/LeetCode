/* Write your T-SQL query statement below */

SELECT A.firstName, A.lastName, B.city, B.state
FROM PERSON AS A
LEFT OUTER JOIN
ADDRESS AS B
ON 
A.PERSONID = B.PERSONID