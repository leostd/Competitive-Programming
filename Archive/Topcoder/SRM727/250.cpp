#include <string>

class MakeTwoConsecutive{
public:
    std::string solve(std::string S){
        if (S.size() < 3)
            return "Impossible";
        for(int i = 0; i < S.size()-2; i++){
            if (S[i] == S[i+1] || S[i]==S[i+2] || S[i+1]==S[i+2])
                return "Possible";
        }
        return "Impossible";
    }
};
