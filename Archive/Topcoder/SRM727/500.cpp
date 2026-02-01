#include <vector>
#include <string.h>

class TwoDiagonals{
public:
    int maxPoints(std::vector<int> x, std::vector<int> y){
        int max1, max2, x1, x2, y1, y2;
        max1 = max2 = 0;
        bool d1[1001], d2[1001], maxd1[1001], maxd2[1001], f1, f2;
        for(int i = 0; i < 999; i++){
            int acum_v1, acum_h1, acum_v2, acum_h2;
            acum_h1 = acum_v1 = 0;
            acum_h2 = acum_v2 = 0;
            for(int j = 0; j < x.size(); j++){
                if (x[j]- i == y[j]){
                    acum_h1++;
                }
                if (y[j] - i == x[j])
                    acum_v1++;
                if (i - x[j] == y[j])
                    acum_h2++;
                if (i - y[j] == x[j])
                    acum_v2++;
                if(acum_v1 > max1){
                    x1 = 0;
                    y1 = i;
                    f1 = false;
                }else if(acum_h1 > max1){
                    x1 = i;
                    y1 = 0;
                    f1 = true;
                }
                if (acum_v2 > max2){
                    x2 = 0;
                    y2 = i;
                    f2 = false;
                }else if (acum_h2 > max2){
                    x2 = i;
                    y2 = 0;
                    f2 = true;
                }
                max1 = std::max(acum_v1, std::max(acum_h1,max1));
                max2 = std::max(acum_v2, std::max(acum_h2, max2));
            }
        }
        int ans = 0;
        bool m[1001][1001];
        memset(m, 0, sizeof(m));
        for (int i = 0; i < x.size(); i++){
            if (f1 && x[i]-x1 == y[i] || (!f1 && y[i]-i == x[i]))
                m[x[i]][y[i]] = true;
        }
        for (int i = 0; i < x.size(); i++){
            if (f2 && x1-x[i] == y[i] || (!f2 && i-y[i] == x[i]))
                if (m[x[i]][y[i]]){
                    ans--;
                    break;
                }
        }
        ans += max1+max2;
        return ans;
    }
};

