#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& prices) {


    if(prices.size() == 1) return 0;

    int profit =0,maxP = INT_MIN,l=0,r=1;
    // [7,1,5,3,6,4]
    //    |       |

    while(r<prices.size()){

      if(prices[l] < prices[r] ){
        profit =  prices[r] - prices[l];
        maxP = ( profit> maxP )? profit : maxP;
      }else{
        l = r;
      }

      r++;
    }

    return (maxP != INT_MIN )? maxP : 0;
  }


  /*
      int maxP = 0;
      int minBuy = prices[0];

      for (int& sell : prices) {
          maxP = max(maxP, sell - minBuy);
          minBuy = min(minBuy, sell);
      }
      return maxP;
  */
};