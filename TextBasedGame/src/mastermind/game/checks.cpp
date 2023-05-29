#include "checks.h"
#include <iostream>

int stringFind(string str, char key){
    int found=0;
    for(int i=0;i<str.size();i++){
        if(str.at(i) == key) found++;
    }

    return found;
}

vector<int> checks(string key, string user_try){
    int string_len = key.length();
    int full_correct[string_len];
    int correct = 0;
    int found;
    int times[string_len];
    int f_correct=0;

    for(int i=0;i<string_len;i++){
        full_correct[i] = 0;
        times[i] = 0;
        if(key.at(i) == user_try.at(i)) {
            full_correct[i] = 1; 
            times[i] = 1;
        }
    }


    for(int i=0;i<string_len;i++){
        found = stringFind(key,key.at(i));
        for(int j=0;j<string_len;j++){
            if(user_try.at(j) == key.at(i) && full_correct[j] != 1 && times[i]<found) {
                correct++;
                times[i]++;
            }
        }
        f_correct += full_correct[i];
    }
    
    return vector<int>{correct,f_correct};
}

