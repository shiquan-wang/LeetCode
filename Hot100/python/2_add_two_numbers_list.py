class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        """ 
        
        """
        ans = 0
        carry = 0
        num = 0
        while l1.next != None and l2.next != None:
            sum_temp = l1.val + l2.val + carry
            if sum_temp > 9:
                carry = sum_temp / 10
                sum_temp = sum_temp % 10
            else:
                carry = 0
            ans = ans + sum_temp*pow(10, num)
            num = num + 1

        while l1.next != None:
            sum_temp = l1.val + carry
            if sum_temp > 9:
                carry = sum_temp / 10
                sum_temp = sum_temp % 10
            else:
                carry = 0
            ans = ans + sum_temp*pow(10, num)
            num = num + 1

        while l2.next != None:
            sum_temp = l2.val + carry
            if sum_temp > 9:
                carry = sum_temp / 10
                sum_temp = sum_temp % 10
            else:
                carry = 0
            ans = ans + sum_temp*pow(10, num)
            num = num + 1