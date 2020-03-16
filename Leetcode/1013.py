class Solution:
    def canThreePartsEqualSum(self, A):
        sum = 0 
        for i in A:
            sum += i
        if sum % 3 == 0:
            res = sum / 3
            i, j = 0, len(A)-1
            tmp = 0
            while i < j:
                tmp += A[i]
                if tmp == res:
                    break
                i += 1
            tmp = 0
            while i < j:
                tmp += A[j]
                if tmp == res:
                    break
                j -= 1
            if i < j - 1:
                return True
            else:
                return False
        else:
            return False