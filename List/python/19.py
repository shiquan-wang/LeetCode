class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next=next

class Solution:
    def removeNthFromEnd(self, head:ListNode, n:int) ->ListNode:
        