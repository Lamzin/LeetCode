#python

class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
        sp1 = version1.split(".")
        sp2 = version2.split(".")
        if not len(sp1) == len(sp2):
            for i in range(max(len(sp1), len(sp2)) - min(len(sp1), len(sp2))):
                if len(sp1) < len(sp2):
                    sp1.append("0")
                else:   
                    sp2.append("0")
        
        for i in range(len(sp1)):
            int1 = int(sp1[i])
            int2 = int(sp2[i])
            if int1 > int2:
                return 1
            if int1 < int2:
                return -1
    
        return 0