from tkinter.messagebox import NO
from typing import List

from pymysql import NULL

class ListNode:
    def __init__(self, val = 0, next = None) -> None:
        self.val = val
        self.next = next
#None表示没有，它是NoneType类的对象，你可以把它看成是一个具体的值。正因它是一个具体的值，所以它可以用来初始化变量，可以作为很多函数在某些异常输入下的返回值，

class Solution:
    def reverseBetween(self, head : ListNode, left : ListNode, right : ListNode)->ListNode:
        def reverse(self, head : ListNode):
            pre = None
            cur = head
            while cur != None:
                temp = cur.next
                cur.next = pre
                pre = cur
                cur = temp
        
        dummyNode = ListNode(-1)
        dummyNode.next = head
        pre = dummyNode

        for _ in range(left - 1):
            pre = pre.next
        
        right_Node = pre
        for _ in range(right - left + 1):
            right_Node = right_Node.next
        
        left_node = pre.next
        curr = right_Node.next

        pre.next = None
        right_Node.next = None

        reverse(left_node)

        pre.next = right_Node
        left_node.next = curr

        return dummyNode.next