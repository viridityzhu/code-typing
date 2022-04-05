class Solution:
    def generateParenthesis(self, n):  #输入n对括号
        res = []  #存放结果的列表，因为是可变的数据类型，后边随时可以直接往里放东西
        self.generate(n, n, "", res)  #开始调用配对函数
        return res  #返回结果的列表
    def generate(self, left, right, str, res):  #配对递归函数  配对剩余的括号
        if left == 0 and right == 0:  #基例：左右括号都不剩了，就往结果里放这个配对好了的括号串
            res.append(str)
            return
        if left > 0:  #如果左括号还有剩的，就放一个，再对剩余括号调用括号配对函数
            self.generate(left - 1, right, str + '(', res)
        if right > left:  #如果右括号有多的，就放一个，再对剩余括号调用配对函数
            self.generate(left, right - 1, str + ')', res)
s=Solution()
print(s.generateParenthesis(4))