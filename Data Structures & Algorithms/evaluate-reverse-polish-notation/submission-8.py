class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for tok in tokens:
            if tok == "+":
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(str(first + second))
            elif tok == "-":
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(str(first - second))
            elif tok == "*":
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(str(first * second))
            elif tok == "/":
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(str(int(first / second)))
            else:
                stack.append(tok)

        return int(stack[-1])