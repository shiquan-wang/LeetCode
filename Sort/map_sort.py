class Solution:
    def bubble_sort(self, dic: dict) -> dict:
        list_dic = list(dic.items())
        for i in range(len(list_dic)):
            for j in range(1, len(list_dic) - i):
                if list_dic[j][0] < list_dic[j-1][0]:
                    list_dic[j], list_dic[j-1] = list_dic[j-1], list_dic[j]
        return dict(list_dic)


dic = {3 : 1, 2 : 4, 1: 3}
s1 = Solution()
print(s1.bubble_sort(dic))
