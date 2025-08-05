class Solution:
    def getIntersectionNode(self, headA, headB):
        def getLength(head):
            length = 0
            while head:
                length += 1
                head = head.next
            return length

        lenA = getLength(headA)
        lenB = getLength(headB)

        while lenA > lenB:
            headA = headA.next
            lenA -= 1
        while lenB > lenA:
            headB = headB.next
            lenB -= 1

        while headA and headB:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next

        return None
