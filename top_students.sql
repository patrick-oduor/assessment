/*
This query implements a high-performance extraction of top-tier student data in a database.

To ensure 'System Determinism'; meaning the query returns the exact same result set every time it is calle, a multi-level sorting strategy is employed.

1. Primary Ranking: Scores are sorted in descending order to prioritize academic excellence.

2. Collision Resolution: In scenarios where scores are identical (Ties), the system defaults to a stable ascending sort by Unique ID. This prevents "flickering" results in the UI and ensures fair, consistent ranking protocols.
*/

SELECT ID, NAME
FROM STUDENT
ORDER BY SCORE DESC, ID ASC
LIMIT 3; /* Optimization with a LIMIT clause to minimize database cursor overhead and reduce network payload. */