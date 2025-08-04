class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)  # Dummy node simplifies edge case handling
        p1 = dummy
        p2 = dummy

        # Move p2 ahead by n+1 steps to keep the gap
        for _ in range(n + 1):
            p2 = p2.next

        # Move both pointers until p2 reaches the end
        while p2:
            p1 = p1.next
            p2 = p2.next

        # Remove the nth node from the end
        p1.next = p1.next.next

        return dummy.next  # Return the real head
