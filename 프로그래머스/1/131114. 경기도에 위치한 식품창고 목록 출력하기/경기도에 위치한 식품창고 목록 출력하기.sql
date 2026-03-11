-- 코드를 입력하세요
SELECT
    WAREHOUSE_ID,                
    WAREHOUSE_NAME,              
    ADDRESS,                     
    NVL(FREEZER_YN, 'N') AS FREEZER_YN   -- 냉동시설 여부 NULL이면 N 출력
FROM FOOD_WAREHOUSE
WHERE ADDRESS LIKE '경기도%'    -- ADDRESS가 경기도로 시작하는 창고만 조회
ORDER BY WAREHOUSE_ID          -- 창고 ID 기준 오름차순 정렬