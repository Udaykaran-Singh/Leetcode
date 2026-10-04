class Solution {
public:
    int compress(vector<char>& chars) {
        int total = 0, cnt = 1, j = 0;

        for(int i = 0; i < chars.size(); i++){

            if(i == chars.size() - 1) goto jump;

            if(chars[i] == chars[i+1]){
                cnt++;
            }else{
                jump:
                if(cnt == 1){
                    chars[j++] = chars[i];
                    total += 1;
                }else{
                    chars[j++] = chars[i];
                    stack<char> st;

                    while(cnt){
                        int digit = cnt % 10;
                        cnt /= 10;
                        st.push(char('0' + digit));
                    }

                    total += st.size() + 1;

                    while(!st.empty()){
                        chars[j++] = st.top();
                        st.pop();
                    }
                    
                }

                cnt = 1;
            }

        }



        return total;

    }
};