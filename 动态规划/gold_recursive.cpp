  int calculateMaxGoldValue2(int peopleTotal, int mineNum, int peopleNeed[], int goldValue[], int maxGoldVlueMatrix[][], int maxGoldMap[][]) {  
        int curMaxGoldValue = 0;  
        int step1, step2;  
        // 如果问题计算过,[对应动态规划中的“做备忘录”]  
        if(maxGoldVlueMatrix[peopleTotal][mineNum] != 0) {  
            curMaxGoldValue = maxGoldVlueMatrix[peopleTotal][mineNum];  
        // 如果仅有一个金矿时 [对应动态规划中的“边界”]  
        } else if(mineNum == 1) {  
            // 当给出的人数足够开采这座金矿  
            if(peopleTotal > peopleNeed[mineNum]) {  
                // 得到的最大值就是这座金矿的金子数  
                curMaxGoldValue = goldValue[mineNum];  
                maxGoldMap[peopleTotal][mineNum] = 2;  
            } else {  
                // 否则这唯一的一座金矿也不能开采  
                curMaxGoldValue = 0;  
                maxGoldMap[peopleTotal][mineNum] = 1;  
            }  
        // 如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]    
        } else if(peopleTotal >= peopleNeed[mineNum]) {  
            // 考虑当前金矿开采与不开采两种情况，取最大值  
            step1 = calculateMaxGoldValue2(peopleTotal, mineNum-1, peopleNeed, goldValue, maxGoldVlueMatrix, maxGoldMap);  
            step2 = calculateMaxGoldValue2(peopleTotal-peopleNeed[mineNum], mineNum-1, peopleNeed, goldValue, maxGoldVlueMatrix, maxGoldMap);  
            if(step1 >= (step2+goldValue[mineNum])) {  
                curMaxGoldValue = step1;  
                maxGoldMap[peopleTotal][mineNum] = 1;  
            } else {  
                curMaxGoldValue = step2 + goldValue[mineNum];  
                maxGoldMap[peopleTotal][mineNum] = 2;  
            }  
        } else {  
            // 否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]  
            // 仅考虑不开采的情况  
            step1 = calculateMaxGoldValue2(peopleTotal, mineNum-1, peopleNeed, goldValue, maxGoldVlueMatrix, maxGoldMap);  
            curMaxGoldValue = step1;  
            maxGoldMap[peopleTotal][mineNum] = 1;  
        }  
        // 做备忘录     
        maxGoldVlueMatrix[peopleTotal][mineNum] = curMaxGoldValue;  
        return curMaxGoldValue;  
    }  