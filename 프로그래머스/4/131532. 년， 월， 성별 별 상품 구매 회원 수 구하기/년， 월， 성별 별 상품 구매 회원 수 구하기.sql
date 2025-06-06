-- 코드를 입력하세요
SELECT A.YEAR, A.MONTH, A.GENDER, COUNT(*) AS USERS
FROM
(SELECT YEAR(SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH, GENDER
FROM ONLINE_SALE JOIN USER_INFO ON ONLINE_SALE.USER_ID = USER_INFO.USER_ID
WHERE GENDER IS NOT NULL
GROUP BY YEAR(SALES_DATE), MONTH(SALES_DATE), USER_INFO.USER_ID) AS A
GROUP BY A.YEAR, A.MONTH, A.GENDER
ORDER BY A.YEAR ASC, A.MONTH ASC, A.GENDER ASC

