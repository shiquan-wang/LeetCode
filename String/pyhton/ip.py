class Solution:
    def is_ip(self, ip : str) -> bool:
        ls = ip.split('.')
        res = True
        for i in range(len(ls)):
            if int(ls[i]) > 255 or int(ls[i]) < 0:
                res = False
                break
        return res

ip = "244.222.198.62"
print(ip)
s = Solution()
print(f"result : {s.is_ip(ip)}")