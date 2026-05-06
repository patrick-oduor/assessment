# Annex Technologies Technical Assessment

This repository contains my solutions for the Annex Technologies technical assessment. Each solution is optimized for performance, scalability, and technical accuracy.

## Solutions Overview

### 1. SQL: Top Students Analysis (`top_students.sql`)
- **Objective:** Identify high-performing students based on marks and total offerings.
- **Key Feature:** Implemented deterministic sorting logic to handle edge cases where students have identical marks.

### 2. C: p-th Factor Finder (`pth_factor.c`)
- **Objective:** Find the p-th factor of numbers up to $10^{15}$.
- **Optimization:** Utilized an **O(sqrt(N))** algorithm to bypass the timeout constraints of a linear scan. By caching lower-half factors and deriving their partners, the solution maintains sub-second execution on quadrillion-scale inputs.

### 3. C++: Top Articles API Processor (`top_articles.cpp`)
- **Objective:** Fetch, filter, and rank paginated article data from the HackerRank API.
- **Logic:** Implemented a custom multi-criteria comparator to prioritize engagement (comments) and resolve ties using alphabetically decreasing (Z-A) order.
