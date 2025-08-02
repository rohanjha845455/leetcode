from collections import Counter

class Solution:
    def minCost(self, basket1, basket2):
        combined = basket1 + basket2
        freq = Counter(combined)
        
        # Check if all fruit counts are even (feasibility)
        for count in freq.values():
            if count % 2 != 0:
                return -1
        
        # Count frequencies in each basket
        freq1 = Counter(basket1)
        freq2 = Counter(basket2)
        
        # Find fruits to be swapped from each basket
        to_swap_1 = []
        to_swap_2 = []
        
        for fruit in freq:
            diff = freq1[fruit] - freq2[fruit]
            if diff > 0:
                # fruit needs to move from basket1 to basket2
                to_swap_1.extend([fruit] * (diff // 2))
            elif diff < 0:
                # fruit needs to move from basket2 to basket1
                to_swap_2.extend([fruit] * ((-diff) // 2))
        
        to_swap_1.sort()
        to_swap_2.sort(reverse=True)
        
        min_fruit = min(freq.keys())
        total_cost = 0
        
        # Pair up mismatches to swap
        for f1, f2 in zip(to_swap_1, to_swap_2):
            cost_direct = min(f1, f2)
            cost_via_min = 2 * min_fruit
            total_cost += min(cost_direct, cost_via_min)
        
        return total_cost
