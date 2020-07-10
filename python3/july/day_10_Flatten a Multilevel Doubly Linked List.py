"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        ptr = head
        while(ptr):
            if(ptr.child):
                next = ptr.next
                ptr.next = ptr.child
                ptr.child = None
                ptr.next.prev = ptr
                ptr1 = ptr.next
                while(ptr1.next):
                    ptr1 = ptr1.next

                ptr1.next = next
                if(next):
                    next.prev = ptr1

            ptr = ptr.next

        return head
