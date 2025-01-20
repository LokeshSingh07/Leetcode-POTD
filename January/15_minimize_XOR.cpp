// 2429. Minimize XOR

class Solution {
public:
    bool isSetBit(int &x, int bitPos){
        return (x & (1<<bitPos));
    }
    bool setBit(int &x, int bit){
        return (x |= (1<<bit));
    }
    bool unSetBit(int &x, int bit){
        return (x &= (~(1<<bit)));
    }


    int minimizeXor(int num1, int num2) {
        int x = num1;

        int currSetBitCount = __builtin_popcount(num1);
        int requiredSetBitCount = __builtin_popcount(num2);

        int bit=0;
        if(currSetBitCount < requiredSetBitCount){
            while(currSetBitCount < requiredSetBitCount){
                if(!isSetBit(x, bit)){
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        }
        else if(currSetBitCount > requiredSetBitCount){
            while(currSetBitCount > requiredSetBitCount){
                if(isSetBit(x, bit)){
                    unSetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};