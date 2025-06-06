-- 코드를 작성해주세요
SELECT A.EMP_NO, B.EMP_NAME, 
    CASE
        WHEN AVG_SCORE >= 96
        THEN 'S'
        WHEN AVG_SCORE >= 90
        THEN 'A'
        WHEN AVG_SCORE >= 80
        THEN 'B'
        ELSE 'C'
    END AS GRADE,
    CASE
        WHEN AVG_SCORE >= 96
        THEN B.SAL * 0.2
        WHEN AVG_SCORE >= 90
        THEN B.SAL * 0.15
        WHEN AVG_SCORE >= 80
        THEN B.SAL * 0.1
        ELSE B.SAL * 0
    END AS BONUS
FROM 
(SELECT EMP_NO, YEAR, TRUNCATE(AVG(SCORE), 0) AS AVG_SCORE
FROM HR_GRADE
GROUP BY EMP_NO, YEAR) AS A JOIN HR_EMPLOYEES AS B ON A.EMP_NO = B.EMP_NO
ORDER BY A.EMP_NO ASC