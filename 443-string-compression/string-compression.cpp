class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, i = 0, n = chars.size();

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[j] == chars[i]) ++j;

            chars[write++] = chars[i];

            int count = j - i;
            if (count > 1) {
                int start = write;

                while (count > 0) {
                    chars[write++] = char('0' + count % 10);
                    count /= 10;
                }

                // Reverse the digits
                int right = write - 1;
                while (start < right) {
                    char temp = chars[start];
                    chars[start++] = chars[right];
                    chars[right--] = temp;
                }
            }

            i = j;
        }

        return write;
    }
};