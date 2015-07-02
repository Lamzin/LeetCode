class Solution:
    # @return an integer
    def numTrees(self, n):
        if n == 1 or n == 0:
            return 1
        curans = 0
        for i in range(0,n):
            curans+=self.numTrees(i) * self.numTrees(n - i - 1)
        return curans